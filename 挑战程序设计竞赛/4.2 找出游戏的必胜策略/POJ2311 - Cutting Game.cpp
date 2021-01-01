/*#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>

using namespace std;

int G[234][234];
int m, n;

int dfs(int u, int v)
{
    if(G[u][v] != -1) return G[u][v];
    set<int> s;
    for(int i = 2; i < u - 1; i++) s.insert(dfs(u - i, v) ^ dfs(i, v));
    for(int i = 2; i < v - 1; i++) s.insert(dfs(u, v - i) ^ dfs(u, i));
    int ans = 0;
    while(s.count(ans)) ans++;
    return G[u][v] = ans;
}

int main()
{
    memset(G, -1, sizeof G);
    G[1][1] = 0;
    while(~scanf("%d%d", &n, &m))
    {
        if(!dfs(n, m)) puts("LOSE");
        else puts("WIN");
    }
    return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define LL long long
using namespace std;
int sg[205][205];
int get_sg(int n,int m){
    if(sg[n][m]!=-1)
        return sg[n][m];
    int vis[1005];
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n-i;i++)
        vis[get_sg(i,m)^get_sg(n-i,m)]=1;
    for(int i=2;i<=m-i;i++)
        vis[get_sg(n,i)^get_sg(n,m-i)]=1;
    for(int i=0;;i++)
        if(vis[i]==0)
            return sg[n][m]=i;
}
int main(){
    int n,m;
    memset(sg,-1,sizeof(sg));
    while(scanf("%d%d",&n,&m)!=EOF)
        if(get_sg(n,m))
            printf("WIN\n");
        else
            printf("LOSE\n");
    return 0;
}
