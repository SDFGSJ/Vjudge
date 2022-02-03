#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,h,i;
    while(~scanf("%d%d",&w,&h)){
        map<pair<int,int>,int> m;   //<(small,big),cnt>
        vector<pair<int,int>> mypair;
        vector<int> mycnt;
        bool good=true;

        auto p=make_pair(min(w,h),max(w,h));    //always put the smaller number at the front,max at back
        m[p]++;
        for(i=0;i<5;i++){
            scanf("%d%d",&w,&h);
            p=make_pair(min(w,h),max(w,h));
            m[p]++;
        }


        for(auto i:m){
            mypair.push_back(i.first);
            mycnt.push_back(i.second);
        }

        if(m.size()==1){    //square*6
            good=true;
        }else if(m.size()==2){  //square*2, rectangle*4
            /*
            (a,a) || (a,b)
            (a,b) || (b,b)
            a<b
            */
            if(mycnt[0]+mycnt[1]!=6 || abs(mycnt[0]-mycnt[1])!=2){  //check cnt
                good=false;
            }else{  //check size
                /*
                might have the case = square*4,rectangle*2,need to check count
                */
                if((mypair[0].first==mypair[1].first && mypair[0].second!=mypair[1].second && mycnt[0]==2 && mycnt[1]==4) ||
                    (mypair[0].first!=mypair[1].first && mypair[0].second==mypair[1].second && mycnt[0]==4 && mycnt[1]==2)){
                    good=true;
                }else{
                    good=false;
                }
            }
        }else if(m.size()==3){  //3 different rectangles, each kind*2
            /*
            (a,b) => mypair[0]
            (a,c)
            (b,c) => mypair[2]
            a is smallest,c is largest
            */
            if(mycnt[0]!=2 || mycnt[1]!=2 || mycnt[2]!=2){
                good=false;
            }else{
                if(mypair[0].first!=mypair[1].first ||
                    mypair[0].second!=mypair[2].first ||
                    mypair[1].second!=mypair[2].second){
                        good=false;
                }
            }
        }else{  //more than 4 kinds of rectangles
            good=false;
        }

        if(!good){
            printf("IMPOSSIBLE\n");
        }else{
            printf("POSSIBLE\n");
        }
    }
    return 0;
}