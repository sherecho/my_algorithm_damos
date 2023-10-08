#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    while (!(N==0 && M==0&& K==0)) {
     vector<vector<int>> order(N,vector<int>(K,0));
     vector<vector<int>> storage(M,vector<int>(K,0));
     vector<vector<int>> cost(K,vector<int>(M,0));
     for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cin>>order[i][j];
        }
     }
     for(int i=0;i<M;i++){
        for(int j=0;j<K;j++){
            cin>>storage[i][j];
        }
     }
     for(int i=0;i<K;i++){
        for(int j=0;j<M;j++){
            cin>>cost[i][j];
        }
     }
    cin>>N>>M>>K;
    }
    
    return 0;
}