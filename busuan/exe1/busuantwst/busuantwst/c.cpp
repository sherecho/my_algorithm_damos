#include<string>
#include<vector>
#include<iostream>
using namespace std;
enum POS{
    pleft,
    pright,
    pnone
};
enum Condition{
     cfalse,
     ctrue,
     cwait
};
int main(){
    int casenum;
    cin>>casenum;
    while(casenum>0){
        vector<vector<string>> scentence(3,vector<string>(3,""));

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
              cin>>scentence[i][j];
        }
        for(int i=0;i<12;i++){
            char abl=(char)('A'+i);
            //test light
            POS pos;
            //bool isfalse;
            //bool islight;
            Condition condition=cwait;
            for(int sc=0;sc<3;sc++){
                if(scentence[sc][0].find(abl)!=string::npos){
                    pos=pleft;
                }
                else if (scentence[sc][1].find(abl)!=string::npos) {
                 pos=pright;
                }
                else {
                 pos=pnone;
                }
                switch (pos) {
                  case pleft:
                   if(scentence[sc][2]!="down")
                      condition=cfalse;
                    else
                     condition=cwait;
                  break;
                  case pright:
                    if(scentence[sc][2]!="up")
                      condition=cfalse;
                    else
                     condition=cwait;
                  break;   
                  case pnone:
                    if(scentence[sc][2]!="even")
                      condition=cfalse;
                    else
                      condition=cwait;              
                  break;
                }
                if(condition==cfalse)
                   break;
            }
            //三条语句都通过
            if(condition==cwait)
              {
                cout<<abl<<" is the counterfeit coin and it is light."<<endl;
                break;
              }
            //test heavy
            condition=cwait;
            for(int sc=0;sc<3;sc++){
                if(scentence[sc][0].find(abl)!=string::npos){
                    pos=pleft;
                }
                else if (scentence[sc][1].find(abl)!=string::npos) {
                 pos=pright;
                }
                else {
                 pos=pnone;
                }
                switch (pos) {
                  case pleft:
                   if(scentence[sc][2]!="up")
                      condition=cfalse;
                    else
                     condition=cwait;
                  break;
                  case pright:
                    if(scentence[sc][2]!="down")
                      condition=cfalse;
                    else
                     condition=cwait;
                  break;   
                  case pnone:
                    if(scentence[sc][2]!="even")
                      condition=cfalse;
                    else
                      condition=cwait;              
                  break;
                }
                if(condition==cfalse)
                   break;
            }
            //三条语句都通过
            if(condition==cwait)
              {
                cout<<abl<<" is the counterfeit coin and it is heavy."<<endl;
                break;
              }
            
        }
        casenum--;
    }
    return 0;
}