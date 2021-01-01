#include<cstdio>
#include<cstring>
#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;

int dp[2050][2050];
int str[2050][2050];
int line[2050], l[2050], r[2050];

int n, m;
int ans;

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &dp[i][j]);

        ans = 0;

        for(int i = 1; i <= n; i++)
            for(int j = m; j >= 1; j--)
                dp[i][j] = dp[i][j] == 1 ? dp[i][j] + dp[i][j + 1] : 0;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
                line[j] = dp[j][i];

            stack<int> s;

            for(int j = 1; j <= n; j++)
            {
                while(!s.empty() && line[s.top()] > line[j])
                {
                    r[s.top()] = j;
                    s.pop();
                }
                s.push(j);
            }

            while(!s.empty())
            {
                r[s.top()] = n + 1;
                s.pop();
            }

            for(int j = n; j >= 1; j--)
            {
                while(!s.empty() && line[s.top()] > line[j])
                {
                    l[s.top()] = j;
                    s.pop();
                }
                s.push(j);
            }
            while(!s.empty())
            {
                l[s.top()] = 0;
                s.pop();
            }

            for(int j = 1; j <= n; j++)
            {
                ans = max(ans, line[j] * (r[j] - l[j] - 1));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
