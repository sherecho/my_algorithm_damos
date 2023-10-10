#include <iterator>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void bigger(vector<string> &words,vector<string>::size_type sz,ostream &os =cout){
    stable_sort(words.begin(),words.end());
    auto bigit=find_if(words.begin(),words.end(),[&sz](const string & a){return a.size()>sz;});
    for_each(bigit,words.end(),[&os](const string  &s){os<<s<<" ";});
    os<<endl;
}
int main(){
vector<string> words={"aa","bbbb","ccccc"};
bigger(words, 2);
    return 0;
}