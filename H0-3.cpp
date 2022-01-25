#include<bits/stdc++.h>
using namespace std;
char str[85];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int c=0, h=0, o=0, n=0;
        for(i=0;str[i]!='\0';){
            int num=0;
            if('A'<=str[i] && str[i]<='Z'){    //CHON
                char tmp=str[i];

                if('0'<=str[i+1] && str[i+1]<='9'){ //next char is number, count total
                    while('0'<=str[i+1] && str[i+1]<='9'){
                        num=num*10+str[i+1]-'0';
                        i++;
                    }
                }else{  //only one element, num=1
                    num=1;
                    i++;
                }

                if(tmp=='C'){
                    c+=num;
                }else if(tmp=='H'){
                    h+=num;
                }else if(tmp=='O'){
                    o+=num;
                }else if(tmp=='N'){
                    n+=num;
                }
            }else{  //number
                i++;
            }
        }
        printf("%.3f\n", 12.01*c + 1.008*h + 16*o + 14.01*n);
    }
    return 0;
}