#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<string> s;
    int n;
    cin>>n;
    while(n--){
        string op;
        cin>>op;
        if(op=="Sleep"){
            string name;
            cin>>name;
            s.push(name);
        }else if(op=="Kick"){
            if(!s.empty()){
                s.pop();
            }
        }else{  //Test
            if(!s.empty()){
                cout<<s.top()<<'\n';
            }else{
                cout<<"Not in a dream\n";
            }
        }
    }
    return 0;
}