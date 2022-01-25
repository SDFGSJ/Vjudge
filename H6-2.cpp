#include<bits/stdc++.h>
using namespace std;
int num[1005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,i;
    while(cin>>n && n!=0){
        while(cin>>num[0] && num[0]!=0){
            bool good=true;
            stack<int> a,station;
            for(i=n;i>=1;i--){
                a.push(i);
            }
            for(i=1;i<n;i++){
                cin>>num[i];
            }


            for(i=0;i<n;i++){
                if(!station.empty() && station.top()==num[i]){    //take from station
                    station.pop();
                }else{  //take from A
                    while(!a.empty() && a.top()!=num[i]){
                        station.push(a.top());
                        a.pop();
                    }

                    if(!a.empty() && a.top()==num[i]){
                        a.pop();
                    }else{
                        good=false;
                        break;
                    }
                }
            }

            if(good){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}