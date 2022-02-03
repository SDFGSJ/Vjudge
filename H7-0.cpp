#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r,suml=0,sumr=0;
        scanf("%d%d",&l,&r);
        while(l > 0){
            suml+=l;
            l/=10;
        }
        
        while(r > 0){
            sumr+=r;
            r/=10;
        }
        
        //the number of changed digits from l~r = 0~r - 0~l
        printf("%d\n",sumr-suml);
    }
    return 0;
}