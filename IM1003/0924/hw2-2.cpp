#include<iostream>

using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int p=0, ben=0,q=0,s=0;
	int min=0, price=0;
	for(p;p<(a/b);p++){
		q=a-b*p;
		s=d*c;
		if(q>s){
			min=s;
		}
		else{
			min=q;
		}
		if(min*(p-c)>ben){
			ben=min*(p-c);
			price=p;
		}
	}
	cout<<price<<" "<<ben;
	
	
	
	return 0;
} 
