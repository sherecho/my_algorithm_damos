#include<string>
#include<vector>
using namespace std;
//暴力递归，会超时
class Solution1 {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()==0)
          return 0;
        return subtask(s,0,s.size()-1);           
    }
    int subtask(string s,int l,int r){
        if(r==l)
          return 1;
        if(l==r-1){
            return s[r]==s[l]?2:1;
        }
        int p1=subtask(s,l+1,r);
        int p2=subtask(s,l,r-1);
        int p3=subtask(s,l+1,r-1);
        int p4=s[r]==s[l]?2+subtask(s,l+1,r-1):0;
        return max( max( max(p1,p2),p3),p4);
    }
};
//动态规划修改
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()==0)
          return 0;
        vector<vector<int>> dp_table(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
          dp_table[i][i]=1;
        }
        for(int i=0;i<s.size()-1;i++){
          dp_table[i][i+1]=s[i]==s[i+1]?2:1;
        }
        for(int i=s.size()-3;i>=0;i--){
          for(int j=i+2;j<s.size();j++){
            int p1=dp_table[i+1][j];
            int p2=dp_table[i][j-1];
            //int p3=dp_table[i+1][j-1];
            int p4=s[j]==s[i]?2+dp_table[i+1][j-1]:0;
            //因为填充顺序，肯定有p1>p3,p2>p3 所以p3可以省略
            dp_table[i][j] = max( max(p1,p2),p4);
          }
        }
        return dp_table[0][s.size()-1];           
    }
};