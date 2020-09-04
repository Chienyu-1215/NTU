#include<iostream>

using namespace std;
void MergeSort(int x[], int begin,int end, int length);//input an array an sort it


int main(){
	int n1,n2;
	cin>>n1;
	int x[1000]={0};
	for(int i=0;i<n1;i++){
		cin>>x[i];
	}
	cin>>n2;
	for(int i=n1;i<(n1+n2);i++){
		cin>>x[i];
	}
	int n=n1+n2;
	MergeSort(x, 0, n1, n);
	for(int i=0;i<n1+n2;i++){
		cout<<x[i];
		if(i<n1+n2-1){
		 	cout<<",";
		}
	}
	
	return 0;
}


void MergeSort(int x[], int begin, int end, int length){
	if(end==length){
		
	}
	else{
		if(x[end]<=x[begin]){
			int temp1=x[begin],temp2;
			x[begin]=x[end];
			for(int i=begin+1;i<=end;i++){
				temp2=x[i];
				x[i]=temp1;
				temp1=temp2;
			}
			end++;
			MergeSort(x,begin, end, length);
		}
		else if(x[end]>=x[end-1]){

		}
		else{
			for(int i=begin;i<end;i++){
				if(x[end]<=x[i+1]&&x[end]>=x[i]){
					int temp1=x[i+1],temp2;
					x[i+1]=x[end];
					for(int j=i+2;j<=end;j++){
						temp2=x[j];
						x[j]=temp1;
						temp1=temp2;
					}
					end++;
					MergeSort(x,i, end, length);
					break;
				}
			}
		}
	} 
}	

