#include <algorithm>
#include<vector>
#include<unordered_map>
#include<iostream>
#include<stack>
/*
-使用hashmap实现并查集并进行优化(路径压缩+按秩合并)
-省份数量问题
  https://leetcode.cn/problems/number-of-provinces/description/
 解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/547. 省份数量.cpp
-岛问题
 测试链接：https://leetcode.cn/problems/number-of-islands/
 解答文件:/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/200. 岛屿数量.cpp
-岛问题2 
 测试链接：https://leetcode.cn/problems/number-of-islands-ii/
 解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/305. 岛屿数量 II.cpp
*/
using namespace std;
struct Node{
    int val;
    Node(int val1=0){
        val=val1;
    }
};
class DisjSet{
    private:
    //vector<int> parent;
    //vector<int> rank;
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, int> rank;
    public:
    DisjSet(int size=0){
    for(int i=0;i<size;i++){
        Node* tmp=new Node(i);
       parent.insert(std::make_pair(tmp,tmp));
       rank.insert(std::make_pair(tmp,0));
    }
    }
    //路径压缩
    Node* findfirst(Node* cur){
    stack<Node*> nodeset;
    while (parent[cur]!=cur) {
      nodeset.push(parent[cur]);
      cur=parent[cur];
    }
    Node * ret=cur;
    while (!nodeset.empty()) {
        cur=nodeset.top();
        nodeset.pop();
        parent[cur]=ret;
    }
    return ret;

    }
    bool is_sameset(Node* a,Node* b){
       return findfirst(a)==findfirst(b);
    }
    void union_node(Node* a,Node * b){
        //按秩合并
        Node * head1=findfirst(a);
        Node* head2=findfirst(b);
        if(head1==head2)
          return ;
        Node * big=rank[head1]>=rank[head2]? head1:head2;
        Node * low=rank[head1]>=rank[head2]? head2:head1;
        rank[big]=rank[big]+rank[low];
        parent[low]=parent[big];
        auto it = parent.find(low);
        if (it != parent.end()) 
        // 使用迭代器删除键值对
        parent.erase(it);
        auto it2=rank.find(low);
        if(it2!=rank.end())
        rank.erase(low);
    }
};
int main(){

    return 0;
}