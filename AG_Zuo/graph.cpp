/*
-图结构(番外：深拷贝问题，析构)
-BFS遍历
-dfs遍历
-图的拓扑排序
 测试链接：https://www.lintcode.com/problem/topological-sork'rukru
 解答文件：（三种方法还有一种点次方法个人感觉和深度方法差不多还不好懂，所以没写）
-最小生成树算法 
 -kruskal：针对无向图 考察权值由小到大的边，如果不行成环保留（贪心+并查集）
    测试链接：https://leetcode.cn/problems/min-cost-to-connect-all-points/
    解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/1584. 连接所有点的最小费用.cpp
 -prim(如何边的数量很多可能p算法优于k算法)
  测试链接：https://leetcode.cn/problems/connecting-cities-with-minimum-cost/
  解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/1135. 最低成本联通所有城市.cpp
 -djikstra:要求没有一个环路的累加和是负数
  -优化djkstra-> 加强堆
  -测试链接：https://leetcode.cn/problems/network-delay-time/
  解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/743. 网络延迟时间.cpp
*/
#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;
class Node;
class Edge{
public:
 int weight;
 Node * from;
 Node * to;
 Edge( int weight,Node* from,Node* to){
    this->weight=weight;
    this->from=from;
    this->to=to;
 }
 //深拷贝
 Edge(Edge& copy);
 ~Edge();
};
class Node {
  public:
   int in;//入度
   int out;//出度
   int val;
   vector<Node*> next;
   vector<Edge*>edges;
   Node(int val=0){
    in=0;
    out=0;
    this->val=val;
   }
   //深拷贝
   Node(const Node & copy){
    if(&copy!=this){
        this->in=copy.in;
        this->val=copy.val;
        this->out=copy.out;
        for(Node* it : copy.next){
        this->next.push_back(new Node(*it));
        }
        for(Edge* it:copy.edges){
            this->edges.push_back(new Edge(*it));
        }
    }
   }
  /* ~Node(){
    for(auto &it: next ){
        delete it;
    }
    for(auto &it: edges ){
        delete it;
    }
   }*/
};
Edge::Edge(Edge& copy){
    this->weight=copy.weight;
    this->from=new Node(*copy.from);
}
Edge::~Edge(){
    delete from;
    delete to;
 }
class Graph{
public:
  unordered_map<int, Node*>nodes;
  unordered_set<Edge*> edges;
  Graph(){

  };
  //深拷贝
  Graph(const Graph &copy){
     if(this!=&copy){
        this->nodes.clear();
        for(auto &it:copy.nodes){
            Node* newnode=new Node(*it.second);
            this->nodes[it.first]=newnode;
        }
        for(auto & it: copy.edges){
            this->edges.insert(new Edge(*it));
        }
    
     }
     
  }
  /*~Graph(){
        for(auto &it: nodes ){
        delete it.second;
    }
    for(auto &it: edges ){
        delete it;
    }
  }*/
};
//将图结构转换为自定义图结构
// matrix 所有的边
	// N*3 的矩阵
	// [weight, from节点上面的值，to节点上面的值]
	// 
	// [ 5 , 0 , 7]
	// [ 3 , 0,  1]
	// 
Graph  generateG(const vector<vector<int>>&matrix){
     int N=matrix.size();
     Graph newgraph=Graph();
     for(int i=0;i<N;i++){
        int from=matrix[i][0];
        int weight=matrix[i][1];
        int to=matrix[i][2];
         if(newgraph.nodes.find(from)==newgraph.nodes.end()){    
            Node* tmp=new Node(from);  
            newgraph.nodes[from]=tmp;
         }
         if(newgraph.nodes.find(to)==newgraph.nodes.end()){      
            newgraph.nodes[to]=new Node(to);
         }
         newgraph.nodes[from]->next.push_back(newgraph.nodes[to]);
         newgraph.nodes[from]->out++;
         newgraph.nodes[to]->in++;
         
         Edge* edgenew=new Edge(weight,newgraph.nodes[from],newgraph.nodes[to]);
         newgraph.edges.insert(edgenew);
         newgraph.nodes[from]->edges.push_back(edgenew);
         newgraph.nodes[to]->edges.push_back(edgenew);
     }
     return newgraph;
}

//广度优先遍历
void BFS( Graph & g){
    unordered_set<Node*>sets;
    queue<Node*> myqueue;
    if(g.nodes.empty())return;
    myqueue.push(g.nodes[1]);
    while(!myqueue.empty()){
        Node* cur=myqueue.front();
        myqueue.pop();
        cout<<"Node:"<<cur->val<<"-->";
        for(auto& it:cur->next){
            if(sets.find(it)==sets.end()){
              sets.insert(it);
              myqueue.push(it);
            }
        }
        //cout<<endl;
    }
    cout<<endl;
}
//DFS 深度优先遍历
void DFS( Graph & g){
stack<Node*> mystack;
unordered_set <Node*> sets;
mystack.push(g.nodes[2]);
while(!mystack.empty()){
    Node* cur=mystack.top();
    mystack.pop();
    if(sets.find(cur)==sets.end())
      cout<<cur->val<<"-->";
    sets.insert(cur);
    for(auto & it: cur->next){
       if(sets.find(it)==sets.end()){
         mystack.push(cur);
         sets.insert(it);
         mystack.push(it);  
         cout<<it->val<<"-->";
         break;//这里这样是因为图有可能有环，和树不一样，如果这里就把所有next压入栈会导致类似于这些结点已经visited影响了遍历顺序。
       }
    }

}
    cout<<endl;
}

int main(){
    vector<vector<int>> metrix={ 
        {1,2,3},
        {1,4,2},
        {2,9,3},
        {2,10,5}
    };
    Graph newg=generateG(metrix);
    BFS(newg);
    DFS(newg);
    return 0;
}