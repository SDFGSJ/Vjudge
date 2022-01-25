#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long sum,diff;
        scanf("%lld%lld",&sum,&diff);
        if(sum<diff || (sum+diff)%2==1){    //score cant have floating point
            printf("impossible\n");
        }else{
            long long big=(sum+diff)/2;
            long long small=(sum-diff)/2;
            printf("%lld %lld\n",big,small);
        }
    }
    return 0;
}