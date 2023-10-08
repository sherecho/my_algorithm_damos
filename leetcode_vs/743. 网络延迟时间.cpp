#include<vector>
#include <limits.h>
using namespace std;
//不使用加强堆的版本dijkstra
class Edge{
    public:
  int from;
  int to;
  int dis;
  Edge(){

  }
  Edge(int f,int t ,int d ){
      from=f;
      to=t;
      dis=d;
  }
};
class compare{
public:
bool operator ()(Edge* a,Edge* b){
     return a->dis>b->dis;
}
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<bool> visited(n,false);
    vector<vector<Edge*>> G(n);
    for(auto & it:times){
        G[it[0]-1].push_back(new Edge(it[0],it[1],it[2]));
    }
    //priority_queue<Edge*,vector<Edge*>, compare> minheap;
    vector<int>dists(n,INT_MAX);
    for(auto & it:G[k-1]){
       dists[it->to-1]=it->dis;
    }
    dists[k-1]=0;
    visited[k-1]=true;
    int  i;
    for( i=0;i<n;i++){
        int mindis=INT_MAX;
        int minindex=-1;
        for(int j=0;j<n;j++){
            if(mindis>dists[j]&&!visited[j]){
                minindex =j;
                mindis=dists[j];
            }
        }
        if(minindex==-1)
          break;
        visited[minindex]=true;
        for(auto & it:G[minindex]){
            if(!visited[it->to-1]&&dists[it->to-1]>dists[minindex]+it->dis){
                dists[it->to-1]=dists[minindex]+it->dis;
            }
        }
    }
    if(i==n-1){
        int max0=-1;
        for(int k=0;k<n;k++){
           max0=max(max0,dists[k]);
        }
        return max0;
    }
    else 
    return -1;
    }
};

//使用加强堆的结题版本
struct datas{
    int vianode;
    int dis;
};
class heap{
    private:
    vector<datas*>heapvector;
    vector<int>indexs;
    int size;
    vector<bool> used;
    public:
    heap(){

    }
    heap(int N):heapvector(N),indexs(N,-1),used(N,false){

    }
};