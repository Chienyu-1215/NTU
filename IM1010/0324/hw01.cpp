#include<iostream>
#include<string>

using namespace std;

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
		void add(string per , string pro , int ra);
		void searching(string target);
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
}

void History::searching(string target)
{
	string* toprint = new string[this -> Cnt];
	int HighestRate = 0;
	int count = 0;
	for(int i = 0 ; i < this -> Cnt ; i++){
		if(this -> product[i] == target){
			if(rate[i] == HighestRate){
				toprint[count] = this -> person[i];
				count++;
			}
			else if(rate[i] > HighestRate){
				HighestRate = rate[i];
				count = 0;
				toprint[count] = this -> person[i];
				count++;
			}
		}
	}
	for(int i = 0 ; i < count ; i++){
		for(int j = 0 ; j < i ; j++){
			if(toprint[j].compare(toprint[i]) > 0){
				string temp = toprint[i];
				toprint[i] = toprint[j];
				toprint[j] = temp;
			}
		} 
	}
	for(int i = 0 ; i < count ; i++){
		if(i > 0){
			cout << " ";
		}
		cout << toprint[i];
	}
}

History::~History()
{
	delete[] person;
	delete[] product;
	delete[] rate;
}

class Member
{
	protected:
		string name;
		History history;
	public:
		Member();
		Member(string nm);
		string getName();
		void addHistory(string per , string pro , int ra);
		void searchHistory(string target);
		~Member();	
};

Member::Member()
{
	this -> name = nullptr;	
};

Member::Member(string nm)
{
	this -> name = nm;	
};

string Member::getName()
{
	return this -> name;
}

void Member::addHistory(string per , string pro , int ra)
{
	history.add(per , pro , ra);
}

void Member::searchHistory(string target)
{
	history.searching(target);
}

class Customer : public Member
{	
	public:
		Customer();
		Customer(string nm);
		
};

Customer::Customer() : Member()
{
	
};

Customer::Customer(string nm) : Member(nm)
{
	
};

class Seller : public Member
{
	public:
		Seller();
		Seller(string nm);	
}; 

Seller::Seller() : Member()
{
	
};

Seller::Seller(string nm) : Member(nm)
{
};

class List
{
	protected:
		int total;
		Member** list;
		int Capacity;
	public:
		List();
		void addCustomer(string nm);
		void addSeller(string nm);
		void addData(string buyer , string seller , string product , int Srate , int Brate);
		void searchList(string buyer , string product);
		~List();
};

List::List()
{
	this -> total = 0;
	this -> Capacity = 500;
	this -> list = new Member* [this -> Capacity];
};

void List::addCustomer(string nm)
{
	if(this -> total < this -> Capacity){
		list[this -> total] = new Customer(nm);
		total++;
	}
};

void List::addSeller(string nm)
{
	if(this -> total < this -> Capacity){
		list[this -> total] = new Seller(nm);
		total++;
	}
};

void List::addData(string buyer , string seller , string product , int Srate , int Brate)
{
	for(int i = 0 ; i < this -> total ; i++){
		if(list[i][0].getName() == buyer){
			list[i][0].addHistory(seller , product , Srate);
			break;
		}
	}
}

void List::searchList(string buyer , string product)
{
	for(int i = 0 ; i < this -> total ; i++){
		if(list[i][0].getName() == buyer){
			list[i][0].searchHistory(product);
			break;
		}
	}
} 

List::~List(){
	this -> total = 0;
	this -> list = nullptr;	
}; 


int main(){
	char order;
	List memberlist;
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
		else if(order == 'S'){
			string c , p;
			cin >> c >> p;
			memberlist.searchList(c , p);
			cout << endl;
		}
	}
	return 0;
} 
