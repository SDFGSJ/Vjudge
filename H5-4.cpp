#include<bits/stdc++.h>
using namespace std;
int solve(int x,int y,int n){   //x**y % n
    if(y==0){
        return 1%n;
    }else if(y==1){
        return x%n;
    }

    int half=solve(x,y/2,n);
    if(y%2==0){
        return ((half%n)*(half%n))%n;
    }else{
        return ((((x%n)*(half%n))%n)*(half%n))%n;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y,n,ans=0;
        scanf("%d%d%d",&x,&y,&n);
        ans=solve(x,y,n);
        printf("%d\n",ans);
    }
    return 0;
}