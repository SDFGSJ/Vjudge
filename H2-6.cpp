#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> mymap; //<num,the array of indexs of num(1-based)>
int main(){
    int n,m,i;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++){
            int num;
            scanf("%d",&num);
            mymap[num].push_back(i);
        }
        
        /*for(auto& i:mymap){
            cout<<i.first<<":";
            for(auto j:i.second){
                cout<<j<<' ';
            }
            cout<<'\n';
        }*/

        for(i=0;i<m;i++){
            int k,v;    //k-th occurrence of v
            scanf("%d%d",&k,&v);
            if(mymap[v].size()<k || mymap.count(v)==0){
                printf("0\n");
            }else{
                printf("%d\n",mymap[v][k-1]);
            }
        }
    }
    return 0;
}