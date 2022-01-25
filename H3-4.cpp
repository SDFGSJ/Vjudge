#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--){
        string a,b,result;
        cin>>a>>b;

        //remove the tail 0
        string a_trim(a.begin(),a.begin() + a.find_last_not_of('0')+1);
        string b_trim(b.begin(),b.begin() + b.find_last_not_of('0')+1);

        //reverse the string
        string a_rev(a_trim.rbegin(),a_trim.rend());
        string b_rev(b_trim.rbegin(),b_trim.rend());

        //perform the addition
        int i,j,num,carry=0;
        int alen=a_rev.length(), blen=b_rev.length();
        for(i=alen-1, j=blen-1; i>=0 && j>=0; i--, j--){
            num=carry+(a_rev[i]-'0')+(b_rev[j]-'0');
            if(num>=10){
                result.insert(0,1,num-10+'0');
                carry=1;
            }else{
                result.insert(0,1,num+'0');
                carry=0;
            }
        }

        //add the remaining numbers,beware of the carry in
        for(;i>=0;i--){
            num=a_rev[i]-'0'+carry;
            if(num>=10){
                result.insert(0,1,num-10+'0');
                carry=1;
            }else{
                result.insert(0,1,num+'0');
                carry=0;
            }
        }
        for(;j>=0;j--){
            num=b_rev[j]-'0'+carry;
            if(num>=10){
                result.insert(0,1,num-10+'0');
                carry=1;
            }else{
                result.insert(0,1,num+'0');
                carry=0;
            }
        }

        //beware of the final carry in,or you might loss one digit
        if(carry==1){
            result.insert(0,1,'1');
        }
        
        int nonzero_pos = result.find_last_not_of('0');
        string result_trim(result.begin(), result.begin() + nonzero_pos+1);
        string result_rev(result_trim.rbegin(), result_trim.rend());
        cout<<result_rev<<'\n';
    }
    return 0;
}