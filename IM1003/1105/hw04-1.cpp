#include<iostream>
#include<cstring>

const int MAX_LENGTH=1000;
using namespace std;

int main(){
	char sentence[MAX_LENGTH+1]={0};
	char* string= sentence;
	cin.getline (string, MAX_LENGTH);
	int sentenceCnt=1;
	for(int i=1;i<strlen(string)-1;i++){
		if(string[i]==','||string[i]=='.'||string[i]==';'||string[i]=='?'||string[i]=='!'||string[i]==':'){
			sentenceCnt++;
		} 
		else if(i==strlen(string)&&string[i]==' '){
			sentenceCnt++;
		}
	}
	int wordCnt=1;
	for(int i=1;i<strlen(string)-1;i++){	
		if((string[i]==','||string[i]=='.'||string[i]==';'||string[i]=='?'||string[i]=='!'||string[i]==':'||string[i]==' ')&&(string[i-1]!=','&&string[i-1]!='.'&&string[i-1]!=';'&&string[i-1]!='?'&&string[i-1]!='!'&&string[i-1]!=':'&&string[i-1]!=' ')){
			wordCnt++;
		}
		 
	}
	cout<<sentenceCnt<<","<<wordCnt/sentenceCnt;
	return 0;
}
 
