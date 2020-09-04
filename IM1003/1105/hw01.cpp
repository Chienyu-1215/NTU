#include<iostream>


using namespace std;

int main(){
	int I, T;
	cin>>I>>T;
	int* M=new int[I];
	int* Con=new int[I];
	int* CD=new int[I];
	int* B=new int[I];
	int* R=new int[I];
	int* CS=new int[I+1];
	int* S=new int[I+1];
	int* D=new int[T]; 
	int* P=new int[T];
	int** x=new int*[I];
	for(int i=0;i<I;i++){
		x[i]=new int[T];
	}
	int* w=new int[T];
	for(int i=0;i<I;i++){
		cin>>M[i]; 
	}
	for(int i=0;i<I;i++){
		cin>>Con[i]; 
	}
	for(int i=0;i<I;i++){
		cin>>CD[i]; 
	}
	for(int i=0;i<I;i++){
		cin>>B[i]; 
	}
	for(int i=0;i<I;i++){
		cin>>R[i]; 
	}
	for(int i=0;i<I+1;i++){
		cin>>CS[i]; 
	}
	for(int i=0;i<I+1;i++){
		cin>>S[i]; 
	}
	for(int i=0;i<T;i++){
		cin>>D[i]; 
	}
	for(int i=0;i<T;i++){
		cin>>P[i]; 
	}
	for(int i=0;i<I;i++){
		for(int j=0;j<T;j++){
			cin>>x[i][j]; 
		}
	}
	for(int i=0;i<T;i++){
		cin>>w[i]; 
	}
	int totalCon=0, totalCD=0, totalP=0;
	int* totalCs=new int[I+1];
	for(int i=0;i<I+1;i++){
		totalCs[i]=0;
	}
	
	for(int i=0;i<T;i++){
		for(int j=0;j<I;j++){
			if(x[j][i]>M[j]*B[j]){
				cout<<-1;
				return 0;
			}
		}
	}
	
	for(int i=0;i<T;i++){
		S[0]+=w[i];
		for(int j=0;j<I;j++){
			totalCon+=Con[j]*(x[j][i]/B[j]+(x[j][i]%B[j]==0? 0:1));
			totalCD+=CD[j]*x[j][i];
			S[j+1]+=x[j][i];
			S[j]-=x[j][i]*R[j];
			if(S[j]<0){
				cout<<-1;
				return 0;
			}
			totalCs[j]+= S[j]*CS[j];
		}
		S[I]-=D[i];
		if(S[I]<0){
			cout<<-1;
			return 0;
		}
		totalCs[I]+=S[I]*CS[I];
		totalP+=P[i]*w[i];
	}
	
	
	
	cout<<totalCon<<","<<totalCD<<",";
	for(int i=0;i<I+1;i++){
		cout<<totalCs[i]<<",";
	}
	cout<<totalP;
	return 0;
} 
