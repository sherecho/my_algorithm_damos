#include <cmath>
#include <cstddef>
#include <cstdlib>
#include<iostream>
#include <ostream>
#include<stack>
#include"time.h"
#include "stdlib.h"
#include <set>
#include<cmath>
using namespace std;
/*快慢指针
 -单链表：求链表中点1奇数个返回唯一中点，2偶数个返回上中点，3偶数个返回下中点 4奇数个返回中点前一个
 - 给定一个单链表头节点head ，请判断该链表是否为回文结构
   -用容器的方法（笔试用）：用栈
   -该原链表方法-(快慢指针找中点+反转链表)
 -修改链表顺序：例如L1L2L3L4R1R2R3R4->将该链表修改为L1R1L2R3L3R3L4R4
 -将单向链表划分为左边小中间相等右边大的形式
   -把链表放数组，对数组partition（笔试用）
   -分成大中小，在串起来（申请六个指针-》大中小三个链表的头尾节点，最后三个链表首尾相连）
 -拷贝带random的链表：
    leetode 138题 : https://leetcode.com/problems/copy-list-with-random-pointer/
    -方法一：使用hashmap
    -方法二：调链表
解答程序文件：E:\desktop\CS_STUDY\DataS_AG\AG_PROJECT_CPLUS\leetcode_vs\138.复制带随机指针的链表.cpp
 -给定两个可能有环也可能无环的单链表，头节点head1和head2
  请实现一个函数，如果两个链表相交，请返回相交的第一个节点。如果不相交返回null 
  要求如果两个链表长度之和为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1)
  -问题拆解：
   -1.给定一个链表如果链表无环返回空，如果有环返回第一个入环的节点
    -容器的办法
    -非容器的办法

 -能不能不给单链表的头节点，只给想要删除的节点，就能做到在链表上把这个点删掉？
*/
class SNode{
public:
int val;
SNode * next;
SNode(int val=0);
};
SNode::SNode(int val)
{
    this->val=val;
    this->next=nullptr;
}
class linklist{
public:
    //SNode *head;
    linklist(int val=0):length(1),circle(-1){
    head=new SNode(val);
    }
    ~linklist(){
        SNode* tmp;
        //无环的析构
        /*
        while (head!=nullptr) {
        tmp=head->next;
        delete head;
        head=tmp;
        }*/
        //有环的析构
        set<SNode*> sets;
        SNode * cur=head;
        while(cur!=nullptr){
          if(sets.find(cur)==sets.end()){           
             sets.insert(cur);
             delete cur;
             }
          else {
          break;
          }
        }
    }
    void headpush(int val){
        SNode * newnode=new SNode(val);
        newnode->next=this->head->next;
        this->head->next=newnode;
        length++;
    }
    void tailAddNode(SNode * node){
      SNode *tail,*cur;
      cur=this->head;
      while (cur!=nullptr) {
      tail=cur;
      cur=cur->next;
      }
      tail->next=node;
      length++;
    }
    SNode*  getNode(int n){
    SNode *cur=this->head;
    if(n>length)
      return nullptr;
    while (n>0) {
    cur=cur->next;
    n--;
    }
    return cur;
    }
    //随机制造环
    void ramdomcreatcircle(){
    srand((time(nullptr)));
    circle= rand()%length;
    SNode * cur=head,*tail=head;
    int tmp=circle;
    while(tmp>0){
      cur=cur->next;
      tmp--;
    }
    while(tail->next!=nullptr){
      tail=tail->next;
    }
    tail->next=cur;
    }
    int getmid(){
    if(head==nullptr)
    return 65535;

    if(this->head->next==nullptr){
        return this->head->val;
    }
    SNode * fast;
    SNode * slow;
    fast=head;
    slow=head;
    //当链表为奇数返回中点,当链表为偶数时返回前中点
    //if(length>1){
    while(fast->next!=nullptr){
        if(fast->next->next==nullptr)
           break;
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->val;
    //}  
    } 
    void printlist(){
        SNode * cur;
        cur=head;
        cout<<"list: ";
        while(cur!=nullptr){
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    //判断是否为回文数链表
    //1.使用栈容器，空间复杂度O(N) N额外空间
    bool ispalindrom_stack(){
    stack<int> tmpstack;
    SNode * cur=head;
    while(cur!=nullptr){
         tmpstack.push(cur->val);
         cur=cur->next;
    }
    cur=head;
    while(cur!=nullptr){
    int val=tmpstack.top();
    tmpstack.pop();
    if(val!=cur->val){
        return false;
    }
    cur=cur->next;
    }
    return true;
    }
    //2.空间复杂度为O(1)
    bool ispalidrom(){
        SNode * fast,*slow;
        fast=head;
        slow=head;
        while(fast->next!=nullptr){
            if(fast->next->next==nullptr)
              break;
            fast=fast->next->next;
            slow=slow->next;
        }
        SNode * pre=slow->next;
        //反转链表    
        SNode * cur=pre->next;
        SNode * curnext;
        pre->next=nullptr;
        while (cur!=nullptr) {
        curnext=cur->next;
        cur->next=pre;
        pre=cur;
        cur=curnext;
        }
        cur=pre;
        SNode *cur2=head;
       //对比
       bool flag=true;
       while(cur2!=nullptr&&cur!=nullptr){
        if(cur->val!=cur2->val){
        flag= false;
        break;
        }
        cur=cur->next;
        cur2=cur2->next;
       }
       //恢复链表
       cur=pre->next;
       pre->next=nullptr;
       while (cur!=nullptr) {
          curnext=cur->next;
          cur->next=pre;
          pre=cur;
          cur=curnext;
       }
       slow->next=pre;
       return  flag;
    }
    //修改链表顺序：例如L1L2L3L4R1R2R3R4->将该链表修改为L1R4L2R3L3R2L4R1
    void cross(){
      SNode * fast,* slow;
      fast=head;
      slow=head;
      while(fast->next!=nullptr){
        if(fast->next->next==nullptr)
          break;
        fast=fast->next->next;
        slow=slow->next;
      }  
      SNode * pre =slow->next;
      SNode* cur=pre->next;
      pre->next=nullptr;
      slow->next=nullptr;
      SNode * curnext;
      //反转链表
      while(cur!=nullptr){
      curnext=cur->next;
      cur->next=pre;
      pre=cur;
      cur=curnext;
      }
      //重连链表
      cur=pre;
      SNode * cur2=head;
      SNode *cur2next;
      while(cur!=nullptr&&cur2!=nullptr){
      cur2next=cur2->next;
      curnext=cur->next;
      cur2->next=cur;
      cur2=cur2next;
      if(cur2==nullptr)
         break;
      cur->next=cur2next;
      cur=curnext;   
      }
  
    }
    //将单向链表划分为左边小中间相等右边大的形式
    void partion(int val){
      SNode * minhead,*mintail,*midhead,*midtail,*maxhead,*maxtail,*cur;
      midhead=nullptr;
      midtail=nullptr;
      mintail=nullptr;
      minhead=nullptr;
      maxhead=nullptr;
      maxtail=nullptr;
      cur=head;
      //划分
      while(cur!=nullptr){
      if(cur->val<val){
      if(minhead==nullptr){
        minhead=cur;       
        mintail=cur;    
      }
      else{
      mintail->next=cur;
      mintail=mintail->next;
      }
      cur=cur->next;
      mintail->next=nullptr;    

      }
      else if (cur->val==val) {
      if(midhead==NULL){
        midhead=cur;
        midtail=cur;
      }
      else{
        midtail->next=cur;
        midtail=midtail->next;
      }
      cur=cur->next;
      midtail->next=nullptr;
      }
      else{
        if(maxhead==nullptr){
          maxhead=cur;
          maxtail=cur;
        }
        else {
        maxtail->next=cur;
        maxtail=maxtail->next;
        }
        cur=cur->next;
        maxtail->next=nullptr;
      }
      }
      //串联
      mintail->next=midhead;
      midtail->next=maxhead;
      head=minhead;
    }
    
    //给定一个链表如果链表无环返回空，如果有环返回第一个入环的节点
    //1. 使用容器
    SNode * getcirclepos_set(){
    set<SNode*> myset;
    SNode * cur=head;
    while(cur!=nullptr){
      if(myset.find(cur)==myset.end())
         myset.insert(cur);
      else
        break;
      cur=cur->next;
    }
    return cur;
    }
    //2.不使用容器
    SNode * getcirclepos(){
    SNode * fast,*slow;
    SNode * cur=head;
    fast=head;
    slow=head;
    while(fast->next!=nullptr){
    if(fast->next->next==nullptr)
      break;
    fast=fast->next->next;
    slow=slow->next;
    if(slow==fast)
      break;
    }
    if(fast->next==nullptr)
      return nullptr;
    if(fast->next->next==nullptr)
       return nullptr;
    fast=head;
    while(fast!=slow){
      fast=fast->next;
      slow=slow->next;
    }
    return fast;
    }

    //返回两个链表相交结点（友元函数）
    /*
    问题分析：
    两链表可能存在的状态： 
    - 1 都是无环的链表       - 2一个链表无环，一个链表有环  -3 两个链表都有环
      A.  |    B.| |              无交点          (入环   C.     D.  |    |   E 入环节点一样
          /\     | |                              节点    |   |     /_ _ _\        \/_ _ _
         /  \    | |                              不一样) |   |     |      |        |_ _ |
如果末尾节点不是同一个-》无交点，否则有交点                  /_\ /_\    \_ _ _/
                                                          无交点       有交点         有交点
    */
    friend SNode * FindIntersectNode(linklist& list1,linklist & list2) ;//这里要用引用是因为我没有写拷贝构造函数
private:
    int length;
    SNode *head;
    int circle;
};
SNode * FindIntersectNode(linklist & list1,linklist & list2) {
   //找环
   SNode * node1,*node2;
   node1=list1.getcirclepos();
   node2=list2.getcirclepos();
   //A，B
   if(node1==nullptr&&node2==nullptr){
    SNode * cur1,*pre1;
    cur1=list1.head;
    pre1=nullptr;
    while (cur1!=nullptr) {
    pre1=cur1;
    cur1=cur1->next;
    }
    SNode * cur2,*pre2;
    cur2=list2.head;
    pre2=nullptr;
    while (cur2!=nullptr) {
    pre2=cur2;
    cur2=cur2->next;
    }
    //情况B
    if(pre1!=pre2)
      return nullptr;
    else{//情况A
    int lengthdif=abs(list1.length-list2.length);
    cur1=list1.length>list2.length?list1.head:list2.head;
    cur2=list1.length>list2.length?list2.head:list1.head;
    while (lengthdif>0) {
    cur1=cur1->next;
    lengthdif--;
    }
    while (cur1!=nullptr) {
    if(cur1==cur2)
       return cur1;
    cur1=cur1->next;
    cur2=cur2->next;
    }
    }
   }
   //2情况
   if(node1==nullptr&&node2!=nullptr)
      return nullptr;
   if(node1!=nullptr&&node2==nullptr)
      return nullptr;
   //C,D
   if(node1!=node2){
   SNode * cur1=node1->next;
   while (cur1!=node1) {
    if(cur1==node2)
       return node1;//D
    cur1=cur1->next;
   }
   //C
   return nullptr;
   }
   //E
   SNode * cur1,*cur2;
   cur1=list1.head;
   cur2=list2.head;
   int n=0;
   while(cur1!=node1){
   n++;
   cur1=cur1->next;
   }
   while(cur2!=node2){
    n--;
    cur2=cur2->next;
   }
   cur1=n>0? list1.head:list2.head;
   cur2=n>0? list2.head:list1.head;
   n=abs(n);
   while (n>0) {
   cur1=cur1->next;
   n--;
   }
   while (cur1!=cur2) {
   cur1=cur1->next;
   cur2=cur2->next;
   }
   return cur1;

}
int main(){
 //linklist list1(0);
 //test mid
 /*
 int length=11;
 int max=100;
 srand((unsigned int)(time(NULL)));
 for(int i=0;i<length;i++){
 int val=rand()%max;
 list1.headpush(val);
 }  
 list1.printlist();
 int mid=list1.getmid();
 cout<<"mid:"<<mid<<endl;*/
//test 回文串
/*
for(int i=0;i<13;i++){
    list1.headpush(i);
}
for(int i=9;i>0;i--){
    list1.headpush(i);
}
list1.printlist();*/
/*
cout<<"stack:  ";
if(list1.ispalindrom_stack())
  cout<<"True"<<endl;
else
 cout<<"false"<<endl;
cout<<"nonstack:  ";
if(list1.ispalidrom())
  cout<<"True"<<endl;
else
 cout<<"false"<<endl;
list1.printlist();
 cout<<"cross: ";
list1.cross();
list1.printlist();
cout<<"partion: ";
list1.partion(5);
list1.printlist();*/
//环
/*
list1.ramdomcreatcircle();
SNode * result;
result=list1.getcirclepos_set();
cout<<"circle:"<<result->val<<endl;
result=list1.getcirclepos();
cout<<"circle2:"<<result->val<<endl;
*/
//测试交点
linklist  c1;
linklist  c2;
for(int i=0;i<13;i++){
    c1.headpush(i);
}
for(int i=17;i<26;i++){
    c2.headpush(i);
}
//test B

SNode * result1;
result1=FindIntersectNode(c1,c2);

//test A
/*
SNode * intersec=c1.getNode(2);
c2.tailAddNode(intersec);
result1=FindIntersectNode(c1,c2);
cout<<"c1:";
c1.printlist();
cout<<"c2 :";
c2.printlist();
cout<<"result1: "<<result1->val<<endl;

//test 情况2
linklist c3;
linklist c4;
for(int i=0;i<13;i++){
    c3.headpush(i);
}
for(int i=17;i<26;i++){
    c4.headpush(i);
}
c3.ramdomcreatcircle();
result1=FindIntersectNode(c3, c4);
if(result1==nullptr)
    cout<<"True"<<endl;
else
    cout<<"False"<<endl; 

//test C
c4.ramdomcreatcircle();
result1=FindIntersectNode(c3, c4);
if(result1==nullptr)
    cout<<"True"<<endl;
else
    cout<<"False"<<endl; 
//test D
linklist c5;
linklist c6;
for(int i=0;i<13;i++){
    c5.headpush(i);
}
for(int i=17;i<26;i++){
    c6.headpush(i);
}
c5.ramdomcreatcircle();
SNode *circle=c5.getcirclepos();
c6.tailAddNode(circle->next);
result1=FindIntersectNode(c5,c6);
SNode *circle2=c6.getcirclepos();
cout<<"result1: "<<result1->val<<endl;
cout<<"circle1: "<<circle->val<<endl;
cout<<"circle2: "<<circle2->val<<endl;*/
//testE
linklist c5;
linklist c6;
for(int i=0;i<13;i++){
    c5.headpush(i);
}
for(int i=17;i<26;i++){
    c6.headpush(i);
}
c5.ramdomcreatcircle();
SNode *circle=c5.getcirclepos();
c6.tailAddNode(circle);
result1=FindIntersectNode(c5, c6);
cout<<"circlr: "<<circle->val<<endl;
cout<<"result :";
cout<<result1->val<<endl;
return 0; 
}
