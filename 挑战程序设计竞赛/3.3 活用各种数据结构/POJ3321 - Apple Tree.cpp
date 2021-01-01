#include<cstdio>
#include<cstring>
#include<iostream>
#include<bitset>

using namespace std;

int G[110050][100];
int l[110050];
int n, m, cnt;
int L[110050], R[110050];
int node[220100], sum[220100];
bitset<220050> apple;

void add(int id, int u)
{
    while(id <= cnt)
    {
        sum[id] += u;
        id += id & (-id);
    }
}

int query(int id)
{
    int res = 0;
    while(id)
    {
        res += sum[id];
        id -= id & (-id);
    }
    return res;
}

void init_bit()
{
    for(int i = 1; i <= n; i++)
    {
        add(L[i], 1);
    }
}

void dfs(int cur, int fa)
{
    if(!L[cur]) L[cur] = cnt;
    node[cnt++] = cur;
    for(int i = 0; i < l[cur]; i++)
    {
        if(G[cur][i] == fa) continue;
        dfs(G[cur][i], cur);
        node[cnt++] = cur;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int ts, tt;
        scanf("%d%d", &ts, &tt);
        G[ts][l[ts]++] = tt;
        G[tt][l[tt]++] = ts;
    }

    cnt = 1;
    dfs(1, -1);
    cnt--;

    apple.set();

    for(int i = cnt; i >= 1; i--)
        if(!R[node[i]]) R[node[i]] = i;

    init_bit();

    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++)
    {
        char op[5];
        int u;
        scanf("%s %d", op, &u);
        if(op[0] == 'Q')
        {
            printf("%d\n", query(R[u]) - query(L[u] - 1));
        }
        else
        {
            if(apple[L[u]] == 1)
            {
                add(L[u], -1);
                apple[L[u]] = 0;
            }
            else
            {
                add(L[u], 1);
                apple[L[u]] = 1;
            }
        }
    }
    return 0;
}

/*
8
1 2
1 3
2 4
2 5
5 7
5 8
3 6





*/
