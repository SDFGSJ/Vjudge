#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int h,m;
        scanf("%d:%d",&h,&m);
        if(h==0 && m==0){
            break;
        }
        double delta = abs(30*h - 11*m/2.0);
        printf("%.3f\n",min(delta,360-delta));
    }
    return 0;
}