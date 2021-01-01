#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define pb push_back

const int MAXV = 123450;
int V;
vector<int> G[MAXV], rG[MAXV];
vector<int> vs;

bool used[MAXV];
int cmp[MAXV];

void add_edge(int from, int to)
{
      G[from].pb(to);
      rG[to].pb(from);
}

void dfs(int v)
{
      used[v] = true;
      for(int i = 0; i < G[v].size(); i++)
      {
            if(!used[G[v][i]])
                  dfs(G[v][i]);
      }
      vs.pb(v);
}

void rdfs(int v, int k)
{
      used[v] = true;
      cmp[v] = k;
      for(int i = 0; i < rG[v].size(); i++)
      {
            if(!used[rG[v][i]]) rdfs(rG[v][i], k);
      }
}

int scc()
{
      memset(used, 0, sizeof used);
      vs.clear();
      for(int i = 0; i < V; i++) if(!used[i]) dfs(i);
      memset(used, 0, sizeof used);
      int k = 0;
      for(int i = vs.size() - 1; i >= 0; i--)
      {
            //printf("%d\n", vs[i]);
            if(!used[vs[i]]) rdfs(vs[i], k++);
      }
      return k;
}

int n, m;
int A[567890], B[567890];

int main()
{
      scanf("%d%d", &n, &m);
      V = n;

      for(int i = 0; i < m; i++)
      {
            scanf("%d%d", &A[i], &B[i]);
            add_edge(A[i] - 1, B[i] - 1);
      }

      int n = scc();
      int u = 0, num = 0;
      //for(int i = 0; i < V; i++) printf("%d :  %d\n", i, cmp[i]);
      for(int v = 0; v < V; v++)
      {
            if(cmp[v] == n - 1)
            {
                  u = v;
                  num++;
            }
      }

      memset(used, 0, sizeof used);
      rdfs(u, 0);
      for(int v = 0; v < V; v++)
      {
            if(!used[v])
            {
                  num = 0;
                  break;
            }
      }
      printf("%d\n", num);
      return 0;
}

/*

6 7
1 2
2 3
3 1
3 4
5 6
5 1
6 2




*/
