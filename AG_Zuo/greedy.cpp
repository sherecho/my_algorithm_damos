/*贪心算法
-  返回所有可能的拼接结果中字典序最小的结果计算重组后可以得到的最小字符串
  https://developer.aliyun.com/article/846569
-用贪心算法返回最多会议室宣讲场次
-用贪心算法解决输入一个数组返回金条分割的最小代价
-IPO问题：https://leetcode.cn/problems/ipo/
  解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/502. IPO.cpp
  注意：这里要定义自己的结构体并多用引用代替传值调用，避免oj提交后超时。
-给定字符串str，返回点亮str中所有点亮的位置至少需要几盏灯
 https://blog.csdn.net/weixin_50337833/article/details/122497292
*/
#include <asm-generic/errno.h>
#include <cstddef>
#include <cstdlib>
#include <queue>
#include<string>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
#include <vector>
#include <set>
using namespace std;
struct CustomComparator {
    bool operator()(int a, int b) const {
        return a >b; 
    }
};

// 返回所有可能的拼接结果中字典序最小的结果
string generratestring(int len){
srand((unsigned)time(nullptr));
static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
string ret="";
int len0=rand()%len;
for(int i=0;i<len0;i++){
    int index=rand()%( sizeof(alphanum));
    ret+=alphanum[index];
}
    return ret;
}
vector<string> genrandomstrings(int len1,int len2){
   vector<string>ret;
   int len0=rand()%len1;
   for(int i=0;i<len0;i++){
    ret.push_back(generratestring(len2));
   }
   return ret;
}
bool mycompartor(string a,string b){
     return (a+b)<(b+a);
}
string less1(vector<string> randoms){
    string ret="";
    sort(randoms.begin(),randoms.end(),mycompartor);
    for(auto r:randoms){
       ret+=r;
    }
    return ret;
}
vector<string> removei(int index,vector<string>s){
    vector<string>ret;
    for(int i=0;i<s.size();i++){
        if (i!=index){
            ret.push_back(s[i]);
        }
    }
    return ret;
}
set<string> subtask(vector<string> randoms){
    set<string> ret;
    if(randoms.empty()){
       ret.insert("");
       return  ret;
    }
    for(int i=0;i<randoms.size();i++){
        string first=randoms[i];
        vector<string> next=removei(i, randoms);
        set<string>  nexts=subtask(next);
        for(auto n:nexts){
            ret.insert(first+n);
        }
    }
    return ret;
}
string less2(vector<string>randoms){
    if(randoms.empty()){
        return "";
    }
     set<string> treeset;
     treeset=subtask(randoms);
     return *treeset.begin();
}

//用贪心算法解决输入一个数组返回金条分割的最小代价
//贪心：哈夫曼编码法
int getless1(vector<int>arr){
    if(arr.empty())
      return 0;
   //优先级队列（小根堆）//程序语言默认的是大根堆
   //auto com=[](int a,int b){return a>b;};
   //priority_queue<int, vector<int>,decltype(com)>minheap(com);
   priority_queue<int, vector<int>,CustomComparator>minheap;
   for(auto it :arr){
    minheap.push(it);
   }
   //哈夫曼
   int cost=0;
   int sum=0;
   while (minheap.size()!=1) {
     int cur1=minheap.top();
     minheap.pop();
     int cur2=minheap.top();
     minheap.pop();
     minheap.push(cur1+cur2);
     cost=cur1+cur2;
     sum+=cost;
     //cout<<"sum "<<sum<<endl;
   }
   
    //sum+=minheap.top();
    //minheap.pop();
   return sum;
}
//暴力解法
vector<int> getnewarr(int i,int j,vector<int> arr){
    vector<int> ret;
    
    for(int index=0;index<arr.size();index++){
        if(index!=i&&index!=j){
            ret.push_back(arr[index]);
        }
    }
    ret.push_back(arr[i]+arr[j]);
    return ret;
}

int subtask2(vector<int> arr,int costpre){
     if(arr.size()==1)
      return costpre;
      int  costs=65535;
     for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            vector<int> arr2=getnewarr(i,j,arr);
            int c=subtask2(arr2,costpre+arr[i]+arr[j]);
            //cout<<"C"<<c;
            costs=min(costs,c);
            //cout<<"min:"<<costs<<endl;
        }
     }
     return costs;
}
int getless2(vector<int>arr){
    if(arr.empty())
      return 0;
    return subtask2(arr,0);
}
vector<int> generatearr(int len ,int max){
    int len0=rand()%len;
    vector<int> ret(len0);
    for(auto it=ret.begin();it!=ret.end();it++){
       *it=rand()%max;
    }
    return ret;
}
int main(){
    //测试 返回所有可能的拼接结果中字典序最小的结果
    /*
    int len1=10;
    int len2=20;

    for(int i=0;i<100;i++) {
         vector<string> s1=genrandomstrings(len1, len2);
         vector<string> s2=s1;  
         string r1=less1(s1) ;
         string r2=less2(s2);
         if(s1!=s2){
            cout<<"wrong";
            break;
         }          
    }
    cout<<"pass";
    */
    //测试输入一个数组返回金条分割的最小代价
    srand((unsigned)time(NULL));
    for(int i=0;i<150;i++){
    cout<<"round "<<i<<endl;
    
    vector<int> arr=generatearr(5, 100);
    // for(auto a:arr){
    //    cout<<a<<" ";
    // }
    // cout<<endl; 
    int cost1=getless1(arr);
    int cost2=getless2(arr);
    if(cost1!=cost2){
        cout<<"wrong"<<endl;
        cout<<cost1<<" "<<cost2<<endl;
        break;
    }
    }
    cout<<"pass";
    return 0;
}
