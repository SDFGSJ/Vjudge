#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,num;
    while(~scanf("%d%d",&a,&b)){
        set<int> s; //record which num has appeared in order to detect cycle
        vector<int> v;  //record the order of num in order to print out the cycle

        num=(a%b)*10;
        while(s.count(num)==0 && num!=0){   //keep dividing until we meet a cycle
            s.insert(num);
            v.push_back(num);
            num=(num%b)*10;
        }

        printf("%d/%d = %d.",a,b,a/b);
        if(num==0){ //completely divided
            for(auto i:v){
                printf("%d",i/b);
            }
            printf("(0)\n   1 = ");
        }else{
            auto dup = find(v.begin(),v.end(),num);   //find the duplicate number
            for(auto it=v.begin();it!=dup;it++){    //non cycle part
                printf("%d",*it/b);
            }

            printf("(");
            auto it=dup;
            for(;it!=v.end() && it-v.begin()<50;it++){  //print the first 50 digits
                printf("%d",*it/b);
            }
            if(v.size()>50){
                printf("...");
            }
            printf(")\n");

            printf("   %d = ",v.size()-(dup-v.begin()));
        }
        printf("number of digits in repeating cycle\n\n");
    }
    return 0;
}