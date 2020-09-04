#include<iostream>
using namespace std;


int main(){
	int n, w;
	cin>>n>>w;
	int k=0,b=1;
	for(int i=0;i<n;i++){
		int x=0;
		cin>>x;
		if (k+x<=w){
			k+=x;
		}
		else{
			b++;
			k=x;
			
		}
	}
	cout<<b;
	
	
	return 0;
} 
