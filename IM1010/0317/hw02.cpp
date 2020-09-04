#include <iostream>
#include <string>

using namespace std;



struct Data{
	bool gender;
	int totalw;//counting for total words
	int totals;//counting for total sentences
	float avg;
};


int main(){
	int n = 0 , m = 0;
	cin >> n >> m;
	Data* train = new Data[n]; // creating training data
	for(int i = 0 ; i < n ; i++){//initializing
		train[i].totals = 0;
		train[i].totalw = 1;
	}
	float max = 0;
	for(int i = 0 ; i < n ; i++){
		int g = 0;
		char x;
		cin >> g >> x;
		string s;
		getline(cin , s);
		train[i].gender = g - 1;
		for(int j = 0 ; j < s.length() ; j++){
			if(s[j] == ' ') {
				train[i].totalw++;
			}
			else if(s[j] == '?' || s[j] == '!' || (s[j] == '.' && (j == s.length() - 1 || s[j + 1] > 57 || s[j + 1] < 48)) ||  (s[j] == ',' && (j == s.length() - 1 || s[j + 1] > 57 || s[j + 1] < 48)) || s[j] ==';'){ //determining whether it's the end of a sentece
				train[i].totals++;
			}		
		}
		train[i].avg = static_cast<float>(train[i].totalw) / static_cast<float>(train[i].totals);//calculating average words per sentence
//		cout << train[i].avg<< endl;
		if(max < train[i].avg){
			max = train[i].avg;
		}
	}
	int minFalse = n + 1 , edge = 0; 
	for(int i = 0 ; i <= max ; i++){ // choosing the classifier that makes less errors
		int falseT = 0;
		for(int j = 0 ; j < n ; j++){
			if(train[j].gender == 0){
				if(train[j].avg >= i){
					falseT++;
				}
			}
			else{
				if(train[j].avg < i){
					falseT++;
				}
			}
		}
		if(falseT < minFalse){
			minFalse = falseT;
			edge = i;
		}
	}
	Data* valid = new Data [m]; // creating validation data
	int error = 0;
	for(int i = 0 ; i < m ; i++){
		valid[i].totals = 0;
		valid[i].totalw = 1;
		int g = 0;
		char x;
		cin >> g >> x;
		string s;
		getline(cin , s);
		valid[i].gender = g - 1;
		for(int j = 0 ; j < s.length() ; j++){
			if(s[j] == ' ') {
				valid[i].totalw++;
			}
			else if(s[j] == '?' || s[j] == '!' ||  (s[j] == '.' && (j == s.length() - 1 || s[j + 1] > 57 || s[j + 1] < 48)) ||  (s[j] == ',' && (j == s.length() - 1 || s[j + 1] > 57 || s[j + 1] < 48)) || s[j] ==';'){
				valid[i].totals++;
			}		
		}
		valid[i].avg = static_cast<float>(valid[i].totalw) / static_cast<float>(valid[i].totals);
		if(valid[i].gender == 0){
			if(valid[i].avg >= edge){
				error++;
			}
		}
		else{
			if(valid[i].avg < edge){
				error++;
			}
		}
	} 
	cout << edge << "," << error;
	

	
	
	
	
	return 0;
}
