#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,i;
    cin>>t;
    while(t--){
        int len;
        string s,mymin;

        cin>>s;
        len=s.length();
        mymin=s;
        
        for(i=0;i<len;i++){ //perform shifting to find the lexicographically smallest string
            char first=s[0];
            s+=first;
            s.erase(0,1);
            if(s<mymin){
                mymin=s;
            }
        }
        cout<<mymin<<'\n';
    }
    return 0;
}