#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct storedata{
    public:
    int cost;
    int storeid;
    int amount;
    storedata(int c,int s,int a){
        cost=c;
        storeid=s;
        amount=a;
    }
    storedata(){

    }
};
struct comp{
    bool operator ()(const storedata &a,const storedata &b){
    return a.cost>b.cost;
    }
};
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    while (!(N==0 && M==0&& K==0)) {
     vector<vector<int>> order(N,vector<int>(K,0));
     vector<vector<int>> storage(M,vector<int>(K,0));
     vector<vector<vector<int>>> cost(K,vector<vector<int>>(N,vector<int>(M,0))); 
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
     for(int k=0;k<K;k++){
     for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>cost[k][i][j];
        }
     }
     }
    //solve:
    int rs=0;
    for(int shop=0;shop<N;shop++){
        //cout<<"shop"<<shop<<endl;
     for(int kind=0;kind<K;kind++){
        // cout<<"kind: "<<kind<<endl;
         int need=order[shop][kind];
         priority_queue<storedata,vector<storedata>,comp> minheap;
      
         for(int store=0;store<M;store++){
             if(storage[store][kind]!=0){
                storedata newdata(cost[kind][shop][store],store,storage[store][kind]);
                minheap.push(newdata);
             }
         }
         storedata curchoice;
         while (need!=0&&rs!=-1) {
            if(!minheap.empty()){
                curchoice=minheap.top();
                minheap.pop();
             if( need>curchoice.amount) {

                need-=curchoice.amount;
                rs+=curchoice.cost*curchoice.amount;
                curchoice.amount=0;
                
             }
             else{
                curchoice.amount-=need;
                rs+=curchoice.cost*need;
                need=0;
             }
             storage[curchoice.storeid][kind] = curchoice.amount;
            if(curchoice.amount!=0)
               minheap.push(curchoice);
            }
            else {
             rs=-1;
            }
            //cout<<"rs tmp"<<rs<<" ";
            
         } 
         if (rs==-1){
            break;
         }
     }
     if(rs==-1){
        break;
     }
    }
   
    cout<<rs<<endl;
    cin>>N>>M>>K;
    }   
    return 0;
}