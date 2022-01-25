#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,i;
    cin>>n;
    cin.ignore();
    while(n--){
        stack<char> s;
        string str;
        bool good=true;

        getline(cin,str);
        for(i=0;str[i]!='\0';i++){
            if(str[i]=='(' || str[i]=='['){
                s.push(str[i]);
            }else{
                if(s.empty()){
                    good=false;
                    break;
                }

                if( (s.top()=='(' && str[i]==')') ||
                    (s.top()=='[' && str[i]==']') ){
                    s.pop();
                }else{
                    good=false;
                }
            }
        }
        if(good && s.empty()){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}