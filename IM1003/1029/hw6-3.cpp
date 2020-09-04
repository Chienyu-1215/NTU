#include<iostream>


using namespace std;
const int MAX_T=100;


int main(){
	int T, M, Con, CD, B, R;
	cin>>T>>M>>Con>>CD>>B>>R;
	int Cs0, Cs1, S0, S1;
	cin>>Cs0>>Cs1>>S0>>S1;
	int D[MAX_T]={0}, P[MAX_T]={0}, x[MAX_T]={0}, w[MAX_T]={0};
	for(int i=0;i<T;i++){
		cin>>D[i];
	}
	for(int i=0;i<T;i++){
		cin>>P[i];
	}
	for(int i=0;i<T;i++){
		cin>>x[i];
	}
	for(int i=0;i<T;i++){
		cin>>w[i];
	}
	bool okay=1;
	int totalExpense=0;
	int totalExpense_Con=0, totalExpense_CD=0, totalExpense_Cs0=0, totalExpense_Cs1=0, totalExpense_P=0;
	for(int i=0;i<T;i++){
		S0+=w[i];
		S0-=x[i];
		if(S0<0||x[i]>M*B||(S1+x[i])<D[i]){
			okay=0;
			break;
		}
		else{
			if(x[i]%B==0){
				totalExpense_Con+=Con*(x[i]/B);
			}
			else{
				totalExpense_Con+=Con*(x[i]/B+1);
			}
			totalExpense_CD+=CD*x[i];
			totalExpense_Cs0+=Cs0*S0;
			S1+=x[i];
			S1-=D[i];
			totalExpense_Cs1+=Cs1*S1;
			totalExpense_P+=w[i]*P[i];
		}
	}
		
	if(okay==1){
		cout<<totalExpense_Con<<","<<totalExpense_CD<<","<<totalExpense_Cs0<<","<<totalExpense_Cs1<<","<<totalExpense_P;
	}
	else{
		cout<<-1;
	}
	return 0;
} 
