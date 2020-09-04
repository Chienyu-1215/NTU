#include<iostream>
#include<string>


using namespace std;

class Data
{
	private:
		int cnt;
		bool** adj;
		int* work;
		int* worker;
	public:
		Data(int n);
		void add(int who , int what);
		int bipartite_matching();
		bool DFS(int s , bool* visited);
		int greedy_matching();
		~Data();
};

Data::Data(int n)
{
	cnt = n;
	adj = new bool* [this->cnt];
	work = new int[this->cnt];
	worker = new int[this->cnt];
	
	for(int i = 0 ; i < this->cnt ; i++){
		this->adj[i] = new bool [this->cnt];
		for(int j = 0 ; j < this->cnt ; j++){
			this->adj[i][j] = false;
		}
		this->work[i] = -1;
		this->worker[i] = -1;
	}
}

void Data::add(int who , int what)
{
	adj[who][what] = true;	
}

int Data::greedy_matching()
{
	int done = 0;
	for(int i = 0 ; i < this->cnt ; i++){
		if(this->worker[i] == -1){
			for(int j = 0 ; j < this->cnt ; j++){
				if(this->work[j] == -1 && this->adj[i][j] == true){
					this->worker[i] = j;
					this->work[j] = i;
					done++;
					break;
				}
			}
		}
	}
	return done;
}

int Data::bipartite_matching()
{
	int done = greedy_matching();
	if(done == this->cnt){
		return done;
	}
	bool* visited = new bool [this->cnt];
	
	for(int i = 0 ; i < this->cnt ; i++){
		if(this->worker[i] == -1){
			for(int j = 0 ; j < this->cnt ; j++){
				visited[j] = false;
			}
			if(DFS(i , visited)){
				done++;
			} 		
		}
	}
	delete[] visited;
	return done;
}

bool Data::DFS(int s , bool* visited)
{
	for(int i = 0 ; i < this->cnt ; i++){
		if(this->adj[s][i] == true && visited[i] != true){
			visited[i] = true;
			if(work[i] == -1 || DFS(work[i] , visited)){
				this->worker[s] = i;
				this->work[i] = s;
				return true;
			}
		}
	}
	return false;
}

Data::~Data()
{
	delete[] work;
	delete[] worker;
	for(int i = 0 ; i < this->cnt ; i++){
		delete[] adj[i];
	}
	delete[] adj;
}

int main(){
	string input; 
	getline(cin , input);
	int n = stoi(input);
	Data data(n);
	getline(cin , input);
	int curN = 0 , start = 0 , length = 0;
    for(int i = 0 ; i < input.length() ; i++){
        length++;
        if(input[i] == ';'){
        	int todowork = stoi(input.substr(start , length - 1)) - 1;
        	data.add(curN , todowork);
            curN ++;
            length = 0;
            start = i + 1;
        }
        else if(input[i] == ','){
            int todowork = stoi(input.substr(start , length - 1)) - 1;
        	data.add(curN , todowork);
            length = 0;
            start = i + 1;
        }
        else{
            continue;
        }
    }
	
	cout << data.bipartite_matching() << endl;
	
	return 0;
} 
