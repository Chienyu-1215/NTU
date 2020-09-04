#include<iostream>
#include<cstring>

using namespace std;
const int MAX_LENGTH=1001;


int main(){
	char sentence[MAX_LENGTH]={0};
	cin.getline(sentence, MAX_LENGTH);
	for(int i=0;i<strlen(sentence);i++){
		if(sentence[i]=='0'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"zero";
		}
		else if(sentence[i]=='1'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='0'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"one";
		}
		else if(sentence[i]=='2'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='0'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"two";
		}
		else if(sentence[i]=='3'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='0'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"three";
		}
		else if(sentence[i]=='4'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='0'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"four";
		}
		else if(sentence[i]=='5'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='0'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"five";
		}
		else if(sentence[i]=='6'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='0'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"six";
		}
		else if(sentence[i]=='7'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='0'&&sentence[i-1]!='8'&&sentence[i-1]!='9')){
			cout<<"seven";
		}
		else if(sentence[i]=='8'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='0'&&sentence[i-1]!='9')){
			cout<<"eight";
		}
		else if(sentence[i]=='9'&&(sentence[i+1]==' '||sentence[i+1]=='\0')&&(sentence[i-1]!='1'&&sentence[i-1]!='2'&&sentence[i-1]!='3'&&sentence[i-1]!='4'&&sentence[i-1]!='5'&&sentence[i-1]!='6'&&sentence[i-1]!='7'&&sentence[i-1]!='8'&&sentence[i-1]!='0')){
			cout<<"nine";
		}
		else{
			cout<<sentence[i];
		}
	}
	
	
	
	return 0;
} 
