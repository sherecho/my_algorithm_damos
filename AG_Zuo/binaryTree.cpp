#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include<stack>
#include<queue>
#include <string>
#include<cstdlib>
#include<unordered_map>
using namespace std;
/*
- 完全二叉树插入leetcode919：https://leetcode.cn/problems/complete-binary-tree-inserter/
-遍历
   -非递归先序遍历-栈（一个队列无法实现）
   -非递归中序遍历
   -非递归后序遍历（两个栈）
   -层次遍历（队列实现）
   -二叉树序列化和反序列化
    * 二叉树可以通过先序、后序或者按层遍历的方式序列化和反序列化，
     * 但是，二叉树无法通过中序遍历的方式实现序列化和反序列化
     * 因为不同的两棵树，可能得到同样的中序序列，即便补了空位置也可能一样。
     * 比如如下两棵树
     *         __2
     *        /
     *       1
     *       和
     *       1__
     *          \
     *           2
     * 补足空位置的中序遍历结果都是{ null, 1, null, 2, null}
    -将多叉树变成唯一二叉树并序列化，可以反序列化还原多叉树：
      https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree
      解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\431. 将 N 叉树编码为二叉树.cpp
    -如何设计打印整棵树的函数（不常考调试用）
    -求二叉树最宽的层有多少结点
    -求中继节点：https://blog.csdn.net/qq_51654808/article/details/127109139
    -折纸问题：
    *请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，压出折痕后展开。此时 折痕是凹下去的，即折
    *痕突起的方向指向纸条的背面。如果从纸条的下边向上方连续对折2 次，压出折痕后展开，此时有三条折痕，从上
    *到下依次是下折痕、下折痕和上折痕。
     给定一 个输入参数N，代表纸条都从下边向上方连续对折N次，请从上到下打印所有折痕的方向 例如：N=1时，打
     印： down；N=2时，打印： down down up
  -如何判断二叉树是否为完全二叉树
   leetcode:https://leetcode.cn/problems/check-completeness-of-a-binary-tree/
   解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\958.二叉树的完全性检验.cpp
  -平衡二叉树：所有子树满足左树最大高度与右树最大高度相差不超过1
    -判断二叉树是否为平衡二叉树： https://leetcode.cn/problems/balanced-binary-tree/
    解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\110.平衡二叉树.cpp
  -判断二叉树是否为搜索二叉树：搜索二叉树：每一个子树左边都小于头节点，右边都大于头节点就是搜索二叉树
   https://leetcode.cn/problems/validate-binary-search-tree/
   （方法1：满足中序遍历序列是递增的就是搜索二叉树)
   （方法2：递归）
   解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\98.验证二叉搜索树.cpp
  -二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点
   https://leetcode.cn/problems/diameter-of-binary-tree/
  解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\543.二叉树的直径.cpp
 -给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小。其中，最大指的是子树节点数最多的。
  https://leetcode.cn/problems/largest-bst-subtree/
  解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\333. 最大 BST 子树.cpp
-给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
  https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
  解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\236.二叉树的最近公共祖先.cpp
-派对快乐最大值
https://www.nowcoder.com/practice/a5f542742fe24181b28f7d5b82e2e49a?tpId=101&tqId=33255&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking&tab=answerKey
解答文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\CD187最快乐派对.cpp
*/
class Node {
    public:
    Node(int vals){
    val=vals;
    left=nullptr;
    right=nullptr;
    }
    friend class Binary_Tree;
    int val;
    Node * left;
    Node * right;

};
class Binary_Tree{
    public:
     Binary_Tree(Node * head=nullptr){
      this->root=head;
      queue<Node*>tmpQueue;
    //TreeNode *cur=root;
    if(root!=nullptr){
    tmpQueue.push(root);
    while(!tmpQueue.empty()){
       Node * cur=tmpQueue.front();
        tmpQueue.pop();
        //从左到右的顺序找不满的结点
        if(cur->left!=nullptr)
            tmpQueue.push(cur->left);
        if(cur->right!=nullptr)
            tmpQueue.push(cur->right);
        //将不满的结点存储
        if(!((cur->left!=nullptr)&&(cur->right!=nullptr)))
           candidate.push(cur);
    }
    }
    }
     
     void addnode1(int val,int dir){
        Node * newnode=new Node(val);
        if(root==nullptr){
           root=newnode;
           return;
        }
       if(dir==0){
         Node * cur=root;
         while (cur->left!=nullptr) {
         cur=cur->left;
         }
         cur->left=newnode;
       }
       else{
        Node * cur=root;
        while(cur->right!=nullptr){
        cur=cur->right;
        }     
       }
       return;
     }
     //完全二叉树插入
    int CBTinsert(int val) {
     
     Node * newchild=new Node(val);
     int ret;
     
     if (root==nullptr){
        ret=-1;
        root=newchild;
     }
     else{
      Node * parent=candidate.front();
      ret=parent->val;
     if(parent->left==nullptr)
       parent->left=newchild;
     else{
        parent->right=newchild;
        candidate.pop();
     }  
     }   
     //candidate.pop();//错的
     candidate.push(newchild);
     return ret;
    }  
    Node* get_root() {
    return root;
    } 
    
    //非递归先序遍历 根左右
      //栈实现：
       void pre_stack(){
        stack<Node*> mystack;
        mystack.push(root);
        cout<<"pre_stack: ";
        while (!mystack.empty()) {
        Node* cur=mystack.top();
        mystack.pop();
        if(cur->right!=nullptr)
          mystack.push(cur->right);
        if(cur->left!=nullptr)
          mystack.push(cur->left);  
          cout<<cur->val<<" ";     
        }
        cout<<endl;
       }
      //队列实现：这个是错的，先序遍历无法只用一个队列实现。队列比较容易进行层次遍历，但是不利于实现这种深度优先的类型
      /*
       void pre_queue(){
        queue<Node*> myqueue;
        myqueue.push(root);
        cout<<"pre_queue: ";
        while (!myqueue.empty()) {
        Node* cur=myqueue.front();
        myqueue.pop();
        if(cur->left!=nullptr)
          myqueue.push(cur->left);
        if(cur->right!=nullptr)
          myqueue.push(cur->right);     
          cout<<cur->val;     
        }
        cout<<endl;
       }*/
    
    //非递归中序遍历：栈实现 左根右
    void mid_stack(){
        cout<<"mid stack:";
        if (root==nullptr)
           return;
        Node * cur=root;
        stack<Node*>mystack;
        while(!mystack.empty()||cur!=nullptr){
        if(cur!=nullptr){
          mystack.push(cur);
          cur=cur->left;
        }  
        else{
        cur=mystack.top();
        mystack.pop();
        cout<<cur->val<<" ";
        cur=cur->right;
        }
       
        }
         cout<<endl;
    } 
    //非递归后序遍历：两个栈实现 左右根(也可以用一个栈实现)
    void post_stack(){
    cout<<"post_Stack :";
    if(root==nullptr)
        return;
    stack<Node*> s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty()){
    Node * cur;
    cur=s1.top();
    s1.pop();
    s2.push(cur);    
    if(cur->left!=nullptr)
       s1.push(cur->left); 
    if(cur->right!=nullptr)
       s1.push(cur->right);
 
    }
    while(!s2.empty()){
      Node * cur=s2.top();
      s2.pop();
      cout<<cur->val<<" ";
    }
    cout<<endl;
    }
    void level(){
        queue<Node*> myqueue;
        cout<<"level:";
        if(root==nullptr)
          return;
        myqueue.push(root);
        while(!myqueue.empty()){
            Node* cur=myqueue.front();
            myqueue.pop();
            if(cur->left!=nullptr)
              myqueue.push(cur->left);
            if(cur->right!=nullptr)
              myqueue.push(cur->right);
            cout<<cur->val<<" ";
        }
        cout<<endl;
    }
    //序列化与反序列化
    //按照先序序列化反序列化
    queue<string> preserial(){
        queue<string> ret;
        stack<Node*> mystack;
        if(root==NULL){
          ret.push("#");}
        else{
           mystack.push(root);
           while(!mystack.empty()){
            Node * cur=mystack.top();
            mystack.pop();      
            if(cur!=nullptr){
            mystack.push(cur->right);         
            mystack.push(cur->left);
            ret.push(std::to_string(cur->val));   }
            else{
                ret.push("#");
            }

           }           
        }    
        return ret;    
    }
    //反序列化
    void reverse_preserial(queue<string> serial){
        string cur;     
        cur=serial.front();
        serial.pop();
        if(cur=="#"){
           root=nullptr;
           return;}
        stack<Node*>mystack;
        root=new Node(atoi(cur.c_str()));
        mystack.push(root);
        Node *curnode=root;
        int flag=0;
        while(!serial.empty()){
        cur=serial.front();
        serial.pop();
        if(flag==0){
        if(cur!="#"){
         curnode->left=new Node(atoi(cur.c_str()));
         curnode=curnode->left; 
         mystack.push(curnode); 
        }
        else{
            flag=1;
            if(!mystack.empty()){
            curnode=mystack.top();
            mystack.pop();  
            }
        }
        }
        else {        
        if(cur=="#"){
            if(!mystack.empty()){
            curnode=mystack.top();
            mystack.pop(); 
            }
        }
        else{
        curnode->right=new Node(atoi(cur.c_str()));
        curnode=curnode->right; 
        mystack.push(curnode);
        flag=0;
        }
        }
        }
    }
    //后序遍历序列化
     queue<string> postserial(){
     queue<string> ret;
     stack<Node*>mystack1;
     stack<Node*>mystack2;
     if(root==nullptr){
        ret.push("#");
     }
     else{
        mystack1.push(root);
        Node* cur=root;
        while (!mystack1.empty()) {
        cur=mystack1.top();
        mystack1.pop();
        mystack2.push(cur);
        if(cur!=nullptr){
        mystack1.push(cur->left);    
        mystack1.push(cur->right);   
        }
        
     }
     while(!mystack2.empty()){
          cur=mystack2.top();
          mystack2.pop();
          if(cur!=nullptr)
          ret.push(to_string(cur->val));
          else
           ret.push("#");
     }  
     }
       return ret;
     }
    //后序反序列化
    //首先用一个栈就能变成类似先序的形式：左右头-》头右左
    void reverse_postserial(queue<string> serial){
    stack<string> reverse;
    string cur;
    //逆序
    while(!serial.empty()){
      reverse.push(serial.front());
      serial.pop();
    } 
    cur=reverse.top();  
    reverse.pop();
     if(cur=="#"){
        root=NULL;
        return;
    }

    Node * curnode=new Node(atoi(cur.c_str()));
    root=curnode;
    stack<Node*>mystack;
    mystack.push(root);
    int flag=0;
    while (!reverse.empty()) {
    cur=reverse.top();
    reverse.pop();
    if(flag==0){
      if(cur!="#"){
      curnode->right=new Node(atoi(cur.c_str()));   
      curnode=curnode->right; 
      mystack.push(curnode);
      }
      else{
        flag=1;
        if(!mystack.empty()){
           curnode=mystack.top();  
           mystack.pop();
        }    
      }   
    }
    else{
    if(cur!="#"){
      curnode->left=new Node(atoi(cur.c_str()));
      curnode=curnode->left;
      mystack.push(curnode);
      flag=0;
    }
    else{
     if(!mystack.empty()){
        curnode=mystack.top();
        mystack.pop();
     }
    }
    }
    }
    }
    //层次遍历序列化
    queue<string> level_serial(){
        queue<string> ret;
        queue<Node*> myqueue;
        if(root==nullptr){
            ret.push("#");
        }
        else{
        Node * curnode=root;
        myqueue.push(curnode);
        while(!myqueue.empty()){
          curnode=myqueue.front();
          myqueue.pop();
          if(curnode!=nullptr){
          ret.push(to_string(curnode->val));         
          myqueue.push(curnode->left);
          myqueue.push(curnode->right);
          }
          else       
            ret.push("#");     
        }    
        }
        return ret;
    }
    //层次遍历反序列化
    void  reverse_level_serial(queue<string>serial){
     string cur;
     cur=serial.front();
     if(cur=="#")
       root=nullptr;
    else{
       serial.pop();
       Node * curnode;
       root=new Node(atoi(cur.c_str()));
       queue<Node*> myqueue;
       myqueue.push(root);
       while (!serial.empty()) {
       curnode=myqueue.front();
       myqueue.pop();
       cur=serial.front();
       serial.pop();
       if(cur!="#"){
        curnode->left=new Node(atoi(cur.c_str()));
        myqueue.push(curnode->left);
       }   
       cur=serial.front();
       serial.pop();
       if(cur!="#"){
        curnode->right=new Node(atoi(cur.c_str()));
        myqueue.push(curnode->right);
       }       
       }
    }
    }
    //print
    std::string getSpace(int num) {
    std::string space = " ";
    std::string result = "";
    for (int i = 0; i < num; i++) {
        result += space;
    }
    return result;
    }
    void printInOrder(Node * head,int height,string to,int len){
       if(head==nullptr)
        return; 
        printInOrder(head->right,height+1, "v", len);
        string val=to+to_string(head->val)+to;
        int lenM=val.length();
        int lenL=(len-lenM)/2;
        int lenR=len-lenM-lenL;
        val=getSpace(len*height)+getSpace(lenL)+val+getSpace(lenR);
        cout<<val<<endl;
        printInOrder(head->left, height+1, "^", len);

    }
    void printTree(){
        cout<<"Binary Tree: ";
        printInOrder(root, 0, "H", 17);
        cout<<endl;
    }
    //求二叉树宽度
     //简答的方法（笔试用）
     int getmaxwidth_hash(){
        unordered_map<Node*, int> hashmap;
        Node * cur=root;
        hashmap[root]=1;
        int width=0;
        int maxwidth=1;
        queue<Node*> myqueue;
        myqueue.push(root);
        int curheight=1;
        while(!myqueue.empty()){
           cur=myqueue.front();
           myqueue.pop();
           if(hashmap[cur]==curheight)
              width++;
          else{
            width=1;
            curheight=hashmap[cur];           
          }
           if(cur->left!=nullptr) {
            myqueue.push(cur->left);
            hashmap[cur->left]=hashmap[cur]+1;
           }
           if(cur->right!=nullptr){
            myqueue.push(cur->right);
            hashmap[cur->right]=hashmap[cur]+1;
           }
           if(width>maxwidth)
               maxwidth=width;
        }
        return maxwidth;
     }
     //较为困难的方法
     int getmaxwidth(){
        queue<Node*> myqueue;
        Node * cur,*curNodeEnd,*nextNodeEnd;
        if(root==nullptr)
            return 0;
        myqueue.push(root);
        curNodeEnd=root;
        int width=0;
        int maxwidth=0;
        while(!myqueue.empty()){
            cur=myqueue.front();
            myqueue.pop();
            if(cur->left!=nullptr){
                myqueue.push(cur->left);
                nextNodeEnd=cur->left;
            }
            if(cur->right!=nullptr){
                myqueue.push(cur->right);
                nextNodeEnd=cur->right;
            }
            width++;
            if(cur==curNodeEnd){
               maxwidth=width>maxwidth?width:maxwidth;
               width=0;
               curNodeEnd=nextNodeEnd;
            }
        }
        maxwidth=width>maxwidth?width:maxwidth;
        return  maxwidth;
     }

    private:
     Node* root;
     queue<Node*>candidate;


};
//折纸问题
void process(int N,int level,bool du){
  if(level>N)
     return;
  process(N,level+1,true);
  string t=du?"down":"up";
  cout<<t<<" ";
  process(N,level+1,false);
}
void solve_paper(int N){
cout<<"paper"<<N<<endl;
process(N,1,true);
cout<<endl;
}
int main(){
    Binary_Tree B1;
    for(int i=10;i<1000;i++){
        int tmp=B1.CBTinsert(i);
    } 
    B1.pre_stack();
    B1.mid_stack();
    B1.post_stack();
    B1.level();
    /*Binary_Tree B2;
    queue<string> ret=B1.level_serial();
    B2.reverse_level_serial(ret);
    B2.pre_stack();
    B2.mid_stack();
    B2.post_stack();
    B2.printTree();*/
    int width=B1.getmaxwidth_hash();
    cout<<"hash widh:"<<width<<endl;
    int width2=B1.getmaxwidth();
    cout<<"widh:"<<width2<<endl;
    solve_paper(3);
    return 0;
}