#include<iostream>

using namespace std;
int game(int board[][3]);

int main(){
	int n=0;
	int board[3][3]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		if((i+1)%2==0){
			if(k%3!=0){
				board[k/3][k%3-1]=2;
			}
			else{
				board[k/3-1][2]=2;
			}
		}
		else{
			if(k%3!=0){
				board[k/3][k%3-1]=1;
			}
			else{
				board[k/3-1][2]=1;
			}
		}
	}
	int result=game(board);
	if(result==1){
		cout<<99;
		return 0;
	}
	int nextPlayer=1, win=0;
	if(n%2!=1){
		nextPlayer=2;
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]==0){
				board[i][j]=nextPlayer;
				win+=game(board);
				board[i][j]=0;
			}
		}
	}
	cout<<win;
	return 0;
	
	/*for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}*///ÀË¬d´Ñ½L 
	
	
	
	
}

int game(int board[][3]){
	for(int i=0;i<3;i++){
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]!=0){
			return 1;
		}
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[2][i]!=0){
			return 1;
		}
	}
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=0){
		return 1;
	}
	if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[0][2]!=0){
			return 1;
		}
	
	return 0;
	
	
}
	



