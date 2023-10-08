/*
两种方法： BFS 1,DFS 2
*/
#include <algorithm>
#include <random>
#include <unordered_set>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
//Definition for Directed graph.
    struct DirectedGraphNode {
      int label;
      vector<DirectedGraphNode *> neighbors;
      DirectedGraphNode(int x) : label(x) {};
  };
 
//方法1：BFS方法：统计每个点的入度，从没有入度的点开始，每次去除该点对其它点入度的影响，选择下一个没有入度的点以此类推进行排序
class Solution1 {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> ret;
        unordered_map <DirectedGraphNode*,int> innodes;
        for(auto &it:graph){
            innodes[it]=0;
        }
        //统计入度
        for(auto &it:graph){
            for(auto & next:it->neighbors){
                innodes[next]++;
            }
        }
        //将0度入队
        queue<DirectedGraphNode*>myqueue;
        for(auto & it:innodes){
            if(it.second==0){
                myqueue.push(it.first);
            }
        }
        while (!myqueue.empty()) {
            DirectedGraphNode* cur;
            cur=myqueue.front();
            ret.push_back(cur);
            myqueue.pop();
            //消除影响 //重新找入队的点
            for(auto& it:cur->neighbors){
                innodes[it]--;
                if(innodes[it]==0)
                 myqueue.push(it);
            }
           
            
        }
        return ret;
    }

};
//方法2： DFS
//记录每个结点的深度，并以此来排序。借助动态规划的记录思想
class record{
    public:
int deep;
DirectedGraphNode * node;
record (int d,DirectedGraphNode* n){
    deep=d;
    node=n;
}
record (){
    ;
}
};
bool comparator(record a,record b){
        return a.deep>b.deep;
};
class Solution2 {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
  vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
       unordered_map <DirectedGraphNode*,record>order;
       //遍历图结点求deep
        for(auto& it:graph){
            cal(it,order);
        }
        vector<record> arr;
        for(auto & it:order){
            arr.push_back(it.second);
        }
        sort(arr.begin(),arr.end(),comparator);
        vector<DirectedGraphNode*>ret;
        for(auto & it:arr){
            ret.push_back(it.node);
        }
    return ret;
 }
record cal(DirectedGraphNode* node,unordered_map<DirectedGraphNode*,record> &order){
      if(order.find(node)!=order.end()){
        return order[node];
      }
      int d=0;
      for( auto &it: node->neighbors){
        record r=cal(it,order);
        d=max(d,r.deep);
      }
      order[node]=record(d+1,node);
      return order[node] ;
}
};


