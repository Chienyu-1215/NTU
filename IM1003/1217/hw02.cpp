#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class BigInt{
	private:
		char* num;
	public:
		BigInt();
		BigInt(char array[]);
		void add(BigInt b);
		void subtract(BigInt b);
		void print();
		void negate();
		void abs();
}; 

BigInt::BigInt(){
	;
}

BigInt::BigInt(char array[]){
	if(array[0] != '-'){
		int a = strlen(array) + 1;
		num = new char[a];
		int j = 0;
		num[0] = '+';
		for(int i = a - 1 ; i > 0 ; i--){
			num[i] = array[j];
			j++;
		}
	}
	else{
		num = new char[strlen(array)];
		num[0] = '-';
		int j = 1;
		for(int i = strlen(array) - 1 ; i > 0 ; i--){
			num[i] = array[j];
			j++;
		}
//		cout << num;
//		cout << strlen(num);
	}
}

void BigInt::abs(){
	if (num[0] != '-'){
		;
	}
	else{
		num[0] = '+';
	}
}

void BigInt::print(){
	if(num[0] == '-'){
		cout << "-";
	}
	for(int i = strlen(num) - 1 ; i > 0 ; i--){
		cout << num[i];
		if (i % 3 == 1 && i != 1){
			cout << ",";
		}
	}
}

void BigInt::negate(){
	if (num[0] != '-'){
		num[0] = '-';
	}
	else{
		num[0] = '+';
	}
}

void BigInt::add(BigInt b){
	if(num[0] == b.num[0] && num[0] == '+'){
		int a = max(strlen(num) , strlen(b.num));
		for(int i = 0 ; i < a ; i++){
			
		} 
		 
	}
}

int main(){
	char array[1000] = {0};
	cin >> array;
	BigInt a(array);
	a.print();
	return 0;
} 
