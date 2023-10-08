// str1[0...i]和str2[0...j]，这个范围上最长公共子序列长度是多少？
	// 可能性分类:
	// a) 最长公共子序列，一定不以str1[i]字符结尾、也一定不以str2[j]字符结尾
	// b) 最长公共子序列，可能以str1[i]字符结尾、但是一定不以str2[j]字符结尾
	// c) 最长公共子序列，一定不以str1[i]字符结尾、但是可能以str2[j]字符结尾
	// 注意：a)、b)、c)、d)并不是完全互斥的，他们可能会有重叠的情况
	// 但是可以肯定，答案不会超过这四种可能性的范围
	// 那么我们分别来看一下，这几种可能性怎么调用后续的递归。
	// a) 最长公共子序列，一定不以str1[i]字符结尾、也一定不以str2[j]字符结尾
	//    如果是这种情况，那么有没有str1[i]和str2[j]就根本不重要了，因为这两个字符一定没用啊
	//    所以砍掉这两个字符，最长公共子序列 = str1[0...i-1]与str2[0...j-1]的最长公共子序列长度(后续递归)
	// b) 最长公共子序列，可能以str1[i]字符结尾、但是一定不以str2[j]字符结尾
	//    如果是这种情况，那么我们可以确定str2[j]一定没有用，要砍掉；但是str1[i]可能有用，所以要保留
	//    所以，最长公共子序列 = str1[0...i]与str2[0...j-1]的最长公共子序列长度(后续递归)
	// c) 最长公共子序列，一定不以str1[i]字符结尾、但是可能以str2[j]字符结尾
	//    跟上面分析过程类似，最长公共子序列 = str1[0...i-1]与str2[0...j]的最长公共子序列长度(后续递归)
	// d) 最长公共子序列，必须以str1[i]字符结尾、也必须以str2[j]字符结尾
	//    同时可以看到，可能性d)存在的条件，一定是在str1[i] == str2[j]的情况下，才成立的
    //    所以，最长公共子序列总长度 = str1[0...i-1]与str2[0...j-1]的最长公共子序列长度(后续递归) + 1(共同的结尾)
	// 综上，四种情况已经穷尽了所有可能性。四种情况中取最大即可
	// 其中b)、c)一定参与最大值的比较，
	// 当str1[i] == str2[j]时，a)一定比d)小，所以d)参与
	// 当str1[i] != str2[j]时，d)压根不存在，所以a)参与
	// 但是再次注意了！
	// a)是：str1[0...i-1]与str2[0...j-1]的最长公共子序列长度
	// b)是：str1[0...i]与str2[0...j-1]的最长公共子序列长度
	// c)是：str1[0...i-1]与str2[0...j]的最长公共子序列长度
	// a)中str1的范围 < b)中str1的范围，a)中str2的范围 == b)中str2的范围
	// 所以a)不用求也知道，它比不过b)啊，因为有一个样本的范围比b)小啊！
	// a)中str1的范围 == c)中str1的范围，a)中str2的范围 < c)中str2的范围
	// 所以a)不用求也知道，它比不过c)啊，因为有一个样本的范围比c)小啊！
	// 至此，可以知道，a)就是个垃圾，有它没它，都不影响最大值的决策
	// 所以，当str1[i] == str2[j]时，b)、c)、d)中选出最大值
	// 当str1[i] != str2[j]时，b)、c)中选出最大值
    #include<string>
    #include<vector>
    using namespace std;
//递归方法：会超时
class Solution1 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()<1||text2.size()<1)
        return 0;
       return subtask(text1,text2,text1.size()-1,text2.size()-1);
    }
    int subtask(string test1,string test2,int i,int j){
        if(i==0&&j==0){
          if(test1[i]==test2[j])
          return 1;
          else
          return 0;
        }
       else if(i==0) {
          if(test1[i]==test2[j])
          return 1;
          else
            return subtask(test1,test2,i,j-1);
       }
       else if(j==0){
           if(test1[i]==test2[j])
          return 1;
          else
            return subtask(test1,test2,i-1,j);
       }
       else{
           int p1=subtask(test1,test2,i-1,j);
           int p2=subtask(test1,test2,i,j-1);
           int tmp=test1[i]==test2[j]? 1:0 ;
           int p3=tmp+subtask(test1,test2,i-1,j-1);
           return max(max(p1,p2),p3);

       }
    }
};
//dp 优化
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()<1||text2.size()<1)
        return 0;
        vector<vector<int>> dp_table(text1.size(),vector<int>(text2.size(),0));
        dp_table[0][0]=text1[0]==text2[0]?1:0;
        for(int j=1;j<text2.size();j++){
          dp_table[0][j]=text1[0]==text2[j]?1:dp_table[0][j-1];
        }
        for(int j=1;j<text1.size();j++){
          dp_table[j][0]=text1[j]==text2[0]?1:dp_table[j-1][0];
        }
        for(int i=1;i<text1.size();i++){
          for(int j=1;j<text2.size();j++){
            int p1=dp_table[i-1][j];
            int p2=dp_table[i][j-1];
            int tmp=text1[i]==text2[j]? 1:0 ;
            int p3=tmp+dp_table[i-1][j-1];
            dp_table[i][j]= max(max(p1,p2),p3);
          }
        }
        return dp_table[text1.size()-1][text2.size()-1];
    }

};