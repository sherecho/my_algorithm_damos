#include <cstddef>
#include<iostream>
#include<vector>
#include"time.h"
#include "stdlib.h"
using namespace std;

void process(vector<int>& arr,int L,int R,long long &count);
void mergesort2(vector<int>& arr,long long &count){
 if(arr.size()==1){
    return;
 }
   process(arr,0,arr.size()-1,count);
 }
void mergesort(vector<int>& arr,long long &count){
 if(arr.size()==1){
    return;
 }
   process(arr,1,arr.size()-1,count);
 }
void process(vector<int> &arr,int L,int R,long long & count){
      if(L>=R)
         return;
      int mid=L+((R-L)/2);
      process(arr,L,mid,count);
      process(arr,mid+1,R,count);
      vector<int> tmp(R-L+1,0);
      int p1=L;
      int p2=mid+1;
      int i=0;
      while(p1<=mid&&p2<=R){
        if(arr[p1]<=arr[p2]){
            tmp[i]=arr[p1];
            p1++;
        }
        else{
            tmp[i]=arr[p2]; 
            count+=(mid-p1+1);
            p2++;      
        }
        i++;
      }
      while(p1<=mid){
        tmp[i++]=arr[p1++];
      }
      while(p2<=R){
        tmp[i++]=arr[p2++];
      }
      for(int i=0;i<tmp.size();i++){
        arr[i+L]=tmp[i];
      }
 }

int main(){
 int len;
  cin>>len;
 srand((unsigned)(NULL));
 while(len>0){
    len--;
    vector<int> arrorigin(len,0);
    vector<int>arrcopy(len,0);
    vector<int> arr(len+1,0);
 for(int i=1;i<len+1;i++){
    // cin>>arr[i];
    // cin>>arrcopy[i-1];
    arr[i]=rand()%10+1;
    arrorigin[i-1]=arr[i];
    arrcopy[i-1]=arr[i];
 }
  long long cnt=0,cnt2=0;
  mergesort(arr,cnt);
  mergesort2(arrorigin,cnt2);
  if(cnt!=cnt2){
    cout<<"error"<<endl;
    cout<<cnt2<<endl;
    cout<<cnt;
    cout<<"arr:"<<endl;
    for (auto a:arrcopy){
      cout<<a<<endl;
    }
    cnt=0;

    break;
  }
  // cout<<cnt<<endl;
  // cin>>len;
 }
return 0;
}