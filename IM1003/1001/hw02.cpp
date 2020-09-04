#include<iostream>


using namespace std;


int main(){
	int g1,g2; //g1=group1, g2=group2
	cin>>g1>>g2;
	int value[200][200]={0};
	for (int i=0;i<g1;i++){
		for (int j=0;j<g2;j++){
			cin>>value[i][j];
		} 
	}
	int totalValue=0;
	if(g1>g2){
		for (int i=0;i<g2;i++){
			int maxValue=0, match1=0;
			for(int j=0;j<g1;j++){
				if(value[j][i]>maxValue){
					maxValue=value[j][i];
					match1=j;
				}				
			}
			cout<<match1+1;
			for(int k=0;k<g1;k++){
				value[match1][k]=0;
			}
			totalValue+=maxValue;
			if(i!=g2-1){
				cout<<",";
			}	
		}
	}
	else{
		for(int i=0;i<g1;i++){
			int maxValue=0, match1=0;
			for(int j=0;j<g2;j++){
				if(value[i][j]>maxValue){
					maxValue=value[i][j];
					match1=j;
				}				
			}
			for(int k=0;k<g2;k++){
				value[k][match1]=0;
			}
			cout<<match1+1;
			totalValue+=maxValue;
			if(i!=g1-1){
				cout<<",";
			}		
		}
	}
	cout<<";"<<totalValue;
	
	return 0;
} 
