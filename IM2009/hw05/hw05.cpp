# include <iostream>
# include <vector>
# include <fstream> 
# include <string>


using namespace std;

int searchPattern(string target, string pattern){
	size_t found = target.find(pattern, 0);
	
	int count = 0;
	while(found != std::string::npos){
		count++;
		found = target.find(pattern , found + 1);
	}
	return count;
} 


int main(int argc, char* argv[]){
	int n = 0;
	ifstream fin(argv[1]);
	string p = "";
	int cnt = 0;
	vector<string> Ftable;
	Ftable.push_back("0");
	Ftable.push_back("1");
	while(Ftable.size() < 28){
		int cur = Ftable.size();
		Ftable.push_back(Ftable[cur - 1] + Ftable[cur - 2]);
	}
	
	while(fin >> n >> p){
		cnt++;
		
		vector<long long int> count;
		
		if(p == "0")
			count.push_back(1);
		else
			count.push_back(0);
		
		if(p == "1")
			count.push_back(1);
		else
			count.push_back(0);
			
		int m = p.length();	
		
		for(int i = 2 ; Ftable[i - 2].length() < m && i <= n ; i++){
			if(m > Ftable[i].length())
				count.push_back(0);
			else
				count.push_back(searchPattern(Ftable[i] , p));	
		}
		
		int p1, p2;
		
		if(count.size() <= n){
			string s1 = Ftable[count.size() - 1].substr(Ftable[count.size() - 1].length() - m + 1) +  Ftable[count.size() - 2].substr(0, m - 1);
			p1 = searchPattern(s1, p);
			string s2 = Ftable[count.size() - 2].substr(Ftable[count.size() - 2].length() - m + 1) +  Ftable[count.size() - 1].substr(0, m - 1);
			p2 = searchPattern(s2, p);
		}
		
		int a = count.size();
		for(int i = count.size() ; i <= n ; i++){
			if((i - a) % 2 == 0)
				count.push_back(count[i - 1] + count[i - 2] + p1);
			else
				count.push_back(count[i - 1] + count[i - 2] + p2);
		}
		
//		cout << count[n] << endl;
		cout << "Case " << cnt << ": " << count[n] << endl;
	}
	
	return 0;
} 
