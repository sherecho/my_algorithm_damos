#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main (){
   /* vector<int> vector1(10,9);

    //遍历容器的方式：
    //1.下标：
    cout<<"1:";
    for(int i=0;i<vector1.size();i++){
        cout<<vector1[i]<<" ";
    }
    cout<<endl;
    //2.迭代器
    cout<<"2:";
    for(vector<int>:: iterator it=vector1.begin();it!=vector1.end();it++){
       cout<<*it<<" ";
    }
    cout<<endl;
    //3.迭代器+auto
    cout<<"3:";
    for(auto it=vector1.begin();it!=vector1.end();it++){
        *it=4;
       cout<<*it<<" ";
    }
    cout<<endl;
    //只读迭代器
    cout<<"常迭代器：";
    for(vector<int>::const_iterator it=vector1.begin();it!=vector1.end();it++){
        //*it=4;//报错
        cout<<*it<<" ";
    }
    cout<<endl;*/
    vector<string> words={"aa","bbbb","ccccc"};
    int sz=4;
    auto v=find_if(words.begin(),words.end(),[sz](const string &a){return a.size()>=sz;});
    cout<<*v;
    return 0;
}