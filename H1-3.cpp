#include<bits/stdc++.h>
using namespace std;
vector<bool> isprime(1000010,true);
set<int> prime; //a set of prime numbers
int main(){
    int t,i,j;
    
    //create a prime table first
    isprime[0]=isprime[1]=false;
    for(i=2;i*i<=1000010;i++){
        if(!isprime[i]){
            continue;
        }
        for(j=i*i;j<=1000010;j+=i){
            isprime[j]=false;
        }
    }
    for(i=0;i<=1000000;i++){
        if(isprime[i]){
            prime.insert(i);
        }
    }


    scanf("%d",&t);
    while(t--){
        int n,e;
        scanf("%d%d",&n,&e);
        vector<int> a(n+5,0);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        
        //only need to focus on prime numbers,dont care about 1's
        long long ans=0ll;
        for(i=1;i<=n;i++){
            long long left=0ll, right=0ll;
            if(prime.count(a[i])){
                int l=i-e, r=i+e;

                //start from a[i-e],count the number of consecutive 1's(1-e, 1-2e, 1-3e, ...)
                while(l>=1 && a[l]==1){
                    l-=e;
                    left++;
                }

                //start from a[i+e],count the number of consecutive 1's(1+e, 1+2e, 1+3e, ...)
                while(r<=n && a[r]==1){
                    r+=e;
                    right++;
                }
            }
            
            //l*r is the combination, left,right both pick one number,which can form a valid range
            ans = ans + left + right + left*right;
        }
        printf("%lld\n",ans);
    }
    return 0;
}