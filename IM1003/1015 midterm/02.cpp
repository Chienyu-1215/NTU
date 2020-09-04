#include<iostream>


using namespace std;


int main(){
	int board[7][7]={0};
	for(int i=1;i<=49;i++){
		int x,y;
		if(i%7!=0){
			x=i/7;
			y=i%7-1;
			board[x][y]=i;
		}
		else{
			x=i/7-1;
			y=6;
			board[x][y]=i;	
		}
	}
	int m, n;
	cin>>m>>n;
	int b1[49]={0}, b2[49]={0};
	for(int i=0;i<m;i++){
		cin>>b1[i];
	}
	for(int i=0;i<n;i++){
		cin>>b2[i];
	}
	for(int i=0;i<m;i++){
		int x,y;
		if(b1[i]%7!=0){
			x=b1[i]/7;
			y=b1[i]%7-1;
		}
		else{
			x=b1[i]/7-1;
			y=6;
		}
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				board[x+i][y+j]=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		int x,y;
		if(b2[i]%7!=0){
			x=b2[i]/7;
			y=b2[i]%7-1;
		}
		else{
			x=b2[i]/7-1;
			y=6;
		}
		for(int j=0;j<7;j++){
			board[x][j]=0;
			board[j][y]=0;
		}
	}
	/*for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}*///ÀË¬d´Ñ½L 
	int count=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			if(count!=0&&board[i][j]!=0){
				cout<<",";
			}
			if(board[i][j]!=0){
				cout<<board[i][j];
				count++;
			}
		}
	}
	if(count==0){
		cout<<0;
	}
	
}
