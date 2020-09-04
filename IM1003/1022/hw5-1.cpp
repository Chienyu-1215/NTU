#include<iostream>

using namespace std;
void placeNum(int array[], int n, int k);

int main(){
	int n;
	cin>>n;
	int number[500]={0};//the input array may have 500 elements at most
	for(int i=0;i<n;i++){
		cin>>number[i];
	}
	int k;
	cin>>k;
	placeNum(number,n,k);
	
	return 0;
} 
;
void placeNum(int array[], int n, int k){
	if(k<=array[0]){//if k smaller than all the elements in the array, print k
		cout<<k<<","; 
	}
	for(int i=0;i<n;i++){
		if(array[i]<k&&array[i+1]>=k){//if k should be put between arrayi & array(i+1)
			cout<<array[i]<<","<<k<<","<<array[i+1];
			if(i<n-2){
				cout<<",";
			}
			i++;
		}
		else if(i<n-1){//if we can't find the interval suits the if condition above, print arrayi and a comma if arrayi is not the last element of the array
			cout<<array[i]<<",";
		}
		else{//print the last element of the array
			cout<<array[i];
		}
		
	}
	if(array[n-1]<k){//if k bigger than all the elements in the array, print k
		cout<<","<<k;
	}
}
