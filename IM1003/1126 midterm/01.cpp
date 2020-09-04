#include<iostream>
#include<cstring>

using namespace std;
const int MAX_LENGTH=1001;


int main(){
	char sentence[MAX_LENGTH]={0};
	cin.getline(sentence, MAX_LENGTH);
	for(int i=0;i<strlen(sentence);i++){
		/*if((sentence[i]=='z'||sentence[i]=='Z')&&(sentence[i+1]=='e'||sentence[i+1]=='E')&&(sentence[i+2]=='r'||sentence[i+2]=='R')&&(sentence[i+3]=='o'||sentence[i+3]=='O')){
			cout<<0;
			i+=3;
		}
		else if((sentence[i]=='o'||sentence[i]=='O')&&(sentence[i+1]=='n'||sentence[i+1]=='N')&&(sentence[i+2]=='e'||sentence[i+2]=='E')){
			cout<<1;
			i+=2;
		}
		else if((sentence[i]=='t'||sentence[i]=='T')&&(sentence[i+1]=='w'||sentence[i+1]=='W')&&(sentence[i+2]=='o'||sentence[i+2]=='O')){
			cout<<2;
			i+=2;
		}
		else if((sentence[i]=='t'||sentence[i]=='T')&&(sentence[i+1]=='h'||sentence[i+1]=='H')&&(sentence[i+2]=='r'||sentence[i+2]=='R')&&(sentence[i+3]=='e'||sentence[i+3]=='E')&&(sentence[i+4]=='e'||sentence[i+4]=='E')){
			cout<<3;
			i+=4;
		}
		else if((sentence[i]=='f'||sentence[i]=='F')&&(sentence[i+1]=='o'||sentence[i+1]=='O')&&(sentence[i+2]=='u'||sentence[i+2]=='U')&&(sentence[i+3]=='r'||sentence[i+3]=='R')){
			cout<<4;
			i+=3;
		}
		else if((sentence[i]=='f'||sentence[i]=='F')&&(sentence[i+1]=='i'||sentence[i+1]=='I')&&(sentence[i+2]=='v'||sentence[i+2]=='V')&&(sentence[i+3]=='e'||sentence[i+3]=='E')){
			cout<<5;
			i+=3;
		}
		else if((sentence[i]=='s'||sentence[i]=='S')&&(sentence[i+1]=='i'||sentence[i+1]=='I')&&(sentence[i+2]=='x'||sentence[i+2]=='X')){
			cout<<6;
			i+=2;
		}
		else if((sentence[i]=='s'||sentence[i]=='S')&&(sentence[i+1]=='e'||sentence[i+1]=='E')&&(sentence[i+2]=='v'||sentence[i+2]=='V')&&(sentence[i+3]=='e'||sentence[i+3]=='E')&&(sentence[i+4]=='n'||sentence[i+4]=='N')){
			cout<<7;
			i+=4;
		}
		else if((sentence[i]=='e'||sentence[i]=='E')&&(sentence[i+1]=='i'||sentence[i+1]=='I')&&(sentence[i+2]=='g'||sentence[i+2]=='G')&&(sentence[i+3]=='h'||sentence[i+3]=='H')&&(sentence[i+4]=='t'||sentence[i+4]=='T')){
			cout<<8;
			i+=4;
		}
		else if((sentence[i]=='n'||sentence[i]=='N')&&(sentence[i+1]=='i'||sentence[i+1]=='I')&&(sentence[i+2]=='n'||sentence[i+2]=='N')&&(sentence[i+3]=='e'||sentence[i+3]=='E')){
			cout<<9;
			i+=3;
		}*/
		if(sentence[i]=='0'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"zero";
		}
		else if(sentence[i]=='1'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"one";
		}
		else if(sentence[i]=='2'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"two";
		}
		else if(sentence[i]=='3'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"three";
		}
		else if(sentence[i]=='4'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"four";
		}
		else if(sentence[i]=='5'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"five";
		}
		else if(sentence[i]=='6'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"six";
		}
		else if(sentence[i]=='7'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"seven";
		}
		else if(sentence[i]=='8'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"eight";
		}
		else if(sentence[i]=='9'&&(isspace(sentence[i-1])!=0||ispunct(sentence[i-1])!=0)&&(isspace(sentence[i+1])!=0||ispunct(sentence[i+1])!=0)){
			cout<<"nine";
		}
		else{
			cout<<sentence[i];
		}
	}
	
	
	
	return 0;
} 
