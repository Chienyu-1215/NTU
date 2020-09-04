#include<iostream>


using namespace std;
const int MAX_V=500;


int main(){
	int V, A;
	cin>>V>>A;
	int graph[MAX_V+1][MAX_V+1]={0};
	for(int i=0;i<A;i++){
		int a,b;
		cin>>a>>b;
		graph[a][b]=1;
		graph[b][a]=1;
	}
	int m, exist=0, cycle=0;
	int degree[MAX_V+1]={0};
	cin>>m;
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		if(graph[a][b]!=0){
			graph[a][b]++;
			graph[b][a]++;
			exist++;
			degree[a]++;
			degree[b]++;
		}
	}
//	for(int i=1;i<=V;i++){
//		cout<<degree[i];
//	}
	for(int i = 1; i <= V ; i++){
		for(int j = 1; j <= V;j++){
			if(graph[i][j] > 0)
				graph[i][j]--;
		}
	}
	if(exist!=m){
		cout<<0;
		return 0;
	}
	else{
		for(int a=1;a<=V;a++){
			for(int i=1;i<=V;i++){
				if(degree[i]==1){
					degree[i]=0;
					for(int j = 1; j <= V; j++){
						if(graph[j][i] > 0){
							degree[j]--;
							graph[j][i] = 0;
							graph[i][j] = 0;
						}	
					}
				}
			}
		}
	}
	for(int j = 1; j <= V; j++){
		if(degree[j] > 0){
			cout<<1;
			return 0;
		}
	}
	cout<<2;
	return 0;
}
