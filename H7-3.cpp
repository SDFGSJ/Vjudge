#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> pq;    //min heap
    int n,num,i;
    while(~scanf("%d",&n) && n){
        long long cost=0;
        for(i=0;i<n;i++){
            scanf("%d",&num);
            pq.push(num);
        }

        //everytime pick the 2 smallest numbers to add,not just add from small to large
        while(pq.size()>1){
            int a=pq.top();pq.pop();
            int b=pq.top();pq.pop();
            cost+=a+b;
            if(pq.size()==0){   //if pq is already empty,then no need to push back result
                break;
            }
            pq.push(a+b);
        }
        printf("%lld\n",cost);
    }
    return 0;
}