#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;
 
const int MAX_CAPACITY = 10;
 
// ===========================================================================
// Item, ItemBag
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
 
 
class ItemBag
{
    private:
        int Capacity;
        int ItemCnt;
        Item** items;
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
    this->items = new Item* [MAX_CAPACITY]; 
}
 
void ItemBag::setBagSize(int n)
{
    this->Capacity = n;
}
 
void ItemBag::bagArrange(){
    for(int i = 1 ; i < this->ItemCnt ; i++){
        for(int j = 0 ; j < i ; j++){
            if(items[i][0].getName().compare(items[j][0].getName()) < 0){
                Item* temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
 
void ItemBag::addItem(Item i) throw(overflow_error)
{
    if(ItemCnt < this->Capacity){
        this->items[ItemCnt] = new Item(i);
        ItemCnt++;
    }
    else{
        throw overflow_error("no more capacity");
    }
}
 
bool ItemBag::hasItem(Item i)
{
    for(int j = 0 ; j < this->ItemCnt ; j++){
        if(items[j][0].getName() == i.getName()){
            return 1;
        }
    }
    return 0;
}
 
string ItemBag::getItemList()
{
    string toreturn;
    if(this->ItemCnt == 0){
        return "empty";
    }
    else{
        this->bagArrange();
        toreturn = items[0][0].getName();
        for(int i = 1 ; i < this->ItemCnt ; i++){
            toreturn += ',';
            toreturn += items[i][0].getName();
        }
        return toreturn;
    }
}
 
string ItemBag::getItemSummary()
{
    string toreturn;
    if(this->ItemCnt == 0){
        return "empty";
    }
    else{
        this->bagArrange();
        toreturn = items[0][0].getName();
        string target = items[0][0].getName();
        if(this->ItemCnt == 1){
            toreturn+=",1";
        }
        int cnt = 1;
        for(int i = 1 ; i < this->ItemCnt ; i++){
            if(items[i][0].getName() == target){
                cnt++;
            }
            else{
                toreturn += ',';
                toreturn += to_string(cnt);
                toreturn += ';';
                toreturn += items[i][0].getName();
                target = items[i][0].getName();
                cnt = 1;
            }
            if(i == this->ItemCnt - 1){
                toreturn += ',';
                toreturn += to_string(cnt);
            }
        }
        return toreturn;
    }
}
 
void ItemBag::useItem(Item i) throw (logic_error) 
{
    bool used = 0;
    for(int j = 0 ; j < this->ItemCnt ; j++){
        if(i.getName() == this->items[j][0].getName() && this->items[j][0].getType() != 0){
            removeItem(i);
            used = 1;
            break;
        }
        else if(i.getName() == this->items[j][0].getName() && this->items[j][0].getType() == 0){
            used = 1;
            throw logic_error("cannot use it");
            break;
        }
    }
    if(used == 0){
        throw logic_error("does the character own it?");
    }
}
 
void ItemBag::removeItem(Item i) throw (logic_error)
{
    bool remove = 0;
    for(int j = 0 ; j < this->ItemCnt ; j++){
        if(i.getName() == items[j][0].getName()){
            items[j] = items[this->ItemCnt - 1];
            this->ItemCnt--;
            remove = 1;
            break;
        }
    }
    if(remove != 1){
        throw logic_error("does the character own it?");
    }
}
 
ItemBag::~ItemBag(){
    delete[] items;
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
//      int exp;
//      int power;
//      int knowledge;
//      int luck;
        ItemBag bag; 
//      void levelUp(int pInc, int kInc, int lInc);
    public:
        Character(string n, int lv, int capacity, int r, int d);
        void addtoBag(Item i);
        bool hasItem(Item i);
        string getBagList();
        string getBagSummary();
        void useItem(Item i);
        void removeItem(Item i);
//      Character(string n, int lv, int po, int kn, int lu);
//      virtual void beatMonster(int exp) = 0;
//      virtual void print();
        string getName();
};
 
Character::Character(string n , int lv , int capacity , int r , int d)
 : name(n) , level(lv) , R(r) , D(d)
{ 
    bag.setBagSize(capacity);
}
 
/*Character::Character(string n, int lv, int po, int kn, int lu) 
  : name(n), level(lv), exp(pow(lv - 1, 2) * EXP_LV), power(po), knowledge(kn), luck(lu) 
{
}
 
void Character::print()
{
    cout << this->name 
        << ": Level " << this->level << " (" << this->exp << "/" << pow(this->level, 2) * EXP_LV << "), " 
        << this->power << "-" << this->knowledge << "-" << this->luck << "\n";
}
 
void Character::levelUp(int pInc, int kInc, int lInc)
{
  this->level++;
  this->power += pInc;
  this->knowledge += kInc;
  this->luck += lInc;    
} */
 
string Character::getName()
{
  return this->name;
}
 
void Character::addtoBag(Item i){
    if(this->R == 1){
        if(i.getType() == 3){
            i.setType();
        }
    }
    else{
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
//      static const int PO_LV = 10;
//      static const int KN_LV = 5;
//      static const int LU_LV = 5;
    public:
        Warrior(string n , int lv , int capacity) : Character(n , lv , capacity , 1 , 0){}
//      Warrior(string n) : Character(n, 1, PO_LV, KN_LV, LU_LV) {}
//      Warrior(string n, int lv) : Character(n, lv, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}
/*      void print()
        {
            cout << "Warrior ";
            Character::print();
        }*/ 
/*      void beatMonster(int exp)
        {
            this->exp += exp;
            while(this->exp >= pow(this->level, 2) * EXP_LV)
            this->levelUp(PO_LV, KN_LV, LU_LV);
        }*/
};
 
 
class Wizard : public Character
{
    private:
//      static const int PO_LV = 4;
//      static const int KN_LV = 9;
//      static const int LU_LV = 7;
    public:
        Wizard(string n , int lv , int capacity) : Character(n , level , capacity , 0 , 1) {}
//      Wizard(string n) : Character(n, 1, PO_LV, KN_LV, LU_LV) {}
//      Wizard(string n, int lv) : Character(n, lv, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}
/*      void print()
        {
            cout << "Wizard ";
            Character::print();
        }*/
/*      void beatMonster(int exp)
        {
            this->exp += exp;
            while(this->exp >= pow(this->level, 2) * EXP_LV)
            this->levelUp(PO_LV, KN_LV, LU_LV);
        }*/
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
//      void memberBeatMonster(string name, int exp);
//      void printMember(string name);
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
 
/*void Team::memberBeatMonster(string name, int exp)
{
    for(int i = 0; i < this->memberCount; i++)
    {
        if(this->member[i]->getName() == name)
        {
            this->member[i]->beatMonster(exp);
            break;
        }
    }  
}*/
 
/*void Team::printMember(string name)
{
    for(int i = 0; i < this->memberCount; i++)
    {
        if(this->member[i]->getName() == name)
        {
            this->member[i]->print();
            break;
        }
    }
}*/
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
