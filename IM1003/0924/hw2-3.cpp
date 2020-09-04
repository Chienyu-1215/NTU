#include<iostream>

using namespace std;

int main(){
	int a, b, d;
	cin>>a>>b>>d;
	int wage=0, price=0, ben=0;
	int w=0, p=2;
	int q=0, s=0, k=0;
	int min=0;
	for(;a>b*p;p++){
		q=a-(b*p);
		for(w=0;(p-w)>0;w++){
			s=w*d;
			if(q>s){
				min=s;
			}
			else{
				min=q;
			}
			k=min*p-min*w;
			if(k>ben){
				ben=k;
				wage=w;
				price=p;
			}
			
		}	
	}
	cout<<price<<" "<<wage<<" "<<ben; 
	
	
	
	
	
	return 0;
}
