#include<bits/stdc++.h>
using namespace std;
int seq[200010],ans[200010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        map<int,vector<int>> m; //<number,array of appear index>
 
        /*to ensure that the number of every color is the same,
        which means that idx.size()%k must == 0*/
        vector<int> idx;
 
        int n,k;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){
            scanf("%d",&seq[i]);
            m[seq[i]].push_back(i);
        }
 
        //pick the index and make sure that idx.size()%k==0
        for(auto item:m){
            for(i=0;i < min( (int)item.second.size(), k);i++){
                idx.push_back(item.second[i]);
            }
        }
        //need to remove (tmp%k) numbers from idx
        int tmp=idx.size();
        for(i=0;i<tmp%k;i++){
            idx.pop_back();
        }
 
        //painting
        int color=0;    //starting from 0 is only for convenience
        for(auto i:idx){
            ans[i]=color+1;
            color++;
            color%=k;
        }
 
        for(i=0;i<n;i++){
            printf("%d ",ans[i]);
            ans[i]=0;   //remember to reset
        }
        printf("\n");
    }
    return 0;
}