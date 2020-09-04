#include<iostream>
#include<string>
#include<stdexcept>
#include<iomanip>


using namespace std;

class Event
{
	private:
		int time;
		bool type;//0 = arrival, 1 = departure
		int length;
	public:
		Event();
		Event(bool tp , int t , int l) : type(tp) , time(t) , length(l){};
		Event(const Event& e);
		int getTime(){return time;};
		int getLength(){return length;};
		bool getType(){return type;}
		bool operator> (const Event& e) const;
		bool operator<= (const Event& e) const;
};

Event::Event(const Event& e)
{
	this->time = e.time;
	this->type = e.type;
	this->length = e.length;
}

bool Event::operator<= (const Event& e) const
{
	if(e.time < this->time){
		return false;
	}
	else return true;
}

bool Event::operator> (const Event& e) const
{
	if(e.time >= this->time){
		return false;
	}
	else return true;
}

class Customer
{
	private:
		int arrival;
		int length;
	public:
		Customer();
		Customer(int t , int l) : arrival(t) , length(l){};
		int getTime(){return arrival + length;};
		int getLength(){return length;};	
};


template<class ItemType>
class Node
{
	private:
	  ItemType item;
	  Node<ItemType>* next; 
	public:
	  Node();
	  Node(const ItemType& anItem);
	  Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	  void setItem(const ItemType& anItem);
	  void setNext(Node<ItemType>* nextNodePtr);
	  ItemType getItem() const;
	  Node<ItemType>* getNext() const;
}; 

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} 

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} 

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
} 

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
} 

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
} 

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
} 

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
} 


template<class ItemType>
class QueueInterface
{
	public:
		virtual bool isEmpty() const = 0;
		virtual bool enqueue(const ItemType& newEntry) = 0;
		virtual bool dequeue() = 0;
		virtual ItemType peekFront() const throw(logic_error) = 0;
};


template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
	protected:
		Node<ItemType>* backPtr;
		Node<ItemType>* frontPtr;
	public:
		LinkedQueue() : backPtr(nullptr) , frontPtr(nullptr){};
		bool isEmpty() const;
		virtual bool enqueue(const ItemType& newEntry);
		bool dequeue();
		ItemType peekFront() const throw(logic_error);
};

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	if(frontPtr == nullptr) return true;
	else return false;
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	if(isEmpty()) //insertion into empty queue
		frontPtr = newNodePtr;
	else // insertion into nonempty queue
		backPtr->setNext(newNodePtr);
	backPtr = newNodePtr;
	return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if(!isEmpty())
	{
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		if(frontPtr == backPtr) // A queue of one item?
		{
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		result = true;
	} // end if(!isEmpty())
	return result;
} // end dequeue

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(logic_error)
{
	if(frontPtr != nullptr){
		return frontPtr->getItem();
	}
	else{
		throw logic_error("the queue is empty");
	}
}


class EventQueue : public LinkedQueue<Event>
{
	public:
		bool isEmpty() const;
		bool enqueue(const Event& newEntry);
};

bool EventQueue::isEmpty() const
{
	if(this->frontPtr == nullptr) return true;
	else return false;
}


bool EventQueue::enqueue(const Event& newEntry)
{
	Node<Event>* newPtr = new Node<Event>(newEntry);
	if(isEmpty()){ //insertion into empty queue
		this->frontPtr = newPtr;
		this->backPtr = newPtr;
	}
	else if(this->backPtr->getItem() <= newEntry){
		this->backPtr->setNext(newPtr);
		this->backPtr = newPtr;
	}
	else if(this->frontPtr->getItem() > newEntry){
		newPtr->setNext(this->frontPtr);
		this->frontPtr = newPtr;
	}
	else{
		Node<Event>* curPtr = this->frontPtr->getNext();
		Node<Event>* curPtr1 = this->frontPtr;
		while(curPtr1 != nullptr){
			if(curPtr->getItem() > newEntry){
				curPtr1->setNext(newPtr);
				newPtr->setNext(curPtr);
				break; 
			}
			curPtr1 = curPtr;
			curPtr = curPtr->getNext();
		}
	}
}


void stimulation(EventQueue events)
{
	cout << "Simulation Begins" << "\n"; 
	int currentTime;
	int WaitT = 0 , totalC = 0; //totalWaitTime;
	LinkedQueue<Customer> customers;
	bool available = true;
	while (!events.isEmpty()){
		Event newEvent = events.peekFront();
		currentTime = newEvent.getTime();
		events.dequeue();
		if(newEvent.getType() == 0){
			cout << "Processing an arrival event at time: " << currentTime << "\n";
			totalC++;
			if(customers.isEmpty() && available == true){
				Event departure(true , newEvent.getTime() + newEvent.getLength() , 0);
				events.enqueue(departure);
				available = false;
				Customer newCustomer(newEvent.getTime() , newEvent.getLength());
				customers.enqueue(newCustomer);
			}
			else{
				Customer newCustomer(newEvent.getTime() , newEvent.getLength());
				customers.enqueue(newCustomer);
			}
		}
		else{
			cout << "Processing a departure event at time: " << currentTime << "\n"; 
			Customer c = customers.peekFront();
			customers.dequeue();
			WaitT += currentTime - c.getTime();
			if(!customers.isEmpty()){
				Customer c = customers.peekFront();
				Event departure(1 , currentTime + c.getLength() , 0);
				events.enqueue(departure);
			}
			else available = true; 
		}
	} // end while
	cout << "Simulation Ends\n\n";
	cout << "Final Statistics:\n\n";
	cout << "\tTotal number of people processed: " << totalC << "\n\tAverage amount of time spent waiting: " ;
	cout << fixed << setprecision(1) <<  static_cast<float>(WaitT)/totalC;
}


int main(){
	EventQueue events;
	int time , length;
	while(cin >> time >> length){	
		Event newEvent(0 , time , length);
		events.enqueue(newEvent);
	}
	
	stimulation(events);
	
	
	return 0;
}


