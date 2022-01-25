#include<bits/stdc++.h>
using namespace std;
int code[1010],guess[1010];
int main(){
    int n,cnt=1,i;
    while(~scanf("%d",&n) && n){
        printf("Game %d:\n",cnt);
        cnt++;
        map<int,vector<int>> m; //<value,idx>
        for(i=0;i<n;i++){
            scanf("%d",&code[i]);
            m[code[i]].push_back(i);    //record each number's idx
        }

        while(scanf("%d",&guess[0])){
            int idx[10];    //idx[i]=the current idx of i
            int strong=0,weak=0;

            for(i=1;i<n;i++){
                scanf("%d",&guess[i]);
            }
            if(guess[0]==0){
                break;
            }

            for(i=0;i<10;i++){
                idx[i]=0;
            }
            
            //find the strong match
            for(i=0;i<n;i++){
                if(code[i]==guess[i]){
                    strong++;
                    idx[code[i]]++;
                    guess[i]=0; //assign this number to a num that wouldnt appear
                }
            }

            for(i=0;i<n;i++){
                if(guess[i]!=0){    //not strong match
                    //this num is in dict && just in the wrong position
                    if(m.count(guess[i]) && idx[guess[i]] < m[guess[i]].size()){
                        weak++;
                        idx[guess[i]]++;
                    }
                }
            }
            printf("    (%d,%d)\n",strong,weak);
        }
    }
    return 0;
}