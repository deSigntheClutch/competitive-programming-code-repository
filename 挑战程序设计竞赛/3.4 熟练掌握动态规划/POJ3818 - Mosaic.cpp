#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

int dp[510][1 << 12];
int n, m;

void dfs(int s, int pt, int pre, int cur, int num)
{
    if(pt >= m)
    {
        dp[s][cur] = (dp[s][cur] + num) % 1000000;
        return ;
    }
    if(pre >> pt & 1)
    {
        dfs(s, pt + 1, pre, cur, num);
        return ;
    }
    if(pt + 1 < m && !(pre >> (pt + 1) & 1) && !(cur >> pt & 1) && !(cur >> (pt + 1) & 1))
    {
        dfs(s, pt + 2, pre | (1 << pt) | (1 << pt + 1), cur | (1 << pt) | (1 << pt + 1), num);
    }
    if(pt + 1 < m && !(cur >> pt & 1) && !(cur >> (pt + 1) & 1))
    {
        dfs(s, pt + 1, pre | (1 << pt), cur | (1 << pt) | (1 << pt + 1), num);
    }
    if(pt + 1 < m && !(pre >> (pt + 1) & 1) && !(cur >> (pt + 1) & 1))
    {
        dfs(s, pt + 2, pre | (1 << pt) | (1 << pt + 1), cur | (1 << pt + 1), num);
    }
    if(pt - 1 >= 0 && !(cur >> (pt - 1) & 1) && !(cur >> pt & 1))
    {
        dfs(s, pt + 1, pre | (1 << pt), cur | (1 << pt - 1) | (1 << pt), num);
    }
    if(pt + 1 < m && !(pre >> (pt + 1) & 1) && !(cur >> pt & 1))
    {
        dfs(s, pt + 2, pre | (1 << pt) | (1 << pt + 1), cur | (1 << pt), num);
    }
}

int main()
{
   // frepoen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    while(~scanf("%d%d", &n, &m), n + m)
    {
        memset(dp, 0, sizeof dp);
        if(m > n) swap(m, n);

        dp[1][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < (1 << m); j++)
            {
                if(dp[i][j] == 0) continue;
                dfs(i + 1, 0, j, 0, dp[i][j]);
            }
        }
        printf("%d\n", dp[n + 1][0]);
    }
    return 0;
}
