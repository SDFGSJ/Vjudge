#include<bits/stdc++.h>
using namespace std;
int main(){
    int days,i,j;
    while(~scanf("%d",&days) && days){
        multiset<int> s;    //allow duplicate values
        long long ans=0;
        for(i=0;i<days;i++){
            int k,num;
            scanf("%d",&k);
            for(j=0;j<k;j++){
                scanf("%d",&num);
                s.insert(num);
            }

            int M = *s.rbegin(), m = *s.begin(); //access the max,min num
            ans += M-m;

            //remove the max,min from the multiset
            s.erase(s.begin());
            s.erase(prev(s.end())); //move iterator s.end() 1 ahead, since s.end() points to nothing
        }
        printf("%lld\n",ans);
    }
    return 0;
}