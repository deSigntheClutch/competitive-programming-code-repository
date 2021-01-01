#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define pb push_back
using namespace std;

const int N = 10;
const int M = 40;
const double inf = 1e10;
const double cinf = 1e9;
const double eps = 1e-9;

int sgn(double u)
{
    if(u > eps) return 1;
    if(u < -eps) return -1;
    return 0;
}

struct edge
{
    int to;
    double len;
};

double ticket[N];
double dp[1 << N][M];
vector<edge> G[M];
int n, m, p, a, b;

int main()
{
    while(~scanf("%d%d%d%d%d", &n, &m, &p, &a, &b), n + m + p + a + b)
    {
        for(int i = 0; i < (1 << (n + 1)); i++)
            for(int j = 0; j <= m; j++)
                dp[i][j] = inf;

        for(int i = 0; i <= m; i++)
            G[i].clear();

        //ini----------------------------------

        for(int i = 0; i < n; i++)
            scanf("%lf", &ticket[i]);

        for(int i = 0; i < p; i++)
        {
            int tt, tf;
            double lt;
            scanf("%d %d %lf", &tf, &tt, &lt);
            G[tf].pb((edge)
            {
                tt, lt
            });
            G[tt].pb((edge)
            {
                tf, lt
            });
        }

        dp[0][a] = 0;

        for(int k = 0; k < (1 << n); k++)
        {
            for(int j = 1; j <= m; j++)
            {
                for(int u = 0; u < n; u++)
                {
                    if(k >> u & 1 || sgn(dp[k][j] - cinf) >= 0) continue;
                    for(int v = 0; v < G[j].size(); v++)
                    {
                        dp[k | (1 << u)][G[j][v].to] = min(dp[k | (1 << u)][G[j][v].to], dp[k][j] + G[j][v].len / ticket[u]);
                    }
                }
            }
        }

        double ans = inf;
        for(int i = 0; i < (1 << n); i++)
            ans = min(ans, dp[i][b]);

        if(sgn(ans - cinf) >= 0) puts("Impossible");
        else printf("%.3f\n", ans);
    }
    return 0;
}
