//可以通过oj的方法：
class Edge{
public:
  int from;
  int to;
  int dis;
  Edge(){

  }
  Edge(int f,int t,int d){
      from=f;
      to=t;
      dis=d;
  }
  };
  class compare{
   public:
    bool operator()(Edge * e1,Edge* e2){
       return e1->dis>e2->dis;
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
    vector<vector<Edge*>>G(n);
    for(auto & it:connections){
        G[it[0]-1].push_back(new Edge(it[0]-1,it[1]-1,it[2]));
        G[it[1]-1].push_back(new Edge(it[1]-1,it[0]-1,it[2]));
    }
   vector<bool> visited(n,false);
   priority_queue<Edge*,vector<Edge*>,compare>minheap;//最小堆找最短的路径
    int node=0;
    visited[0]=true;
    int sum=0;
    Edge *  minedge;
    for(auto & edge : G[0]){
       minheap.push(edge) ;
    }
    while(!minheap.empty()){
        minedge=minheap.top();
        minheap.pop();
        //解锁
        if(!visited[minedge->to]){
            visited[minedge->to]=true;
            for(auto & edge : G[minedge->to]){
                if(!visited[edge->to])
                  minheap.push(edge) ;
             } 
             sum+=minedge->dis;
        }
       
    }
    for(auto  b:visited){
       if(!b)
         return -1;
    }
    return sum;
    }
    
};





//内存超出限制，不建议使用
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
    int maxInt = std::numeric_limits<int>::max();
    //vector<vector<int>> dis(n,vector<int>(n,maxInt));
    int **dis=new int *[n];
    for(int i=0;i<n;i++){
        dis[i]=new int[n];
        std::fill(dis[i], dis[i]+ n,maxInt);
    }
   // 假设要赋的值是 10    
    for(int i=0;i<connections.size();i++){
        dis[connections[i][0]-1][connections[i][1]-1]=connections[i][2];
        dis[connections[i][1]-1][connections[i][0]-1]=connections[i][2];
    }
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int *dist2=new int[n];
    for(int i=0;i<n;i++){
        dist2[i]=dis[0][i];
    }
    visited[0]=true;
    int sum=0;
    
    for(int i=0;i<n;i++){
        int mindist=maxInt;
        int minindex=-1;      
        //解锁新的点
        for(int j=0;j<n;j++){
        if(!visited[j]&&dist2[j]<mindist){
            minindex=j;
            mindist=dist2[j];
        }
        }
        //解锁失败
        if(minindex==-1)
           break;
        //解锁成功
        sum+=mindist;
        visited[minindex]=true;
        //解锁新的距离
        for(int j=0;j<n;j++){
            if(!visited[j]&& dist2[j]>dis[minindex][j]){
                dist2[j]=dis[minindex][j];
            }
        }
    }
    for(int i=0;i<n ;i++){
        if(!visited[i]){
            for(int i=0;i<n;i++){
            delete []dis[i];
            }
          delete []dis;
          delete [] dist2;
          delete []visited;
          return -1;
        }
          
    }
       for(int i=0;i<n;i++){
        delete []dis[i];
       }
       delete []dis;
       delete [] dist2;
       delete []visited;
       return sum;
    }
};