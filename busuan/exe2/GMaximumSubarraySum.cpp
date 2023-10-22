#include<vector>
#include <iostream>
#include"stdlib.h"
using namespace std;
//非递归版本
int maxSubArray0(vector<int>& arr) {
   vector<int> dp_table(arr.size(),0);
   dp_table[0]=arr[0];
   for(int i=1;i<arr.size();i++){
       dp_table[i]=max(dp_table[i-1]+arr[i],arr[i]);
   }
   int max=dp_table[0];
   for(auto i:dp_table){
       if(i>max)
          max=i;
   }
    return max;
    }
//进一步优化
double maxSubArray(vector<double>& nums) {
        double pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }

int main(){
    int n;
    cin>>n;
    vector<double> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double res= maxSubArray(arr); 
    printf("%.0lf\n",res);
    return 0;
}