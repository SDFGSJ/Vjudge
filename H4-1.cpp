#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,num,i;
    while(~scanf("%d%d",&n,&m) && n!=0 && m!=0){
        set<int> jack,jill;
        int ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&num);
            jack.insert(num);
        }
        for(i=0;i<m;i++){
            scanf("%d",&num);
            jill.insert(num);
        }

        for(auto i:jack){
            if(jill.count(i)>0){
                ans++;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}