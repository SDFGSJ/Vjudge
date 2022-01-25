#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j;
    string s,t;
    while(cin>>s>>t){
        i=j=0;
        int slen=s.length(),tlen=t.length();
        while(i<slen && j<tlen){
            if(s[i]==t[j]){
                i++,j++;
            }else{
                j++;
            }
        }
        if(i==slen){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}