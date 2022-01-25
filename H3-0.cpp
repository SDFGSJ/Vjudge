#include<bits/stdc++.h>
using namespace std;
bool palin(string str){
    int i;
    int len=str.length();
    for(i=0;i<len/2;i++){
        if(str[i]!=str[len-1-i]){
            return false;
        }
    }
    return true;
}
bool mirror(string str){
    map<char,char> mymap={
        {'A','A'},
        {'E','3'},
        {'H','H'},
        {'I','I'},
        {'J','L'},
        {'L','J'},
        {'M','M'},
        {'O','O'},
        {'S','2'},
        {'T','T'},
        {'U','U'},
        {'V','V'},
        {'W','W'},
        {'X','X'},
        {'Y','Y'},
        {'Z','5'},
        {'1','1'},
        {'2','S'},
        {'3','E'},
        {'5','Z'},
        {'8','8'}
    };
    int i;
    int len=str.length();

    string origin(str.begin(),str.end());
    
    for(i=0;i<len;i++){
        if(mymap.count(str[i])!=0){
            str[i]=mymap[str[i]];
        }else{  //if this char doesnt have a reverse,it wont be mirror string
            return false;
        }
    }
    string final(str.rbegin(),str.rend());

    if(final==origin){
        return true;
    }else{
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while(cin>>s){
        bool is_palin=palin(s);
        bool is_mirror=mirror(s);
        
        if(is_palin && is_mirror){
            cout<<s<<" -- is a mirrored palindrome.\n\n";
        }else if(!is_palin && is_mirror){
            cout<<s<<" -- is a mirrored string.\n\n";
        }else if(is_palin && !is_mirror){
            cout<<s<<" -- is a regular palindrome.\n\n";
        }else if(!is_palin && !is_mirror){
            cout<<s<<" -- is not a palindrome.\n\n";
        }
    }
    return 0;
}