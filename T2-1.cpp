#include<bits/stdc++.h>
using namespace std;
int a[100010];
map<int,int> m; //<num,cnt>
set<int> s; //record the numbers that only appear once
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
 
    //the first k elements
    for(i=0;i<k;i++){
        m[a[i]]++;
    }
    for(auto i:m){
        if(i.second==1){
            s.insert(i.first);
        }
    }
    if(s.size()==0){    //the first k elements may not have ans, need to judge first, or will get RE
        printf("Nothing\n");
    }else{
        printf("%d\n",*s.rbegin());
    }
 
    for(i=k;i<n;i++){
        //erase old element
        m[a[i-k]]--;
        if(m[a[i-k]]==1){   //exactly 1 element in current sliding window, add to set
            s.insert(a[i-k]);
        }else if(m[a[i-k]]==0){ //more than 1 element, erase from map & set
            m.erase(a[i-k]);
            s.erase(a[i-k]);
        }
 
        //add new element
        m[a[i]]++;
        if(m[a[i]]==1){
            s.insert(a[i]);
        }else{
            s.erase(a[i]);
        }

        if(s.size()==0){
            printf("Nothing\n");
        }else{
            printf("%d\n",*s.rbegin());
        }
    }
    return 0;
}