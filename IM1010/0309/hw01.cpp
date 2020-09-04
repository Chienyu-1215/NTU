#include<iostream>
 
using namespace std;
 
 
struct Edge{
    int n1;
    int n2;
    int d;
};
 
struct Node{
    int dt;
    int Cnt;
    int k;
    bool found;
    int* edgesMark;
}; 
 
void distance(int n , Edge* e , Node* nd , int t);
 
int main(){
    int n = 0, m = 0;
    char x;
    cin >> n >> x >> m;
    Edge* e = new Edge [m];
    Node* nd = new Node [n + 1];
    for(int i = 1 ; i < n + 1 ; i++){
        nd[i].Cnt = 0;
        nd[i].k = 0;
        nd[i].found = 0;
        nd[i].dt = 100 * n;
    }
    for(int i = 0 ; i < m ; i++){
        cin >> e[i].n1 >> x >> e[i].n2 >> x >> e[i].d;
        nd[e[i].n1].Cnt++;
        nd[e[i].n2].Cnt++;
    }
    for(int i = 1 ; i < n + 1 ; i++){
        nd[i].edgesMark = new int [nd[i].Cnt];
    }
    for(int i = 0 ; i < m ; i++){
        nd[e[i].n1].edgesMark[nd[e[i].n1].k] = i;
        nd[e[i].n2].edgesMark[nd[e[i].n2].k] = i;
        nd[e[i].n1].k++;
        nd[e[i].n2].k++;
    }
    int target = 0 , s = 0;
    cin >> target >> x >> s;
    nd[target].dt = 0;
    nd[target].found = 1;
    distance(n , e , nd , target);
     
    int count = 0;
    nd[target].dt = s + 1;
    for(int i = 1 ; i < n + 1 ; i++){
        if(nd[i].dt <= s){
            if(count > 0){
                cout << ",";
            }
            cout << i;
            count++;
        }
    }
    if(count == 0){
        cout << "None";
    }
    delete[] nd;
    delete[] e; 
    return 0;
}
 
void distance(int n , Edge* e , Node* nd , int t){//t = target
    for(int i = 0 ; i < nd[t].Cnt ; i++){
        if(e[nd[t].edgesMark[i]].n1 == t){
            if(nd[e[nd[t].edgesMark[i]].n2].found == 1){
                continue;
            }
            else{
                if(nd[e[nd[t].edgesMark[i]].n2].dt > nd[t].dt + e[nd[t].edgesMark[i]].d){
                    nd[e[nd[t].edgesMark[i]].n2].dt = nd[t].dt + e[nd[t].edgesMark[i]].d;
                }
                else{
                    ;
                }
            }
        }
        else{
            if(nd[e[nd[t].edgesMark[i]].n1].found == 1){
                continue;
            }
            else{
                if(nd[e[nd[t].edgesMark[i]].n1].dt > nd[t].dt + e[nd[t].edgesMark[i]].d){
                    nd[e[nd[t].edgesMark[i]].n1].dt = nd[t].dt + e[nd[t].edgesMark[i]].d;
                }
                else{
                    ;
                }
            }
        }
    }
    int max = 100 * n;
    int newt = 0;
    for(int i = 1 ; i < n + 1 ; i++){
        if(nd[i].found != 1 && nd[i].dt <= max){
            max = nd[i].dt;
            newt = i;
        }
    }
    if(newt == 0){
        ;
    }
    else{
        nd[newt].found = 1;
        distance(n , e , nd , newt);
    }
     
}
