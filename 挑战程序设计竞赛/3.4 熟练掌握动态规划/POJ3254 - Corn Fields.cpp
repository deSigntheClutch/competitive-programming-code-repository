#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll mod = 1000000000;
int dp[2][1 << 14][14 * 14];
int maze[14][14];
int m, n;

void dfs(int pt, int s, int pre, int cur, int cnum, ll num)
{
    if(s >= m)
    {
        dp[(pt + 1) % 2][cur][cnum] = (num + dp[(pt + 1) % 2][cur][cnum]) % mod;
        return ;
    }
    if(maze[pt][s] == 0)
    {
        dfs(pt, s + 1, pre, cur, cnum, num);
        return;
    }

    if(pre >> s & 1) dfs(pt, s + 1, pre, cur, cnum, num);
    else
    {
        dfs(pt, s + 2, pre, cur | (1 << s), cnum + 1, num);
        dfs(pt, s + 1, pre, cur, cnum, num);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &maze[i][j]);

    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (1 << m); j++)
            for(int k = 0; k <= n * m; k++)
                if(dp[i % 2][j][k])
                    dfs(i, 0, j, 0, k, dp[i % 2][j][k]);

        for(int j = 0; j < (1 << m); j++)
            for(int k = 0; k <= n * m; k++)
                dp[i%2][j][k] = 0;
    }

    ll sum = 0;
    for(int i = 0 ; i < (1 << m); i++)
    {
        for(int j = 0; j <= n * m; j++)
        {
           // printf("%d ",  dp[n % 2][i][j]);
            sum = (sum + dp[n % 2][i][j]) % mod;
        }
       // puts("");
    }

    printf("%lld\n", sum);
    return 0;
}
