#include<bits/stdc++.h>
using namespace std;
char a[105],b[105];
int solve(char* a,int alen,char* b,int blen){
    int i,j,ans=0;
    bool haveans=false; //true if two string can overlap fully or partially

    for(i=0;i<alen;i++){
        for(j=0;j<blen;j++){
            if(i+j<alen && a[i+j]-'0'+b[j]-'0'>3){
                break;
            }
        }
        if(j==blen){    //is overlap
            haveans=true;
            break;
        }
    }

    if(haveans){
        if(i+blen<=alen){   //fully overlap(the shorter string is in longer string)
            ans=alen;
        }else{  //partially overlap
            ans=i+blen;
        }
    }else{  //doesnt overlap at all
        ans=alen+blen;
    }
    return ans;
}
int main(){
    int i,j,alen,blen;
    while(~scanf("%s%s",a,b)){
        bool haveans=false;

        alen=strlen(a),blen=strlen(b);
        if(alen<blen){
            swap(a,b);
            swap(alen,blen);
        }
        
        int num1=solve(a,alen,b,blen);
        int num2=solve(b,blen,a,alen);
        printf("%d\n",min(num1,num2));
    }
    return 0;
}