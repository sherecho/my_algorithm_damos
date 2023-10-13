/**
 * @Author: wz
 * @date: 2023-07-16 
 * @last_edit_time: 2023-07-20 
 * @description: 十大排序算法
 */
#include <iostream>
#include <utility>
#include<vector>
#include "time.h"
#include "stdlib.h"
#include <algorithm>
#include<cmath>
using namespace std;
#define base 10
void swap(int &a,int& b){
  int tmp=a;
  a=b;
  b=tmp;
}
void PRINTARR(vector<int> & arr)
{
  for(auto i:arr){
    cout<<" "<<i;
  }
  cout<<endl;
}
//基于比较的排序
// 1.冒泡排序
void Bubblesort (vector<int> & arr){
int len=arr.size();
if(len<2)
   return;
for(int i=0;i<len-1;i++){
  bool flag=false;
  for(int j=0;j<len-1-i;j++){
    
    if(arr[j]>arr[j+1]){
      swap(arr[j],arr[j+1]);
    
      flag=true;
    }
}
    if(!flag){
      break;
    }
}
}
//2 选择排序
void selectsort(vector<int> &arr){
  int len=arr.size();
  if(arr.size()<2)
    return;
  int minindex;
  for(int i=0;i<len;i++){
    minindex=i;
     for(int j=i+1;j<len;j++){
        if(arr[j]<arr[minindex]){
          minindex=j;
        }
     }
     swap(arr[i],arr[minindex]);
  }

}
//3 插入排序
void insertsort(vector<int> &arr){
  int len=arr.size();    
  if(arr.size()<2)
    return;

  for(int i=1;i<len;i++){
      if(arr[i]<arr[i-1]){
          int tmp=arr[i];
          int j=i-1;
          while(j>=0&&arr[j]>tmp){
            arr[j+1]=arr[j];
            j--;
          }
          arr[j+1]=tmp;
      }
         
  }

}
//4 快排递归版本
void part(vector<int>&arr,int L,int R){
  if(L>=R)
     return;

  int randomind=rand()%(R-L+1)+L;
  //swap(arr[R],arr[randomind]);
  int mid =arr[randomind];
  int min=L-1;
  int max=R+1;
  int cur=L;
  while(cur<max){
  if(arr[cur]<mid){
    swap(arr[cur],arr[min+1]);
    cur++;
    min++;
  }
  else if(arr[cur]==mid){
  cur++;
  }
  else if(arr[cur]>mid){
    swap(arr[cur],arr[max-1]);
    max--;
  }
  }
  part(arr,L,min);
  part(arr,max,R);
}
void quicksort(vector<int> &arr){
  srand((unsigned)time(NULL));
  int len=arr.size();
  if(len<2)
     return;
  part(arr,0,len-1);
    

}
//5 归并排序递归版本
void process(vector<int> &arr ,int L ,int R){
      if(L==R)
         return;
      int mid= L+((R-L)>>1);
      process(arr, L, mid);
      process(arr, mid+1,R);
      int p=L;
      int p2=mid+1;
      int tmp[R-L+1];
      int i=0;
      while(p<=mid&&p2<=R){
      tmp[i++]=arr[p]<=arr[p2]? arr[p++]:arr[p2++];
      }
      while(p2<=R){
        tmp[i++]=arr[p2++];}
      while (p<=mid) {
        tmp[i++]=arr[p++];  }      
      for(i=0;i<(R-L+1);i++){
        arr[L+i]=tmp[i];
      }
}
void mergesort(vector<int> &arr){
  if(arr.size()<2){
    return;
  }
  process(arr,0,arr.size()-1);
}
//6 堆排序
void heapify(vector<int> &arr,int num,int heapsize){

    int left=2*num+1;
    int maxidx;
    while(left<=heapsize){
      if(left+1<=heapsize)
         maxidx=arr[left]>arr[left+1]? left: left+1;
      else
         maxidx=left;
      if(arr[num]<arr[maxidx]){
        swap(arr[num],arr[maxidx]);
        num=maxidx;
        left=2*num+1;
      }
      else {
        break;
      }
        
    }
}
void heapsort(vector<int> &arr){
  if(arr.size()<2){
    return;
  }
  int heapsize=arr.size()-1;
  for(int i=heapsize;i>=0;i--){
      heapify(arr, i,  heapsize);
  }   
  
  
   while(heapsize>0){
   
   swap(arr[0],arr[heapsize--]);
   heapify(arr, 0, heapsize);
  }

}

//7. 希尔排序(对插入排序的改进)
void shellsort(vector<int> &arr){
//gap序列的选择有很多不一定要使 用二分
int gap=arr.size();
//分组
for(gap=gap/2;gap>=1;gap/=2){
    for(int i=gap;i<arr.size();i++){
      //插入排序  
      int insert=arr[i];
      int j;  
      for(j=i-gap;(j>=0)&&(arr[j]>insert);j-=gap){
        arr[j+gap]=arr[j];
      }
      swap(arr[j+gap],insert) ;
    }
}
}
//非比较排序
//8. 计数排序（稳定版本）
void countsort(vector<int>& arr){
  if(arr.size()<2)
    return;
  //注意一定要+1
  int max=*max_element(begin(arr),end(arr))+1;
  vector<int>bukets(max,0);
  vector<int> tmp(arr.size());
  for(int i=0;i<arr.size();i++){
     bukets[arr[i]]++;
  }
  for(int i=1;i<bukets.size();i++){
     bukets[i]+=bukets[i-1];
  }

  for(int i=arr.size()-1;i>=0;i--){
    if((bukets[arr[i]]-1)==arr.size()-1)
       int j=0;
     tmp[bukets[arr[i]]-1]=arr[i];
      bukets[arr[i]]--;
  }
  for(int i=0;i<arr.size();i++){
    arr[i]=tmp[i];
  }
}

//9. 基数排序(基数为10)
int maxbit(int max){
   int res=max;
  int maxbit=1;
   while(res!=0){
    res=res/base;
    maxbit++;
   }
   return  maxbit;
}
int getdigit(int num,int level){
  return (num /int(pow(base,level)))%base;
}
void radixsort(vector<int>&arr){
    if(arr.size()<2)
    return;
    vector<int>tmp(arr.size());  
    int max=*(max_element(begin(arr),end(arr)));
    int highbit=maxbit(max);
    for(int d=0;d<highbit-1;d++){
       int buckets[base] ={0};
       for(int i=0;i<arr.size();i++){
          int digit= getdigit(arr[i],d);
          buckets[digit]++;
       }
       for(int i=1;i<base;i++){
       buckets[i]=buckets[i-1]+buckets[i];
       }
       for(int i=arr.size()-1;i>=0;i--){
      
       tmp[--buckets[getdigit(arr[i], d)]]=arr[i];
       }
       for(int i=0;i<arr.size();i++){
        arr[i]=tmp[i];
       }
    }

}
//10. 桶排序


//对数器
void genarry(vector<int> &arr ,int N,int max){
  srand((unsigned)time(NULL));
  int randomlen=rand()%N;
  for(int i=0;i<randomlen;i++){
    arr.insert(arr.end(),rand()%max);
  }
}
bool isequal(vector<int> arr1,vector<int> arr2){
    if(arr1.size()!=arr2.size())
       return false;
    for(int i=0;i<arr1.size();i++){
      if(arr1[i]!=arr2[i])
         return  false;
    }
    return true;
}

int main (){
  //vector<int> arr={7,9,8,9,0,7,6};
  
  int N=10000,max=10000;
  for(int i=0;i<10000;i++){
  vector<int> arr1;
  genarry(arr1,N, max);
  //vector <int> arr1={2724 ,2728 ,3137, 7077, 3953};
  // PRINTARR(arr1);
  // cout<<endl;
  vector<int>arr2=arr1;
  //PRINTARR(arr);
  quicksort(arr1);
  shellsort(arr2);
  if(!isequal(arr1, arr2)){
    cout<<"error"<<endl;
    PRINTARR(arr1);
    cout<<"heap"<<endl;
    PRINTARR(arr2);
    return 0;
  }
  
  }
  cout<<"pass"<<endl;
  return 0; 
}

