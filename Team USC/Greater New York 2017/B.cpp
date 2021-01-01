#include<bits/stdc++.h>
using namespace std;
int r,c,g[11][11],compo;
char buf[10],used[50][15];
#define for0(i,j) for(int i=0;i<j;++i)
vector<pair<int,int>>com[50];
using pii=pair<int,int>;
bool tryput(int i,int j,int v){
    for(int di=-1;di<=1;++di)for(int dj=-1;dj<=1;++dj)
        if(g[i+di][j+dj]==v)return false;
    g[i][j]=v;
    return true;
}
void solve(int id,int index){
    //cout<<"solve "<<id<<' '<<index<<endl;
    if(id==compo){
        //found
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                printf(j==c?"%d\n":"%d ",g[i][j]);
            }
        }
        exit(0);
    }
    auto&c=com[id];
    if(index==c.size()){
        solve(id+1,0);
        return;
    }
    int x,y;
    tie(x,y)=c[index];

    if(g[x][y]){
        solve(id,index+1);
        return;
    }

    for(int k=1;k<=c.size();++k)if(!used[id][k]&&tryput(x,y,k)){
        used[id][k]=1;
        solve(id,index+1);
        used[id][k]=0;
        g[x][y]=0;
    }
}
int main(){
    scanf("%d%d",&r,&c);getchar();
    for(int i=1;i<=r;++i)for(int j=1;j<=c;++j){
        char x=getchar();getchar();
        if(isdigit(x))g[i][j]=x-'0';
    }
    /*
    for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                printf(j==c?"%d\n":"%d ",g[i][j]);
            }
        }
        */
    scanf("%d",&compo);
    //cout<<"comp o "<<compo<<endl;
    for0(i,compo){
        int sz;
        scanf("%d",&sz);
        while(sz--){
            scanf("%s",buf);
            com[i].emplace_back(buf[1]-'0',buf[3]-'0');
        }
            int unfill=0;
         for(auto&x:com[i])if(!g[x.first][x.second])++unfill;else{
                used[i][g[x.first][x.second]]=1;
            }
        //for(auto&&x:com[i])cout<<'('<<x.first<<' '<<x.second<<')';cout<<endl;
    }
    solve(0,0);
}