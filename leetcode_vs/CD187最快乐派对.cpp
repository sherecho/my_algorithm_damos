#include <iostream>
#include<vector>

using namespace std;
struct person{
   int happy;
   vector<person*> subs;
   person(int happyval){
    this->happy=happyval;
   }
};
struct info{
    int no;
    int yes;
};
vector<person*> construct_Ntree(int& boss2){
     int n;
     cin>>n>>boss2;
     
     if(n<=0){
        vector<person*> ret0;
        return ret0 ;
     }
    vector<person*> ret(n);
     for(int i=0;i<n;i++){
     int tmpval;
     cin>>tmpval;
     ret[i]=new person(tmpval);
     }
     for(int i=0;i<n-1;i++){
        int boss,sub;
        cin>>boss>>sub;
        ret[boss-1]->subs.push_back(ret[sub-1]);
     }
    return ret;  
     
}
info * subtask(person* boss){
     info * ret=new info();
     if(boss->subs.empty()){
        ret->no=0;
        ret->yes=boss->happy;
        return ret;
     }
     int yes=boss->happy;
     int no=0; 
     for(person* sub:boss->subs){
        info * tmp=subtask(sub);
        yes+=tmp->no;
        no+=max(tmp->yes, tmp->no);
     }
     ret->no=no;
     ret->yes=yes;
     return ret;

}
int main() {
    int boss;
   vector<person*> company=construct_Ntree(boss);
   info* ret=subtask( company[boss-1]);
   cout<<max(ret->no,ret->yes);
}
// 64 位输出请用 printf("%lld")