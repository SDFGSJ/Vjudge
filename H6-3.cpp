#include<bits/stdc++.h>
using namespace std;

char grid[105][105];
bool visited[105][105];
int di[8]={-1,-1,-1, 0, 1, 1, 1, 0};
int dj[8]={-1, 0, 1, 1, 1, 0,-1,-1};
int ans,n,m;

void dfs(int r,int c){
    int i;
    if(grid[r][c]=='L' || visited[r][c]){
        return;
    }

    ans++;  //grid[r][c] must be 'W'
    for(i=0;i<8;i++){
        if(0<=r+di[i] && r+di[i]<n && 0<=c+dj[i] && c+dj[i]<m){ //check boundary here
            visited[r][c]=true;
            dfs(r+di[i],c+dj[i]);
        }
    }
}

int main(){
    int t,r,c,i,j;
    char str[105];
    scanf("%d",&t);
    getchar();  //the blank line
    for(i=0;i<=t;i++){  //magic try, no reason
        memset(grid,0,sizeof(grid));
        n=m=0;  //record the size of the grid(n*m)
        while(fgets(str,105,stdin)){
            int len=strlen(str);
            str[len-1]='\0';    //since fgets will read in '\n',replace it with '\0'
            if(str[0]=='\0'){   //blank line
                break;
            }
            if(isdigit(str[0])){
                sscanf(str,"%d %d",&r,&c);  //read number from string
                memset(visited,false,sizeof(visited));
                ans=0;
                dfs(r-1,c-1);
                printf("%d\n",ans);
            }else{
                sscanf(str,"%s",grid[n]);
                n++;
                if(m==0){
                    m=strlen(str);
                }
            }
        }
        if(i!=0 && i!=t){
            printf("\n");
        }
    }
    return 0;
}