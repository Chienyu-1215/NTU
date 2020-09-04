#include<iostream>
  
using namespace std;
  
class Item
{
    private:
        int w;
        int num;
    public:
        Item();
        Item(int weight , int n);
        int getW();
        int getN();
};
  
Item::Item() : w(0), num(0)
{
}
  
Item::Item(int weight , int n) : w(weight), num(n)
{
}
  
int Item::getN()
{
    return this->num;
} 
  
int Item::getW()
{
    return this->w;
}
  
  
int main(){
    int n = 0 , B = 0;
    cin >> n >> B;
    Item** items = new Item* [n];
    for(int i = 0 ; i < n ; i++){
        int w = 0;
        cin >> w;
        items[i] = new Item(w , i + 1);
        /*for(int j = 0 ; j < i ; j++){
            if(items[i]->getW() < items[j]->getW()){
                Item* temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }*/
    }
    int** P = new int* [n];
    for(int i = 0 ; i < n ; i++){
        P[i] = new int[B + 1];
    }
    //Mark 0 for IMP, 1 for NS, 2 for S. 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < B + 1 ; j++){
            if(i == 0){
                if(j == items[i]->getW()){
                    P[i][j] = 2;
                }
                else if(j == 0){
                    P[i][j] = 1;
                }
                else{
                    P[i][j] = 0;
                }
            }
            else{
                if(P[i - 1][j] != 2){
                    P[i][j] = P[i - 1][j];
                }
                else{
                    P[i][j] = 1;
                }
                if((j - items[i]->getW()) >= 0 && P[i - 1][j - items[i]->getW()] != 0){
                    P[i][j] = 2;
                }
            }
        }
    }
/*  for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < B + 1 ; j++){
            cout << P[i][j] << " ";
        }
        cout << endl;
    }*/
    int* add = new int [n];
    int b = B, cnt = 0;
    if(P[n - 1][B] == 0){
        cout << 0;
    }
    else{
        for(int i = n - 1 ; i >= 0 ; i--){
            if(P[i][b] == 2){
                add[cnt] = items[i]->getN();
                cnt++;
                b -= items[i]->getW();
                if(b == 0){
                    break;
                }
            }
        }
        for(int i = 1 ; i < cnt ; i++){
            for(int j = 0 ; j < i ; j++){
              if(add[i] < add[j]){
                  int temp = add[i];
                  add[i] = add[j];
                  add[j] = temp;
               }
           }
       }
       for(int i = 0 ; i < cnt ; i++){
            if(i > 0){
                cout << ",";
            }
            cout << add[i];
        }
    }
      
      
      
      
      
      
    for(int i = 0 ; i < n ; i++){
        delete[] P[i];
        delete[] items[i];
    }
    delete[] P;
    delete[] items;
    return 0;
}
