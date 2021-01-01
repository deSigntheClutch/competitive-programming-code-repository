#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;
#define pb push_back

int n, max_logn, root;
vector<int> G[2000];
int parent[20][2000];
int depth[2000];
int ans[2000];

void init()
{
    for(int i = 1; i <= n; i++)
    {
        G[i].clear();
        depth[i] = 0;
        ans[i] = 0;
    }
    memset(parent, 0, sizeof parent);
}

void dfs(int cur, int father, int dep)
{
    parent[0][cur] = father;
    depth[cur] = dep;
    for(int i = 0; i < G[cur].size(); i++)
        if(father != G[cur][i])
            dfs(G[cur][i], cur, dep + 1);
}

void lca_init()
{
    dfs(root, -1, 0);
    max_logn = (int)floor(log2(n)) + 3;

    for(int i = 0; i < max_logn; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(parent[i][j] == -1) parent[i + 1][j] = 1;
            else parent[i + 1][j] = parent[i][parent[i][j]];
        }
    }
}

int lca(int u, int v)
{
    if(depth[u] > depth[v]) swap(u, v);
    for(int i = 0; i < max_logn; i++)
    {
        if(depth[v] - depth[u] >> i & 1)
        {
            v = parent[i][v];
        }
    }
    if(u == v) return u;
    for(int i = max_logn; i >= 0; i--)
    {
        if(parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int main()
{
    while(~scanf("%d", &n))
    {
        init();

        for(int i = 0; i < n; i++)
        {
            int t, l;
            scanf(" %d:(%d)", &t, &l);
            for(int j = 0; j < l; j++)
            {
                int tp;
                scanf(" %d", &tp);
                G[t].pb(tp);
                G[tp].pb(t);
                parent[0][tp] = t;
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(!parent[0][i])
            {
                root = i;
                break;
            }
        }

        lca_init();

        int q;
        scanf(" %d", &q);
        for(int i = 0; i < q; i++)
        {
            int u, v;
            scanf(" (%d %d)", &u, &v);
            int tmp = lca(u, v);
            ans[tmp]++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(!ans[i]) continue;
            else printf("%d:%d\n", i, ans[i]);
        }
    }
    return 0;
}
