//深度优先搜索
#include<iostream>
#include <vector>
#include "stdlib.h"
using namespace std;
class pos{
    public:
    pos(int x,int y):x(x),y(y){

    }
   int x;
   int y;
};
bool check(vector<vector<int>> & map,int x,int y){
     //check left
     int nowx=x-1,nowy=y;
     while(nowx>=0&&nowy>=0&&nowx<map.size()&&nowy<map.size()){
         if(map[nowx][nowy]==-1)
         {
            return false;
         }
         if(map[nowx][nowy]==1){
            break;
         }
         nowx--;
     }
     //check right
     nowx=x+1;nowy=y;
     while(nowx>=0&&nowy>=0&&nowx<map.size()&&nowy<map.size()){
         if(map[nowx][nowy]==-1)
         {
            return false;
         }
         if(map[nowx][nowy]==1){
            break;
         }
         nowx++;
     }
     //down
     nowx=x;nowy=y-1;
     while(nowx>=0&&nowy>=0&&nowx<map.size()&&nowy<map.size()){
         if(map[nowx][nowy]==-1)
         {
            return false;
         }
         if(map[nowx][nowy]==1){
            break;
         }
         nowy--;
     }
     //up
     nowx=x;nowy=y+1;
     while(nowx>=0&&nowy>=0&&nowx<map.size()&&nowy<map.size()){
         if(map[nowx][nowy]==-1)
         {
            return false;
         }
         if(map[nowx][nowy]==1){
            break;
         }
         nowy++;
     }
     return true;
}
int  dfssub(vector<vector<int>> & map,vector<pos> &poses,int index,int count){
    if(index==poses.size())
       return count;
    int num_pos=count;
    int num_none_pos=count;
    //在x，y放置
     if(map[poses[index].x][poses[index].y]==0){
        
        if(check(map,poses[index].x,poses[index].y)){
            map[poses[index].x][poses[index].y]=-1;
            //cout<<"in"<<index<<"count"<<count+1<<endl;
            num_pos=dfssub(map,poses,index+1,count+1);
            //cout<<"index:"<<index<<"num_pos"<<num_pos<<endl;
            map[poses[index].x][poses[index].y]=0;
        }

     }
     num_none_pos=dfssub(map,poses,index+1,count);
     //cout<<"index:"<<index<<"num_pos_none"<<num_none_pos<<endl;
     return max(num_pos,num_none_pos);
}
int main(){
    int n;
    while(scanf("%d",&n)&&n!=0){
    vector<pos> poses;
    vector<vector<int>> map(n,vector<int>(n,0));
    vector<string> line(n);                                                                                                                                                                                                                                                                                                                  
    for(int i=0;i<n;i++){
        cin>>line[i];
        int j=0;
        for(auto c:line[i]){
            if(c=='.'){
              map[i][j]=0;
              }
            else
              map[i][j]=1;
            poses.push_back(pos(i,j));
            j++;     
        }
    }
    cout<<dfssub(map,poses,0,0)<<endl;
    }
    return 0;
}