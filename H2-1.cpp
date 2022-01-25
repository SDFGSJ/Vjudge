#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while(1){
        cin>>s;
        if(s=="END"){
            break;
        }
        
        //beware of special case
        if(s=="1"){
            printf("1\n");
        }else if(s=="0" || s.length()==1){
            printf("2\n");
        }else if(1<s.length() && s.length()<10){
            printf("3\n");
        }else{
            printf("4\n");
        }
    }
    return 0;
}