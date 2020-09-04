#include<iostream>
using namespace std;



int main(){
	int n=0;
	cin>>n;
	int money=0;
	for (int i=0;i<n;i++){
		int a,b;
		float c;
		int k=0;
		cin >>a>>b>>c;
		if(a+b>=10&&b>=1&&c>=3.5){
			k=15000+4000*b;
			if(k>150000){
				k=150000;
			}
		}
		money+=k;
	}
	cout<<money;
	
	
	
	return 0;
}
