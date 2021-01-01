#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

ll dp[2][1 << 13];
int n, m;

int main()
{
    while(~scanf("%d%d", &n, &m), n + m)
    {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        ll *crt = dp[0], *next = dp[1];
        crt[0] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                for(int k = 0; k < (1 << m); k++)
                {
                    ll res = 0;
                    if(k >> j & 1)
                    {
                        next[k] = crt[k & ~(1 << j)];
                        continue;
                    }
                    if(j + 1 < m && !(k >> (j + 1) & 1))
                    {
                        res += crt[k | 1 << (j + 1)];
                    }
                    if(i + 1 < n)
                    {
                        res += crt[k | 1 << j];
                    }
                    next[k] = res;
                }
                swap(crt, next);
            }
        }
        printf("%lld\n", crt[0]);
    }
    return 0;
}
#include<stdio.h>
#include<string.h>


int n, m;
__int64 dp[12][5010];

bool ok(int t)
{
    t = t + (1 << m);
    int c = 0;
    while(c < m)
    {
        int lowbit = t & (-t);
        int w = 0;
        while(lowbit != 0)
            w++, c++, lowbit >>= 1;
        if (w % 2 == 0)
            return 0;
        t >>= w;
    }
    return 1;
}

void solve()
{
    if ((n * m) % 2 == 1)
    {
        printf("0\n");
        return;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 1 << m; j++)
        {
            dp[i][j] = 0;
            for (int k = 0; k < 1 << m; k++)
                if ( !(j & k) && ok(j | k) )
                    dp[i][j] += dp[i - 1][k];
        }
    printf("%I64d\n", dp[n][0]);
}

int main()
{
    while(scanf("%d%d", &n, &m) == 2 && n != 0 && m != 0)
    {
        if (n < m)
        {
            int t = n;
            n = m;
            m = t;
        }
        memset(dp, 0, sizeof(dp));
        solve();
    }
    return 0;
}
