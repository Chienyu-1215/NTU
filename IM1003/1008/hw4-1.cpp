#include<iostream>

using namespace std;
int findTriType(int a, int b, int c);

int main(){
	int a, b,c;
	cin>>a>>b>>c;
	if(a+b>=c&&a+c>=b&&b+c>=a){
		if(a>b&&a>c){
			cout<<findTriType(a,b,c);
		}
		else if(b>a&&b>c){
			cout<<findTriType(b,a,c);
		}
		else{
			cout<<findTriType(c,b,a);
		}
	}
	else{
		cout<<"-1";
	}
	
	return 0;
}



int findTriType(int a, int b, int c){
	if(a*a==(b*b+c*c)){
		return 0;
	}
	else if(a*a>(b*b+c*c)){
		return 2;
	}
	else{
		return 1;
	}
}
