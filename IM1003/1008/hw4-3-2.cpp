#include<iostream>


using namespace std;
int findWinner(int board[][3]); 

int main(){
	int board[3][3]={0};
	int game=0, winner=0, gameSet=9;
	for(int i=1;i<=9;i++){
		int k=0;
		cin>>k;
		if((i%2)==0){
			if((k%3)!=0){
				board[k/3][k%3-1]=2;
			}
			else{
				board[k/3-1][2]=2;
			}
		}
		else{
			if((k%3)!=0){
				board[k/3][k%3-1]=1;
			}
			else{
				board[k/3-1][2]=1;
			}
		}
		if(i>=5){
			game=findWinner(board);
		}
		if(game==1){
			if(i%2==0){
				winner=2;
			}
			else{
				winner=i%2;
			}
			gameSet=i;
			break;
		}
		
	}
	cout<<winner<<" "<<gameSet;
	/*for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}*///ÀË¬d´Ñ½L 
	
	
	
	return 0;
}

int findWinner(int board[][3]){
	for(int i=0;i<3;i++){
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=0){
			return 1;
		}
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]!=0){
			return 1;
		}
		if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=0){
			return 1;
		}
		if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=0){
			return 1;
		}
	}
	return 0;



	return 0;
}
