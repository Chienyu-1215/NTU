#include<iostream>

using namespace std;
void setTransactions(int** trans , int* itemCnt , int m);

int main(){
	int n, m;
	float s;
	cin>>n>>m>>s;
	int** trans= new int*[m];
	int* itemCnt=new int[m];
	setTransactions(trans , itemCnt , m);
	/*for(int i=0;i<m;i++){
		for(int j=0;j<itemCnt[i];j++){
			cout<<trans[i][j]<<" ";
		}
		cout<<endl;
	}*///檢視交易資料
	int num=0;
	cin>>num;
	int* set=new int[num];
	for(int i=0;i<num;i++){
		cin>>set[i];
	} 
	int* support=new int[n];//support  
	for(int i=0;i<n;i++){
		support[i]=0;
	}
	for(int i=0; i<m;i++){
		int a=0,count=0;//a=第a項目, count=有幾個項目符合 
		for(int j=0;j<itemCnt[i];j++){//比較每個交易資料是否有含某消費者購買組合 
			if(trans[i][j]<set[a]&&a<num){

			}
			else if(set[a]==trans[i][j]&&a<num){
				a++;
				count++;
			}
			else if(set[a]<trans[i][j]&&a<num){
				a++;
			}
			else{
				
			} 
		}
		if(count==num){//代表本組資料具有指定消費者購買組合 
			for(int j=0;j<itemCnt[i];j++){
				support[trans[i][j]-1]++;//讓本資料每樣商品support+1 
			}
		}
	}
//	for(int i=0;i<n;i++){
//		cout<<support[i]<<" "<<conf[i]<<endl;
//	}
	int bestProduct=-1;
	float max=0;
	for(int i=0;i<n;i++){
		bool ok=1;
		for(int j=0;j<num;j++){
			if(i+1==set[j]){//判斷商品是否已在消費者購買組合中 
				ok=0;
				break;
			}
		}
		if(ok==0){
			continue;
		}
		else if(support[i]>=s*m){//比較support是否滿足s 
			if(static_cast<float>(support[i])/static_cast<float>(support[set[0]-1])>max){//比較confidence 
				max=static_cast<float>(support[i])/static_cast<float>(support[set[0]-1]);
				bestProduct=i;
			}
		}
	}
	if(bestProduct!=-1){
		cout<<bestProduct+1<<","<<support[bestProduct]<<","<<support[set[0]-1];
	}
	
	
	
	
	
	
	return 0;
} 

void setTransactions(int** trans , int* itemCnt , int m){
	for(int i=0;i<m;i++){
		int k=0;
		cin>>k;
		itemCnt[i]=k;
		trans[i]=new int[k];
		for(int j=0;j<k;j++){
			cin>>trans[i][j];
		}
	}
}
