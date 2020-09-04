#include<iostream>
#include<string>
 
using namespace std;
 
void arrange(string* s , int count);
 
class Product
{
    private:
        string name;
    public:
        Product();
        Product(string nm);
        string getName();
};
 
Product::Product()
{
    this -> name = nullptr;
};
 
Product::Product(string nm)
{
    this -> name = nm;
};
 
string Product::getName(){
    return this -> name;
};
 
class ProductList
{
    private:
        Product** list;
        int total;
        int Capacity;
    public:
        ProductList();
        void addProduct(string nm);
        bool searchProduct(string target);
};
 
ProductList::ProductList()
{
    this -> Capacity = 500;
    this -> total = 0;
    list = new Product* [this -> Capacity];
};
 
void ProductList::addProduct(string nm)
{
    if(this -> total < this -> Capacity){
        list[this -> total] = new Product(nm);
        this -> total++;
    }   
};
 
bool ProductList::searchProduct(string target)
{
    for(int i = 0 ; i < this -> total ; i++){
        if(this -> list[i][0].getName() == target){
            return 1;
        }
    }
    return 0;
};
 
class History
{
    private:
        int Cnt;
        int Capacity;
        string* product;
        string* person;
        int* rate;
    public:
        History();
        void add(string per , string pro , int ra);//per = person(seller) , pro = product , ra =rate
        void searching(string target);
        int experience(string seller , string target);//search if the customer has experiences buying things from the seller
        ~History();
         
         
};
 
History::History()
{
    this -> Cnt = 0;
    this -> Capacity = 500;
    this -> product = new string [this -> Capacity];
    this -> person = new string [this -> Capacity];
    this -> rate = new int [this -> Capacity];
};
 
void History::add(string per , string pro , int ra)
{
    if(this -> Cnt < this -> Capacity){
        person[this -> Cnt] = per;
        product[this -> Cnt] = pro;
        rate[this -> Cnt] = ra;
        this -> Cnt++;
    }
};
 
void History::searching(string target)
{
    string* toprint = new string[this -> Cnt];
    int HighestRate = 0;
    int cnt = 0;
    for(int i = 0 ; i < this -> Cnt ; i++){
        if(this -> product[i] == target){
            if(rate[i] == HighestRate){
                toprint[cnt] = this -> person[i];
                cnt++;
            }
            else if(rate[i] > HighestRate){
                HighestRate = rate[i];
                cnt = 0;
                toprint[cnt] = this -> person[i];
                cnt++;
            }
        }
    }
	if(cnt > 5){
        cnt = 5;
    }
    arrange(toprint , cnt);
    
    for(int i = 0 ; i < cnt ; i++){
        if(i > 0){
            cout << " ";
        }
        cout << toprint[i];
    }
    delete[] toprint;
};
 
int History::experience(string seller , string target)
{
    for(int i = 0 ; i < this -> Cnt ; i++){
        if(this -> person[i] == seller && this -> product[i] == target){
            return this -> rate[i];
        }
    }
    return -1;
};
 
History::~History()
{
    delete[] person;
    delete[] product;
    delete[] rate;
};
 
class Member
{
    protected:
        string name;
        int totalrate;
        int times;
    public:
        Member();
        Member(string nm);
        string getName();
        void addRate(int rate);
        int getTimes();
        ~Member();  
};
 
Member::Member()
{
    this -> times = 0;
    this -> totalrate = 0;
    this -> name = nullptr;  
};
 
Member::Member(string nm)
{
    this -> name = nm;
	this -> times = 0;
	this -> totalrate = 0;   
};
 
string Member::getName()
{
    return this -> name;
};
 
int Member::getTimes(){
    return this -> times;
};
 
void Member::addRate(int rate)
{
    this -> totalrate+= rate;
    this -> times++; 
};
 
Member::~Member()
{
    name = nullptr;
};
 
class Customer : public Member
{   
    private:
        History history;
    public:
        Customer();
        Customer(string nm);
        bool vip();
        void addHistory(string per , string pro , int ra);
        void searchHistory(string target);
        float getHistoryRate(string seller , string target);
         
};
 
Customer::Customer() : Member()
{
     
};
 
Customer::Customer(string nm) : Member(nm)
{
     
};
 
bool Customer::vip()
{
    if(this -> times >= 3 && this -> totalrate > this -> times * 3){
        return true;
    }
    return false;
};
 
void Customer::addHistory(string per , string pro , int ra)
{
    history.add(per , pro , ra);
};
 
 
void Customer::searchHistory(string target)
{
    history.searching(target);
};
 
float Customer::getHistoryRate(string seller , string target)
{
    return history.experience(seller , target);
};
 
 
class Seller : public Member
{
    private:
        ProductList tosell;
    public:
        Seller();
        Seller(string nm);  
        void addingProduct(string nm);
        bool available(string target);//if the product is available to sell
        float getAvgRate();
}; 
 
Seller::Seller() : Member()
{
    this -> tosell;
};
 
Seller::Seller(string nm) : Member(nm)
{
};
 
void Seller::addingProduct(string nm)
{
    this -> tosell.addProduct(nm);
};
 
bool Seller::available(string target)
{
    return this -> tosell.searchProduct(target);
};
 
float Seller::getAvgRate()
{
    return static_cast<float>(this -> totalrate) / static_cast<float>(this -> times);
}
 
class List
{
    protected:
        int stotal;//total seller
        int ctotal;//total customer
        Seller** slist;
        Customer** clist;
        int Capacity;
    public:
        List();
        void addCustomer(string nm);
        void addSeller(string nm);
        void addtoSell(string seller , string product);
        void addData(string buyer , string seller , string product , int Srate , int Brate);
        void searchList(string buyer , string product);
        void advSearching(string buyer , string target , int n , bool X);//n = nmin
        ~List();
};
 
List::List()
{
    this -> stotal = 0;
    this -> ctotal = 0;
    this -> Capacity = 500;
    this -> slist = new Seller* [this -> Capacity];
    this -> clist = new Customer* [this -> Capacity];
};
 
void List::addCustomer(string nm)
{
    if(this -> ctotal < this -> Capacity){
        clist[this -> ctotal] = new Customer(nm);
        ctotal++;
    }
};
 
void List::addSeller(string nm)
{
    if(this -> stotal < this -> Capacity){
        slist[this -> stotal] = new Seller(nm);
        stotal++;
    }
};
 
void List::addtoSell(string seller , string product){
    for(int i = 0 ; i < this -> stotal ; i++){
        if(slist[i][0].getName() == seller){
            slist[i][0].addingProduct(product);
        }
    }
};
 
void List::addData(string buyer , string seller , string product , int Srate , int Brate)//Srate = seller's rate(from customer) , Brate = buyer's rate
{
     
    for(int i = 0 ; i < this -> ctotal ; i++){
        if(clist[i][0].getName() == buyer){
            clist[i][0].addHistory(seller , product , Srate);
            clist[i][0].addRate(Brate);
            break;
        }
    }
    for(int i = 0 ; i < this -> stotal ; i++){
        if(slist[i][0].getName() == seller){
            slist[i][0].addRate(Srate);
            break;
        }
    }
};
 
void List::searchList(string buyer , string product)
{
    for(int i = 0 ; i < this -> ctotal ; i++){
        if(clist[i][0].getName() == buyer){
            clist[i][0].searchHistory(product);
            break;
        }
    }
};
 
void List::advSearching(string buyer , string target , int n , bool X){
    for(int i = 0 ; i < ctotal ; i++){
        if(clist[i][0].getName() == buyer){
            if(X == 1){
                string* toprint = new string[this -> stotal];
                float HighestRate = 0;
                int cnt = 0;
                if(clist[i][0].vip() == true){
                    for(int j = 0 ; j < stotal ; j++){
                        if(slist[j][0].getTimes() >= n){
                            if(slist[j][0].available(target)){
                                if(slist[j][0].getAvgRate() > HighestRate){
                                    HighestRate = slist[j][0].getAvgRate();
                                    cnt = 0;
                                    toprint[cnt] = slist[j][0].getName();
                                    cnt++;
                                }
                                else if(slist[j][0].getAvgRate() == HighestRate){
                                    toprint[cnt] = slist[j][0].getName();
                                    cnt++;
                                }
                            }
                        }
                    }
                    if(cnt > 5){
                        cnt = 5;
                    }
					arrange(toprint , cnt);
                    for(int k = 0 ; k < cnt ; k++){
                        if(k != 0){
                            cout << " ";
                        }
                        cout << toprint[k];
                    }   
                    delete[] toprint;   
                }
                else{
                    cout << "reject";
                }
            }
            else{
                string* toprint = new string[this -> clist[i][0].getTimes()];
                float HighestRate = 1;
                int cnt = 0;
                if(clist[i][0].vip() == true){
                    for(int j = 0 ; j < stotal ; j++){
                        if(slist[j][0].getTimes() >= n){
                            if(clist[i][0].getHistoryRate(slist[j][0].getName() , target) > HighestRate){
                                HighestRate = clist[i][0].getHistoryRate(slist[j][0].getName() , target);
                                cnt = 0;
                                toprint[cnt] = slist[j][0].getName();
                                cnt++;
                            }
                            else if(clist[i][0].getHistoryRate(slist[j][0].getName() , target) == HighestRate){
                                toprint[cnt] = slist[j][0].getName();
                                cnt++;
                            }           
                        }
                    }
					if(cnt > 5){
                        cnt = 5;
                    }
                    arrange(toprint , cnt);    
                    for(int k = 0 ; k < cnt ; k++){
                        if(k != 0){
                            cout << " ";
                        }
                        cout << toprint[k];
                    }
                    delete[] toprint;   
                }
                else{
                    cout << "reject";
                }
            }
            break;
        }
    }
}
 
List::~List()
{
    this -> ctotal = 0;
    this -> stotal = 0;
    this -> clist = nullptr; 
    this -> slist = nullptr;
}; 
 
int main(){
    char order;
    List memberlist;
    ProductList plist;
    while(cin >> order){
        if(order == 'C'){
            string name;
            cin >> name;
            memberlist.addCustomer(name);
        }
        else if(order == 'M'){
            string name;
            cin >> name;
            memberlist.addSeller(name);
        }
        else if(order == 'T'){
            string c , s , p;//c = customer , s = seller , p = product
            int Brate , Srate;//Crate = buyer rate , Srate = seller rate
            cin >> c >> s >> p >> Srate >> Brate;
            memberlist.addData(c , s , p , Srate , Brate);
        } 
        else if(order == 'P'){
            string name;
            cin >> name;
            plist.addProduct(name);
        }
        else if(order == 'A'){
            string s , p;//s = seller , p = product
            cin >> s >> p;
            memberlist.addtoSell(s , p);
        }
        else if(order == 'S'){
            string input;
            getline(cin , input);
            int cnt = 0;
            bool advSearch = 0;
            const char seperator = ' ';
            int start = 0;
            int length = 0;//length of the name of product or customer
            string buyer , product;
            int n = 0;
            bool X = 0;
            for(int i = 1 ; i < input.length() ; i++){
                length++;   
                if(input[i] == seperator){
                    cnt++;
                    if(cnt == 1){
                        buyer = input.substr(1 , length - 1);
                        start = i + 1;
                        length = 0;
                    }
                    else if(cnt == 2){
                        product = input.substr(start , length - 1);
                        start = i + 1;
                        length = 0;
                    }
                    else{
                        n = stoi(input.substr(start , length));
                        X = stoi(input.substr(start + 2 , 1));
                        advSearch = 1;
                        break;
                    }
                }
            }
            if(advSearch == 0){
                product = input.substr(start , length);
                memberlist.searchList(buyer , product);
            }
            else if(advSearch == 1){
                memberlist.advSearching(buyer , product , n , X);
            }
            cout << endl;
        }
    }
    return 0;
} 
 
void arrange(string* s , int count)
{
    for(int i = 0 ; i < count ; i++){
        for(int j = 0 ; j < i ; j++){
            if(s[j].compare(s[i]) > 0){
                string temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        } 
    }
}
