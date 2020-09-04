#include<iostream>


using namespace std;


int main(){
	int n;
	cin>>n;
	int** x=new int*[n];
	int* degree=new int[n];
	for(int i=0;i<n;i++){
		x[i]=new int[i+1];
		degree[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
			cin>>x[i][j];
			if(x[i][j]==1){
				degree[i]++;
				degree[j]++; 
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<degree[i];
		if(i!=n-1){
			cout<<",";
		}
	}
	
	
	
	return 0;
} 
