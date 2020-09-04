#include<iostream>
#include<cstring>

using namespace std;


int main(){
	int n;
	cin>>n;
	int* x=new int[n];
	for(int i=0;i<n;i++){
		x[i]=0;
	}
	char input[10000]={0};
	cin.getline(input, 10000);
	int start=0, a=0;
	int sum=0;
	for(int i=0;i<strlen(input);i++){
		if(input[i]==' '){
			char* s=new char[i-start];
			int m=0;
			for(int j=start;j<i;j++){
				s[m]=input[j];
				m++;
			}
			x[a]=atoi(s);
			a++;
			start=i;
		}
	}
	char* s=new char[strlen(input)-start];
	int m=0;
	for(int j=start;j<strlen(input);j++){
		s[m]=input[j];
		m++;
	}
	x[a]=atoi(s);
	a++;
	for(int i=0;i<a;i++){
		sum+=x[i];
	}
	cout<<sum/n<<","<<sum/(a-1); 
	
	
	
	
	return 0;
} 
