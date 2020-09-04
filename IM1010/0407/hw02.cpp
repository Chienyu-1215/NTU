#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;
  
const int MAX_CAPACITY = 10; //max capacity of a team or a bag
  
// ===========================================================================
// Item, ItemNode, ItemBag
// ===========================================================================
class Item
{
    private:
        string name;
        int type;
    public:
        Item();
        Item(string nm);
        Item(string nm , int t);
        Item(const Item& i);
        Item& operator=(const Item& i);
        string getName();
        int getType();
        void setType();//if type = 0, the character cannot use it
};
  
Item::Item()
{
    this->name = nullptr;
    this->type = 0;
}
  
Item::Item(string nm)
{
    this->name = nm;
    this->type = 0;
}
  
Item::Item(string nm , int t)
{
    this->name = nm;
    this->type = t;
}

Item& Item::operator=(const Item& i) // do operator overloading to make item assignment
{
	if(this != &i){
		this->name = i.name;
		this->type = i.type;
	}
	return *this;
}
  
string Item::getName()
{
    return this->name;   
}
  
int Item::getType()
{
    return this->type;
}

void Item::setType()
{
    this->type = 0;
}
  
Item::Item(const Item& i) //copy constructor
{
    this->name = i.name;
    this->type = i.type;
}

class ItemNode
{
	private:
		Item item;
		ItemNode* next;
	public:
		ItemNode();
		ItemNode(const Item& i);
		ItemNode(const Item& i, ItemNode* nextPtr);
		void setItem(const Item& i);
		void setNext(ItemNode* nextPtr);
		Item getItem() const;
		ItemNode* getNext() const; 
};

ItemNode::ItemNode() : next(nullptr)
{
}

ItemNode::ItemNode(const Item& i) : item(i), next(nullptr)
{	
}

ItemNode::ItemNode(const Item& i , ItemNode* nextPtr) : item(i), next(nextPtr)
{
}

void ItemNode::setItem(const Item& i)
{
	item = i;
}

void ItemNode::setNext(ItemNode* nextPtr)
{
	next = nextPtr;
} 

Item ItemNode::getItem() const
{
	return this->item;
}

ItemNode* ItemNode::getNext() const
{
	return this->next;
}

  
class ItemBag
{
    private:
        int Capacity;
        int ItemCnt;
        ItemNode* head;
    public:
        ItemBag();
        void setBagSize(int n);
        void addItem(Item i) throw(overflow_error);
        bool hasItem(Item i);
        void bagArrange();
        string getItemList();
        string getItemSummary();
        void useItem(Item i) throw (logic_error);
        void removeItem(Item i) throw(logic_error);
        ~ItemBag();
};
  
ItemBag::ItemBag()
{
    this->Capacity = 0;
    this->ItemCnt = 0;
    this->head = nullptr; 
}
  
void ItemBag::setBagSize(int n)
{
    this->Capacity = n;
}

void ItemBag::bagArrange()
{
	ItemNode* curPtr = head;
	int cnt = 0;//use cnt to determine whether all items have been arranged
	while(cnt < this->ItemCnt){
		ItemNode* toCompare = curPtr;
		while(toCompare->getNext() != nullptr){
			if(toCompare->getItem().getName().compare(toCompare->getNext()->getItem().getName()) > 0){
				Item temp = toCompare->getItem();
				toCompare->setItem(toCompare->getNext()->getItem());
				toCompare->getNext()->setItem(temp);
			}
			toCompare = toCompare->getNext();
		}
		cnt++;
	}
}
  
void ItemBag::addItem(Item i) throw(overflow_error)
{
    if(this->ItemCnt < this->Capacity){
        ItemNode* newNode = new ItemNode(i);
        newNode->setNext(this->head);
        this->head = newNode;
        ItemCnt++;
    }
    else{
        throw overflow_error("no more capacity");//throw error if there/s no more capacity
    }
}
  
bool ItemBag::hasItem(Item i)
{
	ItemNode* curPtr = head;
    while(curPtr != nullptr){
    	if(curPtr->getItem().getName() == i.getName()){
    		return true;
		}
		curPtr = curPtr->getNext();
	}
    return false;
}
  
string ItemBag::getItemList()
{
    string toreturn = "";
    if(this->ItemCnt == 0){//if there are no items in bag return "empty"
        return "empty";
    }
    else{
    	this->bagArrange();//do bag arrangement first
        toreturn = head->getItem().getName();
        ItemNode* curPtr = head->getNext();
        while(curPtr != nullptr){
        	toreturn += ',';
        	toreturn += curPtr->getItem().getName();
        	curPtr = curPtr->getNext();
		}
        return toreturn;
    }
}
  
string ItemBag::getItemSummary()
{
    string toreturn = "";
    if(this->ItemCnt == 0){//if there are no items in bag return "empty"
        return "empty";
    }
    else{
    	this->bagArrange();//do bag arrangement first
        string target = head->getItem().getName();
		toreturn = target;
        if(this->ItemCnt == 1){
            toreturn+=",1";
            return toreturn;
        }
        int cnt = 1;
        ItemNode* curPtr = head->getNext();
        while(curPtr != nullptr){
        	if(curPtr->getItem().getName() == target){
        		cnt++;
			}
			else{
				toreturn += ',';
				toreturn += to_string(cnt);
				toreturn += ';';
				target = curPtr->getItem().getName();
				toreturn += target;
				cnt = 1;
			}
			curPtr = curPtr->getNext();
			if(curPtr == nullptr){//if it's already the last item in bag add current cnt to toreturn string
				toreturn += ',';
				toreturn += to_string(cnt);
			}
		}	
        return toreturn;
    }
}
  
void ItemBag::useItem(Item i) throw (logic_error) 
{
    bool used = 0;//determine whether we've found the item that can be used
    ItemNode* curPtr = head;
    while(curPtr != nullptr){
    	if(i.getName() == curPtr->getItem().getName() && curPtr->getItem().getType() != 0){
    		removeItem(i);//after using the item, remove it
    		used = 1;
    		break;
		}
		else if(i.getName() == curPtr->getItem().getName() && curPtr->getItem().getType() == 0){//if the bag has the item but the character cannot use throw "cannot use it"
			used = 1;
            throw logic_error("cannot use it");
            break;
		}
		curPtr = curPtr->getNext();
	}
    if(used == 0){//if cannot find the item, throw the message "does the character own it?"
        throw logic_error("does the character own it?");
    }
}
  
void ItemBag::removeItem(Item i) throw (logic_error)
{
    bool remove = 0;
    ItemNode* curPtr = head;
    while(curPtr != nullptr){
    	if(i.getName() == curPtr->getItem().getName()){
    		this->ItemCnt--;
    		remove = 1;
    		if(curPtr != head){
    			curPtr->setItem(head->getItem()); 
			}
    		ItemNode* todelete = this->head;
    		head = head->getNext();
    		delete todelete;
    		break;
		}
		curPtr = curPtr->getNext();
	}
    if(remove != 1){//if cannot find the item, throw the message "does the character own it?"
        throw logic_error("does the character own it?");
    }
}
  
ItemBag::~ItemBag(){
    ItemNode* curNode = head;
    while(curNode != nullptr){
    	ItemNode* todelete = curNode;
    	curNode = curNode->getNext();
    	delete todelete;
	}
}
  
  
// ===========================================================================
// Character, Warrior, Wizard
// ===========================================================================
class Character
{
    protected:
        static const int EXP_LV = 100;
        string name;
        int level;
        bool R;
        bool D;
        ItemBag bag; 
    public:
        Character(string n, int lv, int capacity, int r, int d);
        void addtoBag(Item i);
        bool hasItem(Item i);
        string getBagList();
        string getBagSummary();
        void useItem(Item i);
        void removeItem(Item i);
        string getName();
};
  
Character::Character(string n , int lv , int capacity , int r , int d)
 : name(n) , level(lv) , R(r) , D(d)
{ 
    bag.setBagSize(capacity);
}
  
string Character::getName()
{
  return this->name;
}
  
void Character::addtoBag(Item i){
    if(this->R == 1){ // if the character is a warrior set type-3 item to type-0
        if(i.getType() == 3){
            i.setType();
        }
    }
    else{ // if the character is a witch set type-2 item to type-0
        if(i.getType() == 2){
            i.setType();
        }
    }
    try{
        this->bag.addItem(i);
    }
    catch(overflow_error e){
        cout << e.what() << endl;
    }
}
  
bool Character::hasItem(Item i)
{
    return bag.hasItem(i);
}
  
string Character::getBagList()
{
    return bag.getItemList();
}
  
string Character::getBagSummary()
{
    return bag.getItemSummary();
}
  
void Character::useItem(Item i)
{
    try{
        bag.useItem(i);
    }
    catch(logic_error e){
        cout << e.what() << endl;
    }
}
  
void Character::removeItem(Item i)
{
    try{
        bag.removeItem(i);
    }
    catch(logic_error e){
        cout << e.what() << endl;
    }
}
  
  
class Warrior : public Character
{
    private:
    public:
        Warrior(string n , int lv , int capacity) : Character(n , lv , capacity , 1 , 0){}
};
  
  
class Wizard : public Character
{
    private:
    public:
        Wizard(string n , int lv , int capacity) : Character(n , level , capacity , 0 , 1) {}
};
  
// ===========================================================================
// Team
// ===========================================================================
  
class Team
{
    private:
        int memberCount;
        Character* member[10];
    public:
        Team();
        ~Team();
        void addWarrior(string name, int lv, int capacity);
        void addWizard(string name, int lv, int capacity);
        int getIndex(string name);
        void addItemtoCharacter(int n , Item i);
        bool characterhasItem(int n , Item i);
        string getCharacterBagList(int n);
        string getCharacterBagSummary(int n);
        void characteruseItem(int n , Item i);
        void characterremoveItem(int n , Item i);
};
  
Team::Team()
{
    this->memberCount = 0;
    for(int i = 0; i < MAX_CAPACITY; i++)
        member[i] = nullptr;
}
  
Team::~Team()
{
    for(int i = 0; i < this->memberCount; i++)
        delete this->member[i];
}
  
void Team::addWarrior(string name, int lv, int capacity) 
{
    if(memberCount < MAX_CAPACITY)
    {
        member[memberCount] = new Warrior(name, lv, capacity);
        memberCount++;
    }
}
  
void Team::addWizard(string name, int lv, int capacity)
{
    if(memberCount < MAX_CAPACITY)
    {
        member[memberCount] = new Wizard(name, lv, capacity);
        memberCount++;
    }
}
  
int Team::getIndex(string name)
{
    for(int i = 0 ; i < this->memberCount ; i++){
        if(this->member[i]->getName() == name){
            return i;
        }
    }
    return MAX_CAPACITY;
}
  
void Team::addItemtoCharacter(int n , Item i)
{
    this->member[n]->addtoBag(i);
}
  
bool Team::characterhasItem(int n , Item i)
{
    return this->member[n]->hasItem(i);   
} 
  
string Team::getCharacterBagList(int n)
{
    return this->member[n]->getBagList();
}
  
string Team::getCharacterBagSummary(int n)
{
    return this->member[n]->getBagSummary();
}
  
void Team::characteruseItem(int n , Item i)
{
    this->member[n]->useItem(i);
}
  
void Team::characterremoveItem(int n , Item i)
{
    this->member[n]->removeItem(i);
}
  
// ===========================================================================
// End of Character, Warrior, Wizard, and Team 
// ===========================================================================
  
int main()
{
    Team team;
    char C;
    while(cin >> C){
        switch(C){
            case 'R':{
                string nm;
                int lv , capacity;
                cin >> nm >> lv >> capacity;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    team.addWarrior(nm , lv , capacity);
                }
                else{
                    cout << "the character exists" << endl;
                }
                break;
            }
            case 'D':{
                string nm;
                int lv , capacity;
                cin >> nm >> lv >> capacity;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    team.addWizard(nm , lv , capacity);
                }
                else{
                    cout << "the character exists" << endl;
                }
                break;
            }
            case 'A':{
                string nm , itemnm;
                int type;
                cin >> nm >> itemnm >> type;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    cout << "no such a character" << endl;
                }
                else{
                    Item toAdd(itemnm , type);
                    team.addItemtoCharacter(n , toAdd);
                }
                break;
            }
            case 'H':{
                string nm , itemnm;
                cin >> nm >> itemnm;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    cout << "no such a character" << endl;
                }
                else{
                    Item toSearch(itemnm);
                    if(team.characterhasItem(n , toSearch)){
                        cout << "yes" << endl;
                    }
                    else{
                        cout << "no" << endl;
                    }
                }
                break;
            }
            case 'L':{
                string nm;
                cin >> nm;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    cout << "no such a character" << endl;
                }
                else{
                    string toprint = team.getCharacterBagList(n);
                    cout << toprint << endl;
                }
                break;
            }
            case 'S':{
                string nm;
                cin >> nm;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    cout << "no such a character" << endl;
                }
                else{
                    string toprint = team.getCharacterBagSummary(n);
                    cout << toprint << endl;
                }
                break;
            }
            case 'U':{  
                string nm , itemnm;
                cin >> nm >> itemnm;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    cout << "no such a character" << endl;
                }
                else{
                    Item touse(itemnm);
                    team.characteruseItem(n , touse);
                }   
                break;
            }
            case 'V':{
                string nm , itemnm;
                cin >> nm >> itemnm;
                int n = team.getIndex(nm);
                if(n == MAX_CAPACITY){
                    cout << "no such a character" << endl;
                }
                else{
                    Item toremove(itemnm);
                    team.characterremoveItem(n , toremove);
                }
                break;
            } 
        }
              
    }
    return 0;
}

