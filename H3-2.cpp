#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,i,j;
    cin>>t;
    while(t--){
        vector<string> v;
        string result;
        int n,len,sum=0;
        cin>>n>>len;
        for(i=0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        for(i=0;i<len;i++){
            int cnt[26];
            for(j=0;j<26;j++){
                cnt[j]=0;
            }
            for(auto s:v){  //get the i-th char of each string
                cnt[s[i]-'A']++;
            }

            int* mymax=max_element(cnt,cnt+26); //returns an iterator
            sum += n - *mymax;
            
            result.push_back('A'+mymax-cnt);
        }
        cout<<result<<'\n'<<sum<<'\n';
    }
    return 0;
}