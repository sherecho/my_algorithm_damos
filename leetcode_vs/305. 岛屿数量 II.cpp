#include<vector>
using namespace std;
class unionfind{
public:
  vector<int> parent;
  vector<int> rank;
  vector<int> helpstack;
  int sets;
  int col;
  int row;
  unionfind(int m,int n):parent(m*n),rank(m*n,0),helpstack(m*n),sets(0){
      int i=0;
  for(auto& it:parent){   
      it=i;
      i++;
      }  
      row=m;
      col=n;
  } 
  int findfirst(int index){
      int hel=0;
      while(parent[index]!=index){
      helpstack[hel++]=index;
      index=parent[index];
      }
      hel--;
      while(hel>=0){
          parent[helpstack[hel]]=index;
          hel--;
      }
      return index;
  }
  void union_set(int index1,int index2){
      if(rank[index1]==0||rank[index2]==0)
        return;
      int head1=findfirst(index1);
      int head2=findfirst(index2);
      if(head1==head2){
          return;
      }
      
      int big=rank[head1]>=rank[head2]? head1:head2;
      int low=rank[head1]>=rank[head2]? head2:head1;
      parent[low]=parent[big];
      rank[big]=rank[low]+rank[big];
      this->sets--;
    }
int connection(int x,int y) {
    int index=getindex(x,y);
    if(rank[index]==0){
        rank[index]=1;
        sets++;
    }
    else 
      return sets;
    //up
    if(x-1>=0){
        int index2=getindex(x-1, y);
        union_set(index, index2);
    }
    //down
    if(x+1<row){
        int index2=getindex(x+1,y);
        union_set(index,index2);
    }
    //left
    if(y-1>=0){
        int index2=getindex(x,y-1);
        union_set(index,index2);
    }
    //right
    if(y+1<col){
        int index2=getindex(x,y+1);
        union_set(index,index2);
    }
    return sets;
    
}
int getindex(int x,int y){
    return x*col+y;
}
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    unionfind u1=unionfind(m,n);
    vector<int> ret;
    for(auto& it:positions){
       ret.push_back(u1.connection(it[0], it[1]));
    }
    return ret;
    }
};