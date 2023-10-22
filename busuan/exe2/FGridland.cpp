#include <cmath>
#include<iostream>
#include<vector>
#include "stdlib.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int line=1;
    while(n>0){
        n--;

        int n1,n2;
        cin>>n1>>n2;
        cout<<"Scenario #"<<line<<":"<<endl;
        line++;
        float rs;
        if(n1%2==0||n2%2==0){         
           rs=n1*n2;
        }
        else 
        rs=n1*n2-1+sqrt(2);
        printf("%.2f\n",rs);
    }
}