#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<long long> s;  //may have duplicate numbers
    long long n;    //beware of intmax + intmax
    while(~scanf("%lld",&n)){
        s.insert(n);
        int cnt=0;
        auto it=s.begin();
        if(s.size()%2){ //odd
            for(;cnt!=s.size()/2;cnt++, it++){}
            printf("%lld\n",*it);
        }else{  //even
            for(;cnt!=s.size()/2 - 1;cnt++, it++){}
            auto l=it, r=++it;  //first increment,then assign
            printf("%lld\n",((*l)+(*r))/2);
        }
    }
    return 0;
}