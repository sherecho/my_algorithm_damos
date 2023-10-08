/*
C++自己定义比较器
-1.定义函数
-2.操作符重载
-3.lamada 函数

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool customComparator(int a, int b) {
    // 自定义排序规则：按绝对值从小到大排序
    //return std::abs(a) < std::abs(b);
    return a>b;//从大到小排序
}
bool comparator2(string a,string b){
    return (a+b).compare(b+a);// (a+b)>(b+a)
}
int main() {
    std::vector<int> numbers = {-3, 2, -1, 5, -4};
    vector<string>strigs={"a","asd","bc"};
    //std::sort(numbers.begin(), numbers.end(), customComparator);
    //lamada表达式
    std::sort(numbers.begin(),numbers.end(),[](int &a,int&b){return a>b;});
    sort(strigs.begin(),strigs.end(),comparator2);
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    cout<<endl;
    for(auto s:strigs){
        cout<<s;
    }
    return 0;
}
