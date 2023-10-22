#include<vector>
#include <iostream>
using namespace std;
class Solution {
public:
    /*
    //递归版本
    int maxsub(vector<int>& arr,int end){
        if(end==0){
            return arr[0];
        }
        int sum1=max(maxsub(arr,end-1)+arr[end],arr[end]) ; 
        return sum1;
    }

    int maxSubArray(vector<int>& arr) {
        return maxsub(arr,arr.size()-1);
    }*/
    //非递归版本
        int maxSubArray2(vector<int>& arr) {
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
int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};