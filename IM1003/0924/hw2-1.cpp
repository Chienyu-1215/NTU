#include<iostream>

using namespace std;

int main(){
	int n,m,x,y,b,d;
	cin>>n>>m>>x>>y>>b>>d;
	int t=0, money=0;
	for(int i=0;i<d;i++){
		int k=0;
		cin>>k;
		money+=k*x;
		if(k>n){
		money+=(k-n)*(y-x);}
		t+=k;
	}
	if(t>=m){
		money+=b;
	}
	cout<<money;
	
	return 0;
}
