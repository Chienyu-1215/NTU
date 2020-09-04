#include<iostream>

using namespace std;

int main(){
	int k[10]={0};
	int n=0;
	cin>>n;
	int num[500]={0};
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(0<=num[i]&&num[i]<10){
			k[0]++;
		}
		if(10<=num[i]&&num[i]<20){
			k[1]++;
		}
		if(20<=num[i]&&num[i]<30){
			k[2]++;
		}
		if(30<=num[i]&&num[i]<40){
			k[3]++;
		}
		if(40<=num[i]&&num[i]<50){
			k[4]++;
		}
		if(50<=num[i]&&num[i]<60){
			k[5]++;
		}
		if(60<=num[i]&&num[i]<70){
			k[6]++;
		}
		if(70<=num[i]&&num[i]<80){
			k[7]++;
		}
		if(80<=num[i]&&num[i]<90){
			k[8]++;
		}
		if(90<=num[i]&&num[i]<=100){
			k[9]++;
		}
	}
	for(int i=0;i<9;i++){
		cout<<k[i]<<",";
	}
	cout<<k[9];
	
	
	
	
	return 0;
}
