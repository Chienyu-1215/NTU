#include<iostream>

using namespace std;


int main(){
	int g1,g2;
	cin>>g1>>g2;
	int value[100][100];
	for(int i=0;i<g1;i++){
		for(int j=0;j<g2;j++){
			cin>>value[i][j];
		}
	}
	int totalValue=0,c=0;
	if(g1>g2){
		c=g2;
	}
	else {
		c=g1;
	}
	for(c;c>0;c--){
		int max=0,a=0,b=0;
		for(int i=0;i<g1;i++){
			for(int j=0; j<=g2; j++){
				if(value[i][j]>max){
					max=value[i][j];
					a=i;
					b=j;
				}
			}
		}
		cout<<a+1<<","<<b+1<<";";
		totalValue+=max;
		for(int k=0;k<g2;k++){
			value[a][k]=0;
		}
		for(int l=0;l<g1;l++){
			value[l][b]=0;
		}
	}
	
	
	
	cout<<totalValue;
	return 0;
} 
