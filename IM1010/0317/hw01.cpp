#include <iostream>
#include <string>

using namespace std;



struct Data{
	bool gender;
	int totalw;
	int totals;
	float avg;
};


int main(){
	int n = 0 , m = 0;
	cin >> n >> m;
	Data* test = new Data[n];
	for(int i = 0 ; i < n ; i++){
		test[i].totals = 0;
		test[i].totalw = 1;
	}
	float max = 0;
	for(int i = 0 ; i < n ; i++){
		int g = 0;
		char x;
		cin >> g >> x;
		string s;
		getline(cin , s);
		test[i].gender = g - 1;
		for(int j = 0 ; j < s.length() ; j++){
			if(s[j] == ' ') {
				test[i].totalw++;
			}
			else if(s[j] == '?' || s[j] == '!' || s[j] == '.' || s[j] == ',' || s[j] ==';'){
				test[i].totals++;
			}		
		}
		test[i].avg = static_cast<float>(test[i].totalw) / static_cast<float>(test[i].totals);
//		cout << test[i].avg<< endl;
		if(max < test[i].avg){
			max = test[i].avg;
		}
	}
	int minFalse = n + 1 , edge = 0;
	for(int i = 0 ; i <= max ; i++){
		int falseT = 0;
		for(int j = 0 ; j < n ; j++){
			if(test[j].gender == 0){
				if(test[j].avg >= i){
					falseT++;
				}
			}
			else{
				if(test[j].avg < i){
					falseT++;
				}
			}
		}
		if(falseT < minFalse){
			minFalse = falseT;
			edge = i;
		}
	}
	Data* valid = new Data [m];
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
			else if(s[j] == '?' || s[j] == '!' || s[j] == '.' || s[j] == ',' || s[j] ==';'){
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
	

	
	
	delete[] test;
	delete[] valid;
	return 0;
}
