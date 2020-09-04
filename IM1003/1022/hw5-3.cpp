#include<iostream>



using namespace std;



int main(){
	int n1, n2;
	cin>>n1;
	int*x=new int[n1];
	for(int i=0;i<n1;i++){
		cin>>x[i];
		if(x[i]==x[i-1]&&i!=0){//delete repeated element
			i--;
			n1--;
		}
	}
	cin>>n2;
	int*y=new int[n2];
	for(int i=0;i<n2;i++){
		cin>>y[i];
		if(y[i]==y[i-1]&&i!=0){//delete repeated element
			i--;
			n2--;
		}
	}
	int n=n1+n2;
	int*z=new int[n];//array z is the combination of x&y
	int start=0;
	int i=0;
	int num=0;//count how many integers in array z
	for(i;i<n1;i++){
		for(;start<n2;){
			if(x[i]==y[start]){
				z[num]=x[i];
				start++;
				num++;
				break;
			}
			else if(x[i]>y[start]){
				z[num]=y[start];
				start++;
				num++;
			}
			else{
				z[num]=x[i];
				num++;
				break;
			}
		}
		if(start==n2){
			if(z[num-1]!=x[i]){//put the elements unsorted in x to z
				z[num]=x[i];
				num++;
			}
		}
	}
	for(;start<n2;start++){//put the elements unsorted in y to z
		z[num]=y[start];
		num++;
	} 
	
	for(int i=0;i<num;i++){
		cout<<z[i];
		if(i<num-1){
			cout<<",";
		}
	}
	
	
	
	
	return 0;
} 

	
