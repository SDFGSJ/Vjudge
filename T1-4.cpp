#include<bits/stdc++.h>
using namespace std;
int a[1000010];
long long ans;

void mymerge(int l,int m,int r){
    vector<int> tmp;

    //merge two subarrays [l,m], [m+1,r]
    int i=l,j=m+1;
    while(i<=m && j<=r){
        if(a[i]<a[j]){
            tmp.push_back(a[i]);
            i++;
        }else{
            tmp.push_back(a[j]);
            ans += m-i+1;   //count the inverse pairs
            j++;
        }
    }

    //the rest of subarray
    for(;i<=m;i++){
        tmp.push_back(a[i]);
    }
    for(;j<=r;j++){
        tmp.push_back(a[j]);
    }

    //copy the sorted part to original array
    copy(tmp.begin(),tmp.end(),a+l);
}

void merge_sort(int l,int r){
    if(l>=r){
        return;
    }else{
        int mid=(l+r)/2;
        merge_sort(l,mid);  //[l,mid]
        merge_sort(mid+1,r);    //[mid+1,r]
        mymerge(l,mid,r);
    }
}
int main(){
    int n,i;
    while(~scanf("%d",&n) && n){
        ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        merge_sort(0,n-1);  //sort the array [0,n-1]
        printf("%lld\n",ans);
    }
    return 0;
}