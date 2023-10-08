#include<queue>
#include<vector>
using namespace std;
struct mydata {
    int p;
    int c;
    mydata(const int& a,const int& b){
        this->p=b;
        this->c=a;
    }
};
struct compar1{
    bool operator()(mydata & a,mydata& b)const{
        return a.c>b.c;
    }
};
struct compar2{
    bool operator()(mydata a,mydata b)const{
        return a.p<b.p;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       priority_queue<mydata,vector<mydata>,compar1> minheap;
       priority_queue<mydata ,vector<mydata>,compar2>maxheap;
       for(int i=0;i<capital.size();i++){
           minheap.push(mydata(capital[i],profits[i]));
       }  
       while(k>0){    
               while(!(minheap.empty())&&minheap.top().c<=w){                 
                   maxheap.push(minheap.top());
                   minheap.pop();
               }       
               if(maxheap.empty())
                 return w;
               else{           
                 w=w+maxheap.top().p; 
                 maxheap.pop();
                 k--;
                }
           } 
       return w;
    }
};