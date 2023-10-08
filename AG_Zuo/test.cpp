#include<iostream>
int main() {
    std::string input;

    // 从标准输入读取一行文本并存储到 input 中
    std::cout << "Enter a line of text: "<<std::endl;
    std::getline(std::cin, input);

    // 输出读取的文本
    std::cout << "You entered: " << input << std::endl;
    int a;
    const int * p=&a;
    int const*b=&a;
    int d=0;
    b=&d;
    int * const f =&a;
    *f=9;
    f=&b;
    return 0;
}