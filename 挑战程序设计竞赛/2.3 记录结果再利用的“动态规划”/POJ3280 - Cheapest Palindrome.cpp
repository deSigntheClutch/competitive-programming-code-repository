#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

int dp[2008][2008];
int n, m;
char str[2008];
int w[300];

int main()
{
      scanf("%d%d", &n, &m);
      scanf("%s", str);
      getchar();
      for(int i = 0; i < n; i++)
      {
            char tmp;
            int u, v;
            tmp = getchar();
            scanf("%d %d", &u, &v);
            getchar();
            w[tmp] = min(u, v);
      }

      for(int i = m - 1; i >= 0; i--)
      {
            for(int j = i + 1; j < m; j++)
            {
                  if(str[i] == str[j])dp[i][j] = dp[i + 1][j - 1];
                  else dp[i][j] = min(dp[i + 1][j] + w[str[i]], dp[i][j - 1] + w[str[j]]);
            }
      }
      printf("%d\n", dp[0][m - 1]);
      return 0;
}
