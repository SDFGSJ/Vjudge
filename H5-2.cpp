#include<bits/stdc++.h>
using namespace std;
bool appear[200010];
int a[200010];
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    for(i=m-1;i>=0;i--){
        if(!appear[a[i]]){
            printf("%d\n",a[i]);
            appear[a[i]]=true;
        }
    }
    for(i=1;i<=n;i++){
        if(!appear[i]){
            printf("%d\n",i);
            appear[i]=true;
        }
    }
    return 0;
}