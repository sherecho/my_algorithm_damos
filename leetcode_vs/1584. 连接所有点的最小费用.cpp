#include<vector>
#include<queue>
using namespace std;
class Edge{
 public:
   int from;
   int to;
   int dis;
   Edge(){
       ;
   }
   Edge(int f,int t,int d){
       from=f;
       to=t;
       dis=d;
   }
};
class unionfind{
  public:
  vector<int> parentnode;
  vector<int> rank;
  vector<int> mystack;

  unionfind(int N): parentnode(N),rank(N,0),mystack(N){
      for(int i=0;i<parentnode.size();i++){
          parentnode[i]=i;
      }
  }
  int findfirst(int node){
      int hel=0;
      while(parentnode[node]!=node){
          mystack[hel]=node;
          node=parentnode[node];
      }
      hel--;
      while(hel>=0){
          parentnode[mystack[hel--]]=node;

      }
      return node;
  }
  void unionset(int node1,int node2){
      int head1=findfirst(node1);
      int head2=findfirst(node2);
      if(head1==head2)
         return;
       int big=rank[head1]>rank[head2]?head1:head2;
       int low=rank[head1]>rank[head2]?head2:head1;
       parentnode[low]=big;
       rank[big]=rank[low]+rank[big];
  }
};
class comparator{
    public:
    bool operator()(Edge* A,Edge* B){
        return A->dis>B->dis;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ret=0;
      vector<Edge*> edgeset;
      for(int i=0;i<points.size();i++){
          for(int j=i+1;j<points.size();j++){
              int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
              Edge* newedge=new Edge(i,j,dis);
            edgeset.push_back(newedge);
          }
      }
      unionfind uset(points.size());
      priority_queue<Edge*,vector<Edge*>,comparator> minheap;
      for(auto & it : edgeset){
          minheap.push(it);
      }
      while(!minheap.empty()){
          Edge * cur=minheap.top();
          minheap.pop();
          if(uset.findfirst(cur->to)!=uset.findfirst(cur->from)){
            ret+=cur->dis;
            uset.unionset(cur->to,cur->from);
          }
      }
    return ret;
    }

    
};