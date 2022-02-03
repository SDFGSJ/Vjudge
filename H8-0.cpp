#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n) && n){
        int a=0, b=0, cnt=1, digit=0;
        while(n!=0){
            if(n&1){    //rightmost num=1
                if(cnt%2){  //add to a(cnt=1,3,5...)
                    a+=(1<<digit);
                }else{  //add to b(cnt=2,4,6...)
                    b+=(1<<digit);
                }
                cnt++;
            }
            digit++;
            n>>=1;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}