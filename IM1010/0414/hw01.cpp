#include<iostream>
#include<string>

using namespace std;

class Item
{
	private:
		int v;
		int w;
		int num;
		float ratio;
	public:
		Item();
		Item(int value , int weight , int n);
		int getW();
		int getV();
		int getN();
		float getR();
};

Item::Item() : v(0), w(0), ratio(0), num(0)
{
	
}

Item::Item(int value , int weight , int n): v(value), w(weight), num(n)
{
	ratio = static_cast<float>(v)/w;
}

int Item::getN()
{
	return this->num;
}

int Item::getV()
{
	return this->v;
}

int Item::getW()
{
	return this->w;
}

float Item::getR()
{
	return this->ratio;
}

int main(){
	int n = 0 , B = 0;
	cin >> n >> B;
	int* v = new int [n];
	int* w = new int [n];
	Item** items = new Item* [n];
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin >> w[i];
		items[i] = new Item(v[i] , w[i] , i);
		for(int j = 0 ; j < i ; j++){
			if(items[j]->getR() < items[i]->getR()){
				Item* temp = items[i];
				items[i] = items[j];
				items[j] = temp;
			}
		}
	}
//	for(int i = 0 ; i < n ; i++){
//		cout << items[i]->getR() << " ";
//	}
	int curSize = 0, totalV = 0, cnt = 0;
	int* add = new int[n];
	for(int i = 0 ; i < n ; i++){
		if((curSize + items[i]->getW()) <= B){
			curSize += items[i]->getW();
			totalV += items[i]->getV();
			add[cnt] = items[i]->getN() + 1;
			cnt++;
		}
		if(curSize >= B){
			break;
		}
	}
	for(int i = 0 ; i < cnt ; i++){
		for(int j = 0 ; j < i ; j++){
			if(add[i] < add[j]){
				int temp = add[i];
				add[i] = add[j];
				add[j] = temp;
			}
		}
	}
	for(int i = 0 ; i < cnt ; i++){
		if(i != 0){
			cout << ",";
		}
		cout << add[i]; 
	}
	cout << ";" << curSize;
	
	delete[] items;
	delete[] add;
	delete[] v;
	delete[] w;
	
	
	return 0;
} 
