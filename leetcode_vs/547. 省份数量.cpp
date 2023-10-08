#include<vector>
using namespace std;
class djset{
    public:
    vector<int>parents;
    vector<int>rank;
    vector<int> helpstack;
    int sets;
    djset(int num=0):parents(num),rank(num,1),helpstack(num*2,-1){
        for(int i=0;i<num;i++){
            parents[i]=i;
        }
        sets=num;
    }
    int findfirst(int index){
        int hel=0;
        while(parents[index]!=index){
             helpstack[hel++]=index;
             index=parents[index];
        }
        hel=hel-1;
        while(hel>=0){
            parents[helpstack[hel]]=index;
            hel--;
        }
        return index;
    }
    void union_set(int ind1,int ind2){
        int head1=findfirst(ind1);
        int head2=findfirst(ind2);
        if(head1==head2)
           return;
        int big=rank[head1]>=rank[head2]?head1:head2;
        int low=rank[head1]<rank[head2]?head1:head2;
        parents[low]=parents[big];
        rank[big]=rank[big]+rank[low];
        sets--;
    }
};

class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
       int N=isConnected.size();
       djset D=djset(N);
       for(int i=0;i<N;i++){
           for(int j=i+1;j<N;j++){
               if(isConnected[i][j]==1){
                   D.union_set(i,j);
               }
           }
           
       }
       return D.sets;
    }
};