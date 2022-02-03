#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,l,r;
        long long ans=0;
        scanf("%d%d%d",&n,&l,&r);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        //only care about how many pairs that meet the constraints,idx doesnt matter,so can sort and use binary search
        sort(a,a+n);
        for(i=0;i<n;i++){
            ans+=upper_bound(a+i+1,a+n,r-a[i])-lower_bound(a+i+1,a+n,l-a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}