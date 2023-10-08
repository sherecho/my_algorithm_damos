#include<vector>
#include<string>
#include<limits>
#include<unordered_map>
using namespace std;
//纯暴力，复杂度很高没法通过测试。测试超时：
class Solution1 {
public:
    
    int minStickers(vector<string>& stickers, string target) {
    int maxint=numeric_limits<int>::max();
    int ret=subtask(stickers,target);
    return ret==maxint? -1:ret;

    }
    string minus(string target,string first){
        string ret="";
        int count[26]={0};
        for(int i=0;i<target.size();i++){
            count[target[i]-'a']++;
        }
        for(int i=0;i<first.size();i++){
            count[first[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<count[i];j++){
                ret+=(char)'a'+i;
            }
        }
        return ret;
    }
    int subtask(vector<string>& stickers, string target){
       if(target.size()==0){
           return 0;
       }
       int min=numeric_limits<int>::max();
       for( auto& first:stickers){
           string target2=minus(target,first);
           if(target.size()!=target2.size()){
             int tmp=subtask(stickers,  target2);
             min=min>tmp? tmp:min;
           }

       }
       int maxint=numeric_limits<int>::max();
       int tmp= min==maxint? 0:1;
       return min+tmp;
    }
};
//优化：引入词频统计替代字符串，加入贪心策略剪枝。此时虽然优于方法1，但是仍为递归因此还是超时
class Solution2 {
public:
    
    int minStickers(vector<string>& stickers, string target) {
    int maxint=numeric_limits<int>::max();
    int N=stickers.size();
    //用词频代替原有的字符串
    vector<vector<int>>  stri2(N,vector<int>(26,0));
    for(int i=0;i<N;i++){
        for(int j=0;j< stickers[i].size();j++){
             stri2[i][(int)(stickers[i][j]-'a')]++;
        }
    }
    int ret=subtask(stri2,target);
    return ret==maxint? -1:ret;
    }

    int subtask(vector<vector<int>>& stickers, string target){
       if(target.size()==0){
           return 0;
       }
       vector<int>tar2(26,0);
       for(int i=0;i<target.size();i++){
           tar2[(int)(target[i]-'a')]++;
       }
       int min=numeric_limits<int>::max();
       for(int i=0;i<stickers.size();i++){
           //贪心剪枝
           vector<int> &first= stickers[i];
           string res="";
           if(first[(int)(target[0]-'a')]>0){
               for(int j=0;j<26;j++){
                   if(tar2[j]>0){
                     int tmp=(tar2[j]-first[j])>0?tar2[j]-first[j]:0;                 
                     for(int k=0;k<tmp;k++){
                       res+=(char)('a'+j);
                      } 
                   }
                   
               }
           int tmp=subtask(stickers, res);
           min=tmp>min?min:tmp; 
           }
        }
           return min+(min==numeric_limits<int>::max()?0:1);
    }
};
//优化3：动态规划：此处采用傻缓存进行优化，可以通过oj
class Solution3 {
public:
    
    int minStickers(vector<string>& stickers, string target) {
    int maxint=numeric_limits<int>::max();
    int N=stickers.size();
    //用词频代替原有的字符串
    vector<vector<int>>  stri2(N,vector<int>(26,0));
    for(int i=0;i<N;i++){
        for(int j=0;j< stickers[i].size();j++){
             stri2[i][(int)(stickers[i][j]-'a')]++;
        }
    }
    unordered_map<string,int> dp;
    int ret=subtask(stri2,target,dp);
    return ret==maxint? -1:ret;
    }

    int subtask(vector<vector<int>>& stickers, string target,unordered_map<string,int>&dp){
       if(target.size()==0){
           return 0;
       }
       if(dp.find(target)!=dp.end())
         return dp[target];
       vector<int>tar2(26,0);
       for(int i=0;i<target.size();i++){
           tar2[(int)(target[i]-'a')]++;
       }
       int min=numeric_limits<int>::max();
       for(int i=0;i<stickers.size();i++){
           //贪心剪枝
           vector<int> &first= stickers[i];
           string res="";
           if(first[(int)(target[0]-'a')]>0){
               for(int j=0;j<26;j++){
                   if(tar2[j]>0){
                     int tmp=(tar2[j]-first[j])>0?tar2[j]-first[j]:0;                 
                     for(int k=0;k<tmp;k++){
                       res+=(char)('a'+j);
                      } 
                   }
                   
               }
           int tmp=subtask(stickers, res,dp);
           min=tmp>min?min:tmp; 
           }
        }
        int ret= min+(min==numeric_limits<int>::max()?0:1);
        dp[target]=ret;
        return ret;
    }
};
