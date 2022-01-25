#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,ans,tmp,mymin=0;
        scanf("%d",&n);
        for(i=n-1;i>=n-45;i--){ //start from n-1 to n-45,since n<10**6
            ans=i,tmp=i;
            while(tmp!=0){
                ans+=tmp%10;
                tmp/=10;
            }
            if(ans==n){
                mymin=i;
            }
        }
        if(i>n){
            printf("0\n");
        }else{
            printf("%d\n",mymin);
        }
    }
    return 0;
}