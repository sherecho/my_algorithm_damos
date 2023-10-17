#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include<string>
#include <unordered_set>
#include <unordered_map>
#include<vector>
#include<stack>
#include <utility>
#include<queue>
#include "time.h"
#include<stdlib.h>
#include<cmath>
using namespace std; 
/*递归
-汉诺塔问题
-打印字符串的全部子序列，要求不要出现重复字面值的子序列
  例如：abc : "" "ac" "bc" "c" "b" "ab" "a" "abc"
-打印一个字符串的全部排序（不重复，剪枝简化版本）
-给你一个栈请你逆序这个栈不能申请格外的数据结构只能使用递归函数如何实现
-假设有排成一行的N个位置记为1到N N一定大于等于2开始时机器人在其中的M位置上M一定是1到
  N中的一个如果机器人来到1位置那么下一步只能往右来到2位置如果机器人来到N位置那么下一步只能往左来到N-1的位置
-给定一个整型数组arr代表数值不同的纸牌排成一条线玩家A和玩家B依次拿走每一张牌
 规定玩家A先拿玩家B后拿但每个玩家每次只能拿最左或者最右的牌玩家A和玩家B智商一样请返回最后获胜者的分数
-背包问题
-优化规定1对应A 2对应B 3对应C依此类推26对应Z那么一个数字字符串比如111就可以转化为AAA KA Ak给定一个只有数字字符组成的字符串str返回有多少种转化结果
-给定一个字符串str，给定一个字符串类型的数组arr，出现的字符都是小写英文
 arr每一个字符串，代表一张贴纸，你可以把单个字符剪开使用，目的是拼出str来
 返回需要至少多少张贴纸可以完成这个任务。
 例子：str= "babac"，arr = {"ba","c","abcd"}
 ba + ba + c  3  abcd + abcd 2  abcd+ba 2
  分析：与顺序无关
 本题测试链接：https://leetcode.com/problems/stickers-to-spell-word
 解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/691. 贴纸拼词.cpp
 注：此处DP无法做严格的位置依赖，只能用缓存解决
 -最长公共子序列
  给定两个字符串str1和str2，
  返回这两个字符串的最长公共子序列长度
  比如 ： str1 = “a12b3c456d”,str2 = “1ef23ghi4j56k”
  最长公共子序列是“123456”，所以返回长度6
  测试链接：https://leetcode.com/problems/longest-common-subsequence/
  解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/1143. 最长公共子序列.cpp
 -最长回文子序列问题
  测试链接：https://leetcode.cn/problems/longest-palindromic-subsequence/
  解答文件：/mnt/e/desktop/CS_STUDY/DataS_AG/AG_PROJECT_CPLUS/leetcode_vs/516. 最长回文子序列.cpp
 -象棋问题
   请同学们自行搜索或者想象一个象棋的棋盘，
   然后把整个棋盘放入第一象限，棋盘的最左下角是(0,0)位置
    那么整个棋盘就是横坐标上9条线、纵坐标上10条线的区域
     给你三个 参数 x，y，k
    返回“马”从(0,0)位置出发，必须走k步
    最后落在(x,y)上的方法数有多少种? 
 -咖啡问题-业务模型
  // 数组arr代表每一个咖啡机冲一杯咖啡的时间，每个咖啡机只能串行的制造咖啡。
  // 现在有n个人需要喝咖啡，只能用咖啡机来制造咖啡。
  // 认为每个人喝咖啡的时间非常短，冲好的时间即是喝完的时间。
  // 每个人喝完之后咖啡杯可以选择洗或者自然挥发干净，只有一台洗咖啡杯的机器，只能串行的洗咖啡杯。
  // 洗杯子的机器洗完一个杯子时间为a，任何一个杯子自然挥发干净的时间为b。
  // 四个参数：arr, n, a, b 
 // 假设时间点从0开始，返回所有人喝完咖啡并洗完咖啡杯的全部过程结束后，至少来到什么时间点。
-二维数组最小累加和的问题
  给定一个二维数组matrix，一个人必须从左上角出发，最后到达右下角
   沿途只可以向下或者向右走，沿途的数字都累加就是距离累加和
  返回最小距离累加和
  -思路一：建立一个dp表和matrix等规模，dp表的含义：从dp[0][0]出发到达dp【i】【j】的最小累加和
       因此第一行没有别的选择，只能从左边过来，第一列也很好填，只能从上面过来，其它的格子依次从左边和上边找一个最小的填进去
   -思路二：数组压缩 （小技巧：空间压缩）
    -扩展，如果一个动态规划问题依赖左上角和上方也可以进行数组压缩
    -如果依赖左方，上方也可以进行数组压缩
    -如果依赖左上，上，左，依然可以进行数组压缩（增加一个临时变量记录左上的值）
     进一步扩展：
     压缩数组可以采用行也可以采用列
- arr是货币数组，其中的值都是正数。再给定一个正数aim。
  每个值都认为是一张货币，
  即便是值相同的货币也认为每一张都是不同的，
   返回组成aim的方法数
   例如：arr = {1,1,1}，aim = 2
   第0个和第1个能组成2，第1个和第2个能组成2，第0个和第2个能组成2
   一共就3种方法，所以返回3
   -分析：属于从左往右的模型
-进阶版：arr是面值数组，其中的值都是正数且没有重复。再给定一个正数aim。
 每个值都认为是一种面值，且认为张数是无限的。
 返回组成aim的方法数
 例如：arr = {1,2}，aim = 4
 方法如下：1+1+1+1、1+1+2、2+2
 一共就3种方法，所以返回3
 -记忆化搜索和严格表结构在每个格子没有枚举行为的时候性能一样好
 -有枚举行为表结构可以继续优化:
  分析表结构：列为index横轴为rest
    I
  -------------------
 R: 0|1|2|3|4|5|6|7|8|9|
  ———————————————————————
    a|b|c|d|e|f|g|h|i|j
  根据程序可以知道想要求出8依赖的是i，（假设arr[8]=1),i，g,h，f,...a
  而7 依赖的是h,g,...a
  因此可以看出7，和8存在一部分重复
  可以有7+i得到8
-货币问题进一步扩展
 arr是货币数组，其中的值都是正数。再给定一个正数aim。
 每个值都认为是一张货币，
 认为值相同的货币没有任何不同，
 返回组成aim的方法数
 例如：arr = {1,2,1,1,2,1,2}，aim = 4
 方法：1+1+1+1、1+1+2、2+2
 一共就3种方法，所以返回3
-给定5个参数，N，M，row，col，k
  表示在N*M的区域上，醉汉Bob初始在(row,col)位置
  Bob一共要迈出k步，且每步都会等概率向上下左右四个方向走一个单位
  任何时候Bob只要离开N*M的区域，就直接死亡
  返回k步之后，Bob还在N*M的区域的概率
-给定3个参数，N，M，K
 怪兽有N滴血，等着英雄来砍自己
 英雄每一次打击，都会让怪兽流失[0~M]的血量
  到底流失多少？每一次在[0~M]上等概率的获得一个值
  求K次打击之后，英雄把怪兽砍死的概率
 总结：
  -1.从左-》右的尝试模型
  -2.范围尝试模型（在L-R范围上尝试）
  -3.样本队列模型
     （最长公共子序列问题）
  -4.业务模型
*/ 
//汉诺塔问题 复杂度：

class Hanno{
int N_level;
public:
Hanno (int n){
    N_level=n;
}
//方法1：六个过程
void Hanno1(){
    cout<<"Hanno1:"<<endl;
    lefttoright(N_level);
}
void lefttoright(int n){
    if(n==1){
        cout<<"put "<<n<<"to right"<<endl;
        return;
    }
    lefttomid(n-1);
    cout<<"put "<<n<<"to right"<<endl;
    midtoright(n-1);

}
void lefttomid(int n){
        if(n==1){
        cout<<"put "<<n<<"to mid"<<endl;
        return;
        }
        lefttoright(n-1);
        cout<<"put "<<n<<"to mid"<<endl;
        righttomid(n-1);
}
void midtoright(int n){
        if(n==1){
        cout<<"put "<<n<<"to right"<<endl;
        return;
        }
        midtoleft(n-1);
        cout<<"put "<<n<<"to right"<<endl;
        lefttoright(n-1);
}
void midtoleft(int n){
    if(n==1){
        cout<<"put "<<n<<"to left"<<endl;
        return;
        }
    midtoright(n-1);
    cout<<"put "<<n<<"to left"<<endl;
    righttoleft(n-1);
}
void righttomid(int n){
        if(n==1){
        cout<<"put "<<n<<"to mid"<<endl;
        return;
        }
    righttoleft(n-1);
    cout<<"put "<<n<<"to mid"<<endl;
   lefttomid(n-1);
}
void righttoleft(int n){
        if(n==1){
        cout<<"put "<<n<<"to left"<<endl;
        return;
        }
    righttomid(n-1);
    cout<<"put "<<n<<"to left"<<endl;
    midtoleft(n-1);
}
//方法2：总结方法一用一个递归函数替代六个过程
void Hanno2(){
    cout<<"Hanno2"<<endl;
   subtask("left", "right", "mid",N_level);
}
 void subtask(string from,string to,string other,int n){
     if(n==1){
        cout<<"put "<<n<<"to"<<to<<endl;
        return;
     }
     subtask(from, other, to,  n-1);
     cout<<"put "<<n<<"to"<<to<<endl;
     subtask(other, to, from,  n-1);
 }    
};
//打印字符串子序列(不重复字面值)
//打印字符全排序（不重复，剪枝简化版本）
class print_sub_str{
    private:
    string seq;
    unordered_set<string> subseqs;
    vector<string> orders;
    public:
 print_sub_str(string a){
     seq=a;
 }
 void printsub(){
    cout<<"subs: "<<endl;
   subtask(0, "");
   for(auto & it:subseqs){
    cout<<"sub: "<<it<<endl;
   }
 }
 void subtask(int sindex,string front){
      if(sindex==seq.size()){ 
        subseqs.insert(front) ;  
        return;
      }
      subtask(sindex+1,front);
      subtask(sindex+1,front+seq[sindex]);
      return;
 }
 //打印一个字符串的全部排序
 void printorders(){
     suborder(0);
     cout<<"orders:"<<endl;
     for(auto & it:orders){
        cout<<""<<it<<endl;
     }
     
 }
 void suborder(int index){
      if(index==seq.size()){
        orders.push_back(seq);
        return;
      }
      unordered_set<char> sets;
      for(int i=index;i<seq.size();i++){
          if(sets.find(seq[i])==sets.end()){
            sets.insert(seq[i]);
            swap(index,i);
            suborder(index+1);
            swap(index,i);//恢复现场
          }
          
      }
 }
 void swap(int index1,int index2){
    char tmp=seq[index1];
    seq[index1]=seq[index2];
    seq[index2]=tmp;

 }
};
//给你一个栈请你逆序这个栈不能申请格外的数据结构只能使用递归函数如何实现
class reverse_stack{
private:
  stack<int> mystack;
public:
   reverse_stack(){

  } 
  void push(int a){
    mystack.push(a);
  }
  void reverse(){
     if(mystack.empty())
     {
        
        return;
     }
     int last=rmbotom();
     reverse_stack();
     mystack.push(last);
     cout<<"reverse: "<<endl;
     while(!mystack.empty()){
         cout<<mystack.top()<<" ";
         mystack.pop();
     }
     cout<<endl;
  }
  int rmbotom(){
    int top=mystack.top();
    mystack.pop();
    if(!mystack.empty()){
        int last=rmbotom();
        mystack.push(top);
        return last;
    }
    else{
        return top;
    }
     
  }

};
//机器人移动：从暴力递归到动态规划
class robot_move{
    private:
    /*
     int start;//起始位置
     int N;//总路程长度
     int movenum;//一共可以移动的步数
     int aim;//目标地点
    */
    public: 
    //暴力递归法
     int move1(int start,int N,int aim,int movenum){
         return subtask(start,N,aim,movenum);
     }

   
    int subtask(int cur,int N,int aim,int rest){
        if(rest==0){
            return cur==aim? 1:0;
        }
       
        if(cur==1){
            return subtask(cur+1,  N,  aim,  rest-1);
        }
        if(cur==N){
            return subtask(N-1, N, aim,  rest-1);
        }
        return subtask(cur-1,  N, aim, rest-1)+subtask(cur+1,  N,  aim, rest-1);
    }
    //优化一：使用内存记录--     
    int move2(int start,int N,int aim,int movenum){
        int **dp=  new int*[N+1];
        for (int i=0;i<N+1;i++){
            dp[i]=new int[movenum+1];
        }
        for(int i=0;i<N+1;i++){
            for(int j=0;j<movenum+1;j++){
                dp[i][j]=-1;
            }
        }
         int ret=subtask2(start,N,aim,movenum,dp);
        for (int i=0;i<N+1;i++){
            delete [] dp[i];
        }
        delete[] dp;
        return ret;
     }
    int subtask2(int cur,int N,int aim,int rest,int** dp){
        if(dp[cur][rest]!=-1)
         return dp[cur][rest];
        int ret;
        if(rest==0){
            ret= cur==aim? 1:0;
        }
       
        if(cur==1){
            ret= subtask(cur+1,  N,  aim,  rest-1);
        }
        if(cur==N){
            ret= subtask(N-1, N, aim,  rest-1);
        }
        ret= subtask(cur-1,  N, aim, rest-1)+subtask(cur+1,  N,  aim, rest-1);
         dp[cur][rest]=ret;
        return ret;
    }
    //优化2 :动态规划
    int move3(int start,int N,int aim,int movenum){
    if(start<1||N<2||aim<1||aim>N||movenum<0||start>N)
        return -1;
    int dp[N+1][movenum+1];
    for(int i=0;i<N+1;i++){
            for(int j=0;j<movenum+1;j++){
                dp[i][j]=0;
            }
        }

    dp[aim][0]=1;
    for(int rest=1;rest<movenum+1;rest++){
        dp[1][rest]=dp[2][rest-1];
        dp[N][rest]=dp[N-1][rest-1];
        for(int i=2;i<movenum+1;i++){
            dp[i][rest]=dp[i-1][rest-1]+dp[i+1][rest-1];
        }
    }
    return dp[start][movenum];
    }


};
//纸牌先后手问题
class cardplay{
 
 private:
 vector<int> card;
 public:
 cardplay(vector<int>arr){
   card=arr;
 }
 //base方法暴力迭代（返回获胜者分数）
 int win1(){
   if(card.size()==0){
     return 0;
   }
   int first=f1(0,card.size()-1);
   int second=g1(0,card.size()-1);
   return max(first,second);
 }
int f1(int L,int R){
   if(L==R){
    return card[L];
   }
   int cond1=card[L]+g1(L+1,R);
   int cond2=card[R]+g1(L,R-1);
   return max(cond1,cond2);
}
int g1(int L,int R){
    if(L==R){
    return 0;
   }
   int cond1=f1(L,R-1);
   int cond2=f1(L+1,R);
   return  min(cond1,cond2);
}
//优化1：使用缓存表
int win2(){
    int length=card.size();
    
    int **f_table=  new int*[length];
        for (int i=0;i<length;i++){
            f_table[i]=new int[length];
        }
    int** g_table=  new int*[length];
    for (int i=0;i<length;i++){
            g_table[i]=new int[length];
        }
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            f_table[i][j]=-1;
            g_table[i][j]=-1;
        }
    }
   int first=f2(0,card.size()-1,f_table);
   int second=g2(0,card.size()-1,g_table);

   for (int i=0;i<length;i++){
            delete [] f_table[i];
            delete [] g_table[i];
        }
        delete [] f_table;
        delete [] g_table;   
    return max(first,second);
}
int f2(int L,int R,int **ftable){
    if (ftable[L][R]!=-1) {
       return ftable[L][R];
    }
   if(L==R){
     ftable[L][R]=card[L];
     return card[L];
   }
   int cond1=card[L]+g1(L+1,R);
   int cond2=card[R]+g1(L,R-1);
   int ret= max(cond1,cond2);
   ftable[L][R]=ret;
   return ret;
}
int g2(int L,int R,int** gtable){
    if(gtable[L][R]!=-1){
        return gtable[L][R];
    }
    if(L==R){
        gtable[L][R]=0;
    return 0;
   }
   int cond1=f1(L,R-1);
   int cond2=f1(L+1,R);
   int ret= min(cond1,cond2);
   gtable[L][R]=ret;
   return ret;
}
//优化2 迭代版动态规划
int win3(){
    int length=card.size();
    
    int **f_table=  new int*[length];
        for (int i=0;i<length;i++){
            f_table[i]=new int[length];
        }
    int** g_table=  new int*[length];
    for (int i=0;i<length;i++){
            g_table[i]=new int[length];
        }
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            if(i==j){
            f_table[i][j]=card[i];
            g_table[i][j]=0;
            }
            else{
            f_table[i][j]=0;
            g_table[i][j]=0; 
            }
            
        }
    }
    //沿对角线填充
    for(int col=1;col<length;col++){
        int curco=col;
        int curro=0;
        while(curco<length){
            g_table[curro][curco]=min(f_table[curro][curco-1],f_table[curro+1][curco]);
            f_table[curro][curco]=max(card[curro]+g_table[curro+1][curco],card[curco]+g_table[curro][curco-1]);
            curco++;
            curro++;
        }
    }
   int first=f_table[0][card.size()-1];
   int second=g_table[0][card.size()-1];
  
   for (int i=0;i<length;i++){
            delete [] f_table[i];
            delete [] g_table[i];
        }
        delete [] f_table;
        delete [] g_table; 
   return max(first,second);
}
};
//背包问题
class backpacks{
public:
backpacks(vector<int>w,vector<int>val,int ca){
    weight=w;
    value=val;
    capecity=ca;
}
// 返回：不超重的情况下，能够得到的最大价值
//暴力递归法
int maxval(){
    return subtask1(0, capecity);
}
int subtask1(int index,int restc){
    if(restc<0){
        return -1; //这个要最先判断
    }
    if(index==weight.size()){
        return 0;
    }
    int get=subtask1(index+1, restc-weight[index])>=0?subtask1(index+1, restc-weight[index])+value[index]:-1;
    int noget=subtask1(index+1, restc);
    return max(get,noget);
}
//dp
int maxval2(){
    //index 0~weght.size rest 负数~cap
    int dptable[weight.size()+1][capecity+1];
    /* 
        if(index==weight.size()){
        return 0;
    }根据这个改写：dp表的最后一行是0
    */
    for(int i=0;i<=weight.size();i++){
        for(int j=0;j<=capecity;j++){
            dptable[i][j]=0;
        }
    }
    /*
    int get=subtask1(index+1, restc-weight[index])>=0?subtask1(index+1, restc-weight[index])+value[index]:-1;
    int noget=subtask1(index+1, restc);
    return max(get,noget);
    根据这个改写：
    */
    for(int index=weight.size()-1;index>=0;index--){
        for(int rest=0;rest<=capecity;rest++){
            int noget=dptable[index+1][rest];
            int get=(rest-weight[index])>0? dptable[index+1][rest-weight[index]]+value[index]:-1;
            dptable[index][rest]=max(get,noget);
        }
    }
    return dptable[0][capecity];
}
private:
vector<int> weight;
vector<int> value;
int capecity;
};
//优化规定1对应A 2对应B 3对应C依此类推26对应Z那么一个数字字符串比如111就可以转化为AAA KA Ak给定一个只有数字字符组成的字符串str返回有多少种转化结果
class intconvstr{
    public:
    //暴力递归法
    intconvstr(string data){
        string_data=data;
    }
    int getconv(){
        return subtask(0);
    }
    int subtask(int index){
        if(index==string_data.size()){
            return 1;
        }
        if(string_data[index]=='0'){
            return 0;
        }
        int ways=subtask(index+1);
        if((index+1)<string_data.size()&&(string_data[index]-'0')*10+(string_data[index+1]-'0')<27){
            ways+=subtask(index+2);
        }
        return ways;
    }
    //dp 法
    int getconv2(){
        int dp_table[string_data.size()+1];
        dp_table[string_data.size()]=1;
        for(int i=0;i<string_data.size();i++){
            dp_table[i]=0;
        }
        for(int index=string_data.size()-1;index>=0;index--){
            
            if(string_data[index]=='0'){
               dp_table[index]=0;
            }
            else{
                int ways=dp_table[index+1];
                if((index+1)<string_data.size()&&(string_data[index]-'0')*10+(string_data[index+1]-'0')<27){
                ways+=dp_table[index+2];
                }  
                dp_table[index]=ways;
            }
            
        }
        return dp_table[0];
        
    }    
    private:
    string string_data;
};
class jumphorse{
    public:
    jumphorse(int x,int y,int size=10){
    target.first=x;
    target.second=y;
    this->size=size;
    }
    int ways(int jump){
        return subtask1(0, 0, jump);
    }
    int subtask1(int x,int y,int jumpnum){

        if(x<0||y>=size||x>=size||y<0)
           return 0;
        if(jumpnum==0){
           if(x==target.first&&y==target.second)
             return 1;
            else
             return 0;
        }

        int p=0;
        p+=subtask1(x+2, y, jumpnum-1);
        p+=subtask1(x+2, y+1,  jumpnum-1);
        p+=subtask1(x+2, y-1,  jumpnum-1);
        p+=subtask1(x, y+2,  jumpnum-1);
        p+=subtask1(x, y-2,  jumpnum-1);
        p+=subtask1(x-2, y, jumpnum-1);
        p+=subtask1(x-2, y+1,  jumpnum-1);
        p+=subtask1(x-2, y-1,  jumpnum-1);
        return p;
    }
    int ways_dp(int jump){
       vector< vector<vector<int>>>dptable(jump+1,vector<vector<int>>(size,vector<int>(size,0)));
       dptable[0][target.first][target.second]=1;
       for(int r=1;r<=jump;r++){
          for(int x=0;x<size;x++){
            for(int y=0;y<size;y++){
                int res=0;
                res+=pick(x+2, y, r-1, dptable);
                res+=pick(x+2, y+1, r-1, dptable);
                res+=pick(x+2, y-1, r-1, dptable);
                res+=pick(x, y+2, r-1, dptable);
                res+=pick(x, y-2, r-1, dptable);
                res+=pick(x-2, y, r-1, dptable);
                res+=pick(x-2, y+1, r-1, dptable);
                res+=pick(x-2, y-1, r-1, dptable);
                dptable[r][x][y]=res;
            }
          }
       }

       return dptable[jump][0][0];
    }
    int pick(int x,int y,int r,const vector< vector<vector<int>>>& dp_table){
        if(x<0||y>=size||x>=size||y<0)
           return 0;
        return dp_table[r][x][y];
    }
    private:
    pair<int,int> target;
    int size;
};
//咖啡问题。业务模型
class machine{
    public:  int starttime;
    int finishtime;
    machine(){

    }
    machine(int a,int b){
        starttime=a;
        finishtime=b;
    }
};
struct coffecompare{
    bool operator ()(machine a,machine b){
        return (a.finishtime+a.starttime)>(b.starttime+b.finishtime);
    }
};
class coffe{
    public:
    int mintime(vector<int> maketimes,int numpeople,int washtime,int selftime){
     priority_queue<machine,vector<machine>,coffecompare> minheap;
     for(int i=0;i<maketimes.size();i++){
        minheap.push(machine(0,maketimes[i]));
     }
     vector<int> drinktime(numpeople,0);
     for(int i=0;i<numpeople;i++){
        machine cur=minheap.top();
        minheap.pop();
        drinktime[i]=cur.starttime+cur.finishtime ;
        cur.starttime=cur.starttime+cur.finishtime  ;
        minheap.push(cur);
     }
      return best(drinktime,0,washtime,selftime ,0);
    }
    int best(vector<int> drinks,int kth,int wash,int nonewash, int freetime){
        if(kth==drinks.size()){
            return 0;
        }
        int tmp=max(freetime,drinks[kth])+wash;
        int machinewash=best(drinks,kth+1,wash,nonewash,tmp);
        int p1=max(tmp,machinewash);

        int nonewashtime=best(drinks,kth+1,wash,nonewash,freetime);
        int tmp2=nonewash+drinks[kth];
        int p2=max(tmp2,nonewashtime);
        return min(p1,p2);

    }
    int mintime_dp(vector<int> maketimes,int numpeople,int washtime,int selftime){
     priority_queue<machine,vector<machine>,coffecompare> minheap;
     for(int i=0;i<maketimes.size();i++){
        minheap.push(machine(0,maketimes[i]));
     }
     vector<int> drinktime(numpeople,0);
     for(int i=0;i<numpeople;i++){
        machine cur=minheap.top();
        minheap.pop();
        drinktime[i]=cur.starttime+cur.finishtime ;
        cur.starttime=cur.starttime+cur.finishtime  ;
        minheap.push(cur);
     } 
     int maxfree=0;
     for(int i=0;i<numpeople;i++){
        maxfree=max(drinktime[i],maxfree)+washtime;
     }
     
     vector<vector<int>> best_table(numpeople+1,vector<int>(maxfree+1,0));
     for(int n=numpeople-1;n>=0;n--){
        for(int free=0;free<=maxfree;free++){
            int tmp=max(free,drinktime[n])+washtime;
            if(tmp>maxfree)
              continue;
            int machinewash=best_table[n+1][tmp];
            int p1=max(tmp,machinewash);
            int nonewashtime=best_table[n+1][free];
            int tmp2=selftime+drinktime[n];
            int p2=max(tmp2,nonewashtime);
            best_table[n][free]=min(p1,p2);
        }
        
     }
      return best_table[0][0];
    }
    private:
    
};
//二维数组最小累加和的问题
//扩展：所有依赖左边和上方的dptale都可以用这种方式进行一维表替代。
class minsum{
    public:

 minsum(int x,int y,int randmax):X(x),Y(y),matrix(x,vector<int>(y,0))
 {
  srand(time(NULL));
  for(int inde=0;inde<x;inde++){
    for(int indey=0;indey<y;indey++){
        int randomval=rand()%randmax;
        matrix[inde][indey]=randomval;
    }
  }

 }
//思路一：建立一个dp表和matrix等规模，dp表的含义：从dp[0][0]出发到达dp【i】【j】的最小累加和
//因此第一行没有别的选择，只能从左边过来，第一列也很好填，只能从上面过来，其它的格子依次从左边和上边找一个最小的填进去
 int getminsum1(){
   vector<vector<int>> dp_table(X,vector<int>(Y,0));
   dp_table[0][0]=matrix[0][0];
   for(int i=1;i<Y;i++){
    dp_table[0][i]=dp_table[0][i-1]+matrix[0][i];
   }
   for(int i=1;i<X;i++){
     dp_table[i][0]=dp_table[i-1][0]+matrix[i][0];
   }
   for(int i=1;i<X;i++){
    for(int j=1;j<Y;j++){
        dp_table[i][j]=min(dp_table[i][j-1],dp_table[i-1][j])+matrix[i][j];
    }
   }
   return dp_table[X-1][Y-1];
 }
 //用一个和matrix大小相同的数组占用了太多的空间，可以只使用一个一维数组代替。当满足左方和上方依赖的dptable都可以使用这种方法进行替代
  int getminsum2(){
    vector<int>dp_table(Y,0);
    dp_table[0]=matrix[0][0];
   for(int i=1;i<Y;i++){
    dp_table[i]=dp_table[i-1]+matrix[0][i];
   }
   //一维的dp——table 在没更新的时候就是上方的值，左方的值是已更新的左边的值，因此一维数组就可以完成上述方法1的依赖关系的更新
   for(int i=1;i<X;i++){
    //更新最左边的列
    dp_table[0]+=matrix[i][0];
    for(int j=1;j<Y;j++){
        dp_table[j]=min(dp_table[j-1],dp_table[j])+matrix[i][j];
    }
   }
   return dp_table[Y-1];
  }
 
 private:
 vector<vector<int>> matrix;
 int X;
 int Y;
};

//arr是货币数组，其中的值都是正数。再给定一个正数aim。
//   每个值都认为是一张货币，
//   即便是值相同的货币也认为每一张都是不同的
class coinproblem1{
    public:
    coinproblem1(int len,int a):arrlen(len),aim(a),arr(len,0){
        srand((unsigned)time(NULL));
        for(auto &num : arr) {
            int random =rand()%10;
            num=random;
        }
    }
    int rec_getstrategy(){
    return  subtask(aim,0);
    }
    int subtask(int rest,int index){
     if(rest<0)
        return 0;
     if(index==arr.size()){//no money 
        return rest==0? 1:0;
     }
     int res=subtask(rest,index+1)+subtask(rest-arr[index],index+1);
     return res;
     }
    int dp_getstrategy(){
        vector<vector<int>> dp_table(aim+1,vector<int>(arr.size()+1,0));
        dp_table[0][arr.size()]=1;
        for(int i=1;i<aim+1;i++){
            dp_table[i][arr.size()]=0;
        }
        for(int r=0;r<aim+1;r++){
        for(int index=arr.size()-1;index>=0;index--){    
            int res=((r-arr[index])>=0)?dp_table[r-arr[index]][index+1]:0;
             dp_table[r][index]=dp_table[r][index+1]+res;
            }
        }
        return dp_table[aim][0];
    }
    private:
    int arrlen;
    int aim;
    vector<int> arr;
};
//no limit 版本
/*-进阶版：arr是面值数组，其中的值都是正数且没有重复。再给定一个正数aim。
 每个值都认为是一种面值，且认为张数是无限的。
 返回组成aim的方法数
 例如：arr = {1,2}，aim = 4
 方法如下：1+1+1+1、1+1+2、2+2
 一共就3种方法，所以返回3
*/
class coinproblem2{
    public:
    coinproblem2(int len,int a):arrlen(len),aim(a),arr(len,0){
         srand((unsigned)time(NULL));
        //  cout<<"len"<<len<<endl;
        //  cout<<"a"<<a<<endl;
        //  cout<<"arr:"<<std::flush;;
        for(auto &num : arr) {
            int random =rand()%10+1;
            num=random;
            // cout<<num<<std::flush;;
        }
    }
    int rv_stra(){
     return subtask(aim,0);
    }
    int subtask(int rest,int index){
      if(rest<0)
        return 0;
       if(index==arr.size())
          return rest==0? 1:0;
        int ways=0;
        for(int num=0;num*arr[index]<=rest;num++){
         ways+=subtask(rest-(num*arr[index]),index+1);
        }
        return ways;
    }
    int dp_stra(){
    vector<vector<int>> dp_table(aim+1,vector<int>(arr.size()+1,0));
        dp_table[0][arr.size()]=1;
        for(int i=1;i<aim+1;i++){
            dp_table[i][arr.size()]=0;
        }
        for(int r=0;r<aim+1;r++){
            for(int index=arr.size()-1;index>=0;index--){
                int ways=0;
               for(int num=0;num*arr[index]<=r;num++){
                 ways+=dp_table[r-(num*arr[index])][index+1];
               }
               dp_table[r][index]=ways;
            }
        }
        return dp_table[aim][0];
   }
    int dp_stra2(){
        vector<vector<int>> dp_table(aim+1,vector<int>(arr.size()+1,0));
        dp_table[0][arr.size()]=1;
        for(int i=1;i<aim+1;i++){
            dp_table[i][arr.size()]=0;
        }
        for(int r=0;r<aim+1;r++){
            for(int index=arr.size()-1;index>=0;index--){
               int ways=0;
               if((r-arr[index])>=0)
                ways=dp_table[r-arr[index]][index];
               else ways=0;
               dp_table[r][index]=ways+dp_table[r][index+1];
            }
        }
        return dp_table[aim][0];
        }
    /*  分析表结构：列为index横轴为rest
    I
  -------------------
 R: 0|1|2|3|4|5|6|7|8|9|
  ———————————————————————
    a|b|c|d|e|f|g|h|i|j
  根据程序可以知道想要求出8依赖的是i，（假设arr[8]=1),i，g,h，f,...a
  而7 依赖的是h,g,...a
  因此可以看出7，和8存在一部分重复
  可以有7+i得到8
  */
   
    private:
    vector<int> arr;
    int arrlen;
    int aim;

};
class coinproblem3{
    public:
    coinproblem3(int len,int a):arrlen(len),aim(a),arr(len,0){
         srand((unsigned)time(NULL));
        //  cout<<"len"<<len<<endl;
        //  cout<<"a"<<a<<endl;
        //  cout<<"arr:"<<std::flush;;
        for(auto &num : arr) {
            int random =rand()%10+1;
            num=random;
            // cout<<num<<std::flush;;
        }
    }
    void convert(){
        unordered_map<int,int>mymap;
        for( int coin:arr){
            if(mymap.find(coin)!=mymap.end()){
                mymap[coin]++;     
            }
            else{
                mymap[coin]=1;
            }
        }
        int len=mymap.size();
        coinarr.resize(len);
        coinnum.resize(len);
        int i=0;
        for(auto coin:mymap){   
            coinarr[i]=coin.first;
            coinnum[i]=coin.second;
            i++;
        }
    }
    int rv_stra(){
     return  subtask(aim,0);
    }
    int subtask(int rest ,int index){
    if(rest<0)
      return 0;
    if(index==coinarr.size())
      return (rest==0)?1:0;
    int ways=0;
    for(int num=0;(num<=coinnum[index])&&(num*coinarr[index]<=rest);num++){
        ways+=subtask(rest-num*coinarr[index],index+1);
    }
    return ways;
    }
    int dp_stra(){
        vector<vector<int>>dp_table(aim+1,vector<int>(coinarr.size()+1,0));
        dp_table[0][coinarr.size()]=1;
        for(int r=0;r<aim+1;r++){
            for(int index =coinarr.size()-1;index>=0;index--){
                int ways=0;
                  for(int num=0;(num<=coinnum[index])&&(num*coinarr[index]<=r);num++){
                       ways+=dp_table[r-num*coinarr[index]][index+1];
                    }
                    dp_table[r][index]=ways;
                }  
        }
        return dp_table[aim][0];
    }
    //dp表进一步优化
    int dp_stra2(){
    vector<vector<int>>dp_table(aim+1,vector<int>(coinarr.size()+1,0));
        dp_table[0][coinarr.size()]=1;
        for(int r=0;r<aim+1;r++){
            for(int index =coinarr.size()-1;index>=0;index--){
                int ways=0;
                if((r-coinarr[index])>=0)
                   ways+=dp_table[r-coinarr[index]][index];
                if((r-(coinnum[index]+1)*coinarr[index])>=0)
                    ways-=dp_table[r-(coinnum[index]+1)*coinarr[index]][index+1];
                dp_table[r][index]=ways+dp_table[r][index+1];

                }  
        }
        return dp_table[aim][0];    
    }
    private:
    int arrlen;
    vector<int> arr;
    int aim;
    vector<int> coinarr;
    vector<int> coinnum;
    
};

/*-给定5个参数，N，M，row，col，k
  表示在N*M的区域上，醉汉Bob初始在(row,col)位置
  Bob一共要迈出k步，且每步都会等概率向上下左右四个方向走一个单位
  任何时候Bob只要离开N*M的区域，就直接死亡
  返回k步之后，Bob还在N*M的区域的概率*/
class BOB_LIVE{
    public:
    BOB_LIVE(int M,int N):M(M),N(N){
    
    }
    double live_af_k(int k,int row,int col){
        double po=(double)(subtask(k,row,col))/((double)pow(4,k));
        return po;
    }
    int subtask(int rest,int row,int col){
        if(((row>=M)||(col>=N)||(row<0)||(col<0)))
          return 0;
        if(rest==0){
            return 1;
        }
        int res=0;
        res+=subtask(rest-1,row-1,col);
        res+=subtask(rest-1,row+1,col);
        res+=subtask(rest-1,row,col-1);
        res+=subtask(rest-1,row,col+1);
        return res;
    }
    //dp 版本
    double dp_live_af_k(int k,int row,int col){
        vector<vector<vector<int>>> dp_table(k+1,vector<vector<int>>(M,vector<int>(N,0)));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                dp_table[0][j][i]=1;
            }
        }
        for(int r=1;r<k+1;r++){
            for(int x=0;x<M;x++){
                for(int y=0;y<N;y++){
                    int res=0;
                    bool C=check(x+1, y);
                    if(C)
                       res+=dp_table[r-1][x+1][y];
                    C=check(x-1, y);
                    if(C)
                       res+=dp_table[r-1][x-1][y];
                    C=check(x,y-1);
                    if(C)
                       res+=dp_table[r-1][x][y-1];
                    C=check(x, y+1);
                    if(C)
                       res+=dp_table[r-1][x][y+1];     
                    dp_table[r][x][y]=res;
                }
            }
        }
        double res= double(dp_table[k][row][col])/(double)pow(4,k);
        return res;
    }
    bool check(int x,int y){
        return (!((x<0)||(y<0)||(x>=M)||(y>=N)));
    }
    private:
    int M, N;
};

/*给定3个参数，N，M，K
怪兽有N滴血，等着英雄来砍自己
英雄每一次打击，都会让怪兽流失[0~M]的血量
到底流失多少？每一次在[0~M]上等概率的获得一个值
求K次打击之后，英雄把怪兽砍死的概率
*/
class kill_monster{
    public:
    kill_monster(int M ,int K,int N):M(M),N(N),K(K){

    }
    /*给定3个参数，N，M，K
     怪兽有N滴血，等着英雄来砍自己
     英雄每一次打击，都会让怪兽流失[0~M]的血量
     到底流失多少？每一次在[0~M]上等概率的获得一个值
     求K次打击之后，英雄把怪兽砍死的概率*/
    double rv_kill(){
        int n1=pow(M+1,K);
        int n2=subtask(N,K);
        return (double)n2/(double)n1;
    }
    int subtask(int rest_b,int rest_k){
     if(rest_k==0)
        return rest_b>0? 0:1;
     if(rest_b<=0){
        return pow(M+1,rest_k);
     }
     int ways=0;
     for(int i=0;i<=M;i++){
        ways+=subtask(rest_b-i,rest_k-1);
     }
     return ways;
    }
    double dp_monster(){
      vector<vector<int>> dp_table(N+1,vector<int>(K+1,0));
      dp_table[0][0]=1;
     for(int i=1;i<=K;i++){
        dp_table[0][i]=pow(M+1,i);
     }
      for(int k=1;k<K+1;k++){
       for(int b=1;b<N+1;b++){
           int ways=0;
           for(int i=0;i<=M;i++){ 
            if((b-i)>=0)       
               ways+=dp_table[b-i][k-1];
            else 
               ways+=pow(M+1,k-1);

           }
           dp_table[b][k]=ways;
       }
    }
    int n1=pow(M+1,K);
    int n2=dp_table[N][K];
    return  (double)n2/(double)n1;
    }
    private:
    int M;
    int K;
    int N; 
    };
int main(){
    /*
    Hanno h=Hanno(4);
    h.Hanno1();
    h.Hanno2();*/
    
    //print_sub_str ps=print_sub_str("abca");
    //ps.printsub();
    //ps.printorders();
    /*
    reverse_stack rs ;
    rs.push(5);
    rs.push(2);
    rs.push(3);
    rs.reverse();*/
    /*
    robot_move RB;
    int start=2;
    int N=10;
    int aim=8;
    int movement=8;
    int R1=RB.move1(start, N, aim,movement);
    int R2=RB.move2(start, N, aim,movement);
    int R3=RB.move1(start, N, aim,movement);
    cout<<R1<<" "<<R2<<" " <<R3;*/
    /*
    vector<int> card={100,50,25,900,34,5,103};
    cardplay cp =cardplay(card);
    int r1=cp.win1();
    int r2=cp.win2();
    int r3=cp.win3();
    cout<<r1<<" "<<r2<<" " <<r3;*/

    /*
    vector<int> weight{10,20,30,60,2,100};
    vector<int>value={110,20,90,50,7,90};
    int cap=50;
    backpacks bp=backpacks(weight,value,cap);
    int r1=bp.maxval();
    int r2=bp.maxval2();
    cout<<r1<<" "<<r2;*/
    /*    string data="10982453211817";
    intconvstr inv= intconvstr(data);
    cout<<inv.getconv()<<" "<<inv.getconv2();
   */
   /*
     jumphorse jp(0,2);
     cout<<jp.ways(10)<<endl;
     cout<<jp.ways_dp(10)<<endl;*/
     /*coffe cf;
     vector<int>mt={2,4,5,7};
     int nump=12;
     int washt=4;
     int selft=8;
     int tmp1=cf.mintime(mt, nump,  washt,  selft);
     int tmp2=cf.mintime_dp(mt, nump,  washt,  selft);
     cout<<tmp1;
     cout<<" "<<tmp2;*/
     /*
     //测试二维数组最小累加和的问题
     for(int i=0;i<100;i++){
      minsum ma(10,10,100);
      int result1=ma.getminsum1();
      int result2=ma.getminsum2();
      if(result1!=result2)
      {
        cout<<"error"<<endl;
        cout<<result1<<endl;
        cout<<result2<<endl;
        break;
      }
     }
      cout<<"finish"<<endl;*/
      /*
      //测试货币问题
      srand(time(NULL));
      for(int i=0;i<100;i++){
        int random=rand()%20;
        int random2=rand()%20;
        coinproblem1 cb(random,random2);
        int res1=cb.rec_getstrategy();
        int res2=cb.dp_getstrategy();
        if(res1!=res2){
            cout<<"error"<<endl;
            cout<<res1<<endl;
            cout<<res2<<endl;
            break;
        }     
      }
      cout<<"finish"<<endl;*/
      //测试货币问题无限制版本
      /*srand(time(NULL));
      for(int i=0;i<100;i++){
        int random=rand()%7+1;
        int random2=rand()%7+1;
        coinproblem2 cb(random,random2);
        int res1=cb.dp_stra2();
        int res2=cb.dp_stra();
        //cout<<res2<<endl;
        if(res1!=res2){
            cout<<"error"<<endl;
            cout<<res1<<endl;
            cout<<res2<<endl;
            break;
        }     
      }
      cout<<"finish"<<endl;*/
      //测试纸币有张数版本：
      /*
      srand(time(NULL));
      for(int i=0;i<100;i++){
        int random=rand()%7+1;
        int random2=rand()%7+1;
        coinproblem3 cb(random,random2);
        cb.convert();
        int res1=cb.dp_stra();
        int res2=cb.dp_stra2();
        //cout<<res2<<endl;
        if(res1!=res2){
            cout<<"error"<<endl;
            cout<<res1<<endl;
            cout<<res2<<endl;
            break;
        }     
      }
      cout<<"finish"<<endl;*/
      //测试BOB醉汉生存率问题
      /*
      srand(time(NULL));
      for(int i=0;i<100;i++){
        int random=rand()%7+1;
        int random2=rand()%7+1;
        BOB_LIVE bl(random,random2);
        int random3=rand()%10+1;
        int random4=rand()%random;
        int random5=rand()%random2;
        double res1=bl.live_af_k(random3,random4,random5);

        double res2=bl.dp_live_af_k(random3,random4,random5);
        //cout<<res2<<endl;
        if(res1!=res2){
            cout<<"error"<<endl;
            cout<<res1<<endl;
            cout<<res2<<endl;
            //break;
        }     
      }
      cout<<"finish"<<endl;*/
      //验证kill monster问题
      srand(time(NULL));
      for(int i=0;i<100;i++){
        int random=rand()%7+1;
        int random2=rand()%7+1;
        int random3=rand()%7+1;
        kill_monster km(random,random2,random3);
        double res1=km.rv_kill();
        double res2=km.dp_monster();
        //cout<<res2<<endl;
        if(res1!=res2){
            cout<<"error"<<endl;
            cout<<res1<<endl;
            cout<<res2<<endl;
            //break;
        }     
      }
      cout<<"finish"<<endl;
     return 0;

}