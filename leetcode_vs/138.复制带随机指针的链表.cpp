/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
// Definition for a Node0.

/*
class Node {
public:
    int val;
    Node* next;
    Node* random;    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};*/
#include<unordered_map>
using namespace std;
class Solution {
public:
//使用容器的做法
    Node* copyRandomList0(Node* head) {
    if(head==nullptr)
       return head;
    unordered_map <Node*,Node*> hashmap;
    Node * cur =head;
    while(cur!=nullptr){
        Node * key=new Node(cur->val);
        hashmap[cur]=key;
        cur=cur->next;
    }
    cur=head;
    while(cur!=nullptr){
    hashmap[cur]->next=hashmap[cur->next];
    hashmap[cur]->random=hashmap[cur->random];
    cur=cur->next;
    }
    return hashmap[head];
    }
//不使用容器的做法
    Node* copyRandomList(Node* head){
    Node * cur=head;
    if(head==nullptr){
        return nullptr;
    }
    //插入
    Node * tmp,* newnode;
    while(cur!=nullptr){
    tmp=cur->next;
    newnode=new Node(cur->val);
    cur->next= newnode;
    newnode->next=tmp;
    cur=tmp;
    }
    //连接random 
    cur=head;   
    while(cur!=nullptr){ 
       cur->next->random=cur->random!=nullptr? cur->random->next : nullptr;
       cur=cur->next->next;
    }
    //建链表
    cur=head;
    Node * nextnext;
    Node * newhead=head->next;
    while(cur!=nullptr){
      nextnext = cur->next->next;
      cur->next->next= (nextnext!=nullptr)? nextnext->next:nullptr;
      cur->next=nextnext;
      cur=nextnext;
    }
    return newhead;
 }
};
// @lc code=end

