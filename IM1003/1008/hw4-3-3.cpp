#include<iostream>


using namespace std;
int findWinner(bool board[][3]); 

int main(){
	bool board[3][3]={0};
	int game=0, winner=0, gameSet=9;
	for(int i=1;i<=9;i++){
		int k=0;
		cin>>k;
		if((i%2)==0){
			if((k%3)!=0){
				board[k/3][k%3-1]=0;
			}
			else{
				board[k/3-1][2]=0;
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
		if(game==2&& i%2==0){
			winner=2;
			gameSet=i;
			break;
		}
		if(game==1){
			winner=1;
			gameSet=i;
			break;
		}
		
	}
	cout<<winner<<" "<<gameSet;
	
	
	return 0;
}

int findWinner(bool board[][3]){
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]==1){
		return 1;
	}
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]==0){
		return 2;
	}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]==1){
		return 1;
	}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]==0){
		return 2;
	}
	for(int i=0;i<3;i++){
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]==1){
			return 1;
		}
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]==0){
			return 2;
		}
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]==1){
			return 1;
		}
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]==0){
			return 2;
		}
	}
	return 0;

}
