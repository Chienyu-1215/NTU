#include<iostream>


using namespace std;

int main(){
	int a, b;
	cin>>a>>b;
	int weight[200]={0};
	for(int i=0;i<a;i++){
		cin>>weight[i];
	}
	int box[200]={0};
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(weight[i]<=(b-box[j])){
				box[j]+=weight[i];
				break;
			}
		}
	}
	int i=0;
	for(i=0;i<a;i++){
		if(box[i]==0){
			break;
		}
	}
	cout<<i;
	
	
	
	
	return 0;
} 
