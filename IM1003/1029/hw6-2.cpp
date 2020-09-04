#include<iostream>


using namespace std;
const int MAX_N=100;
const int MAX_M=500;
void swap(int graph[][3], int i, int j);
int findSmaller(int vertex[][2], int graph[][3], int i);



int main(){
	int n, m, t;
	cin>>n>>m>>t;
	int edge[MAX_M][3]={0};
	for(int i=0;i<m;i++){
		cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
		int start=i;//排序Weight值 
		for(int j=i-1; j>=0;j--){
			if(edge[start][2]<edge[j][2]){
				swap(edge, start, j);
				start=j; 
			}
			else if(edge[start][2]==edge[j][2]&&(edge[start][0]+edge[start][1])<(edge[j][0]+edge[j][1])){
				swap(edge, start, j);
				start=j; 
			}
			else{
				break;
			}
		}
	}
	int totalWeight=0, st[MAX_M][2]={0};//spanning tree
	st[0][0]=edge[0][0];
	st[0][1]=edge[0][1];
	totalWeight+=edge[0][2];
	int vertex[MAX_N+1][2]={0};
	int set=1;
	int count=1;
	vertex[edge[0][0]][0]=1;
	vertex[edge[0][1]][0]=1;
	vertex[edge[0][0]][1]=1;
	vertex[edge[0][1]][1]=1;
	for(int i=1;i<m;i++){
		if(vertex[edge[i][0]][0]==0&&vertex[edge[i][1]][0]==0){//不屬於任何SET 
			st[count][0]=edge[i][0];
			st[count][1]=edge[i][1];
			totalWeight+=edge[i][2];
			count++;
			set++;
			vertex[edge[i][1]][0]=set;
			vertex[edge[i][0]][0]=set;
			vertex[edge[i][1]][1]++;
			vertex[edge[i][0]][1]++;
		}
		else if(vertex[edge[i][0]][0]==vertex[edge[i][1]][0]){//同SET 
			
		}
		else if(vertex[edge[i][0]][0]==0&&vertex[edge[i][1]][0]!=0&&vertex[edge[i][1]][1]<t){
			st[count][0]=edge[i][0];
			st[count][1]=edge[i][1];
			vertex[edge[i][1]][1]++;
			vertex[edge[i][0]][1]++;
			totalWeight+=edge[i][2];
			count++;
			vertex[edge[i][0]][0]=vertex[edge[i][1]][0];
			int correct=1;
			for(int j=1;j<=n;j++){
				if(vertex[j][0]!=1){
					correct=0;
					break;
				}
			}
			if(correct==1){
				break;
			}
		}
		else if(vertex[edge[i][1]][0]==0&&vertex[edge[i][0]][0]!=0&&vertex[edge[i][0]][1]<t){
			st[count][0]=edge[i][0];
			st[count][1]=edge[i][1];
			vertex[edge[i][1]][1]++;
			vertex[edge[i][0]][1]++;
			totalWeight+=edge[i][2];
			count++;
			vertex[edge[i][1]][0]=vertex[edge[i][0]][0];
			int correct=1;
			for(int j=1;j<=n;j++){
				if(vertex[j][0]!=1){
					correct=0;
					break;
				}
			}
			if(correct==1){
				break;
			}
		}
		else if(vertex[edge[i][0]][1]<t&&vertex[edge[i][1]][1]<t){
			int k=findSmaller(vertex, edge, i), t=0;
			st[count][0]=edge[i][0];
			st[count][1]=edge[i][1];
			count++;
			vertex[edge[i][1]][1]++;
			vertex[edge[i][0]][1]++;
			totalWeight+=edge[i][2];
			if(vertex[edge[i][0]][0]==k){
				t=vertex[edge[i][1]][0];
				vertex[edge[i][1]][0]=k;
				for(int a=1;a<=n;a++){
					if(vertex[a][0]==t){
						vertex[a][0]=k;
					}
				}
			}
			else{
				t=vertex[edge[i][0]][0];
				vertex[edge[i][0]][0]=k;
				for(int a=1;a<=n;a++){
					if(vertex[a][0]==t){
						vertex[a][0]=k;
					}
				}
			}
			int correct=1;
			for(int j=1;j<=n;j++){
				if(vertex[j][0]!=1){
					correct=0;
					break;
				}
			}
			if(correct==1){
				break;
			}	
		}
		
		
	}
	cout<<totalWeight<<endl;
	for(int i=0;i<count;i++){
		cout<<st[i][0]<<","<<st[i][1];
		if(i!=count-1){
			cout<<";";
		}
	}
	

	
	
	
	
	
	return 0;
}




void swap(int graph[][3],int i, int j){//交換陣列順序 
	int temp1=graph[j][0], temp2=graph[j][1], temp3=graph[j][2];
	graph[j][0]=graph[i][0];
	graph[j][1]=graph[i][1];
	graph[j][2]=graph[i][2];
	graph[i][0]=temp1;
	graph[i][1]=temp2;
	graph[i][2]=temp3;
}


int findSmaller(int vertex[][2], int graph[][3], int i){
	if(vertex[graph[i][0]][0]>vertex[graph[i][1]][0])
		return vertex[graph[i][1]][0];
	else 
		return vertex[graph[i][0]][0];
}
