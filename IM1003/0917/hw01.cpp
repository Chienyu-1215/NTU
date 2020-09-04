#include<iostream>
using namespace std;


int main(){
	int a,b;
	float c;
	cin>>a>>b>>c;
	int money=0;
	if(a+b>=10){
	if(1<=b&&b<=9){
		if(c>=3.5){
			money=10000+3000*b;
			if (money>150000){
				money=150000;
			}
		}
	}
	else if(10<=b&&b<=29){
		if(c>=3.5&&c<4){
			money=15000+4000*b;
			if (money>150000){
				money=150000;
			}
		}
		else if(c>=4){
			money=20000+5000*b;
			if (money>150000){
				money=150000;
			}
		}
		}
	else if(b>=30){
		if(c>=3.5){
			money=30000+6000*b;
			if (money>150000){
				money=150000;
			}
		}
		
	}
}
	cout<<money;
		
	
	
	
	
	
	
	
	
	return 0;
} 
