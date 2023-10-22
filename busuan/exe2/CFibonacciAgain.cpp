#include<vector>
#include<iostream>
using namespace std;
#include<string>
int main(){
    //找规律
    // int len=100;
    // vector<long long> arr(len,0);
    // arr[0]=7;
    // arr[1]=11;
    // for(int i=2;i<len;i++){
    //    arr[i]=arr[i-1]+arr[i-2];
    //    cout<<arr[i]%3<<endl;
    // }
     long n;
     while(scanf("%ld",&n)!=EOF){
      if(n%4==2)
         cout<<"yes"<<endl;
      else
         cout<<"no"<<endl;
     }
    return 0;
}