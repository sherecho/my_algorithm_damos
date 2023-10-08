#include<vector>
using namespace std;
class unionfind{
 private:
  int* parent;
  int* rank;
  int* helpstack;
  int col0;
  int row0;
  
 public:
  int sets;
  unionfind(vector<vector<char>>& grid){
   int row=grid.size();
   sets=0;
   int col= row>0? grid[0].size():0;   
   row0=row;
   col0=col;
   parent=new int[row*col];//.resize(row*col);
   rank=new int[row*col];//.resize(row*col);
   helpstack=new int[row*col];//.resize(row*col);
   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
           if(grid[i][j]=='1'){
               int index=i*col+j;
               parent[index]=index;
               rank[index]=1;
               sets++;
           }
       }
   }
  }
  ~unionfind(){
      delete []parent;
      delete []rank;
      delete [] helpstack;
  }
  int findfirst(int index){
      int hel=0;
      while(parent[index]!=index){
          helpstack[hel++]=index;
          index=parent[index];
      }
      hel--;
      while(hel>=0){
          int ind2=helpstack[hel];
          hel--;
          parent[ind2]=index;
      }
      return index;
  }
  void union_set(int index1 ,int index2){
      int head1=findfirst(index1);
      int head2=findfirst(index2);
      if(head1==head2)
      return;
      int big=rank[head1]>=rank[head2]?head1:head2;
      int low=rank[head1]>=rank[head2]?head2:head1;
      parent[low]=big;
      rank[big]=rank[low]+rank[big];
      sets--;
  }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=row>0? grid[0].size():0;
        unionfind u1=unionfind(grid);
        for(int i=0;i<col-1;i++){
           int right=i+1;
           if(grid[row-1][i]=='1'&&grid[row-1][right]=='1'){
               u1.union_set((row-1)*col+i, (row-1)*col+right);
           }           
        }
        for(int i=0;i<row-1;i++){
            int down=i+1;
            if(grid[i][col-1]=='1'&&grid[down][col-1]=='1'){
                int index1=i*col+col-1;
                int index2=down*col+col-1;
                u1.union_set(index1, index2);
            }
        }
        for(int i=0;i<row-1;i++){
            for(int j=0;j<col-1;j++){
                //right
               if(grid[i][j]=='1'&&grid[i][j+1]=='1'){
                 int index1=i*col+j;
                 int index2=(i)*col+j+1;
                 u1.union_set(index1, index2);
               }
               //down
               if(grid[i][j]=='1'&&grid[i+1][j]=='1'){
                 int index1=i*col+j;
                 int index2=(i+1)*col+j;
                 u1.union_set(index1, index2);
               }
            }
        }
        return u1.sets;
    }
};