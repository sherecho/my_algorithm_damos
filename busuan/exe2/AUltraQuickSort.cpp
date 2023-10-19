#include<iostream>
#include<vector>
using namespace std;
void process(vector<int>& arr,int L,int R,int &count);
void mergesort(vector<int>& arr,int &count){
 if(arr.size()==0){
    return;
 }
   process(arr,0,arr.size()-1,count);
 }
void process(vector<int> &arr,int L,int R,int & count){
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
 while(len!=0){
    vector<int> arr(len,0);
    //cout<<"len  "<<len<<endl;
 for(int i=0;i<len;i++){
    cin>>arr[i];
 }
  int count=0;
  mergesort(arr,count);
  cout<<count<<endl;
  //cout<<"arr:"<<endl;
  // for(int i=0;i<len;i++){
  //   cout<<arr[i]<<endl;
  // }
 cin>>len;
 }
return 0;
}