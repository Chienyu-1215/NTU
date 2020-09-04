#include<iostream>

using namespace std;
int findWinner(int board[][3]);

int main(){
	int board[3][3]={0};
	int k;
	int game=0;
	int winner=0,gameSet=9;
	for(int i=1;i<=9;i++){
		cin>>k;
		if(i%2==1){
			if(k%3!=0){
				board[k/3][k%3-1]=1;
			}
			else{
				board[k/3-1][2]=1;
			}
		}
		else{
			if(k%3!=0){
				board[k/3][k%3-1]=0;
			}
			else{
				board[k/3-1][2]=0;
			}
		}
		game=findWinner(board);
		if(game==1){
			if (i%2==1){
				winner=1;
				gameSet=i;
			}
			else{
				winner=2;
				gameSet=i;
			}
			break;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}
	cout<<winner<<" "<<gameSet;







	return 0;
} 


int findWinner(int board[][3]){
	for(int i=0;i<3;i++){
		if(board[i][0]==board[i][1]&&board[i][2]==board[i][1]){
			return 1;
		}
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]){
			return 1;
		}
		if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]){
		return 1;
	}
	}
	
	return 0;
	
}
