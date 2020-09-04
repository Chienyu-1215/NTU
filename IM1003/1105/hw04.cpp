#include<iostream>
#include<cstring>

const int MAX_LENGTH=1000;
using namespace std;

int main(){
	char sentence[MAX_LENGTH+1]={0};
	char* string= sentence;
	cin.getline (string, MAX_LENGTH);
	char* string1=new char[strlen(string)];
	char* string2=new char[strlen(string)];
	strcpy(string1,string);
	strcpy(string2,string);
	int sentenceCnt=0;
	char* end=",.:;!?";
	char* space=" "; 
	int i=0, totalWord=0;
	char* p1=strtok(string1, end);
	while(p1!=nullptr){
		i++;
		p1=strtok(nullptr, end); 
	}
	char* p2=strtok(string2, space);
	while(p2!=nullptr){
		totalWord++;
		p2=strtok(nullptr, space); 
	}
	cout<<i<<","<<totalWord/i;
	return 0;
}
 
