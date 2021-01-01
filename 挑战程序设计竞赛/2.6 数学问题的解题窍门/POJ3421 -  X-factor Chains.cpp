#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1 << 23], fp[1 << 23];

int dfs(int u)
{
      if(dp[u] != -1) return dp[u];
      int res = 1;
      int cnt = 1;
      for(int i = 2; i * i <= u; i++)
      {
            if(u % i == 0)
            {
                  int tmp = dfs(i) + 1;
                  if(tmp == res) cnt += fp[i];
                  else if(tmp > res) res = tmp, cnt = fp[i];
                  if(u / i != i)
                  {
                        tmp = dfs(u / i) + 1;
                        if(tmp == res) cnt += fp[u / i];
                        else if(tmp > res) res = tmp, cnt = fp[u / i];
                  }
            }
      }
      fp[u] = cnt;
      return dp[u] = res;
}

int main()
{
      int n;
      memset(dp, -1, sizeof dp);
      while(~scanf("%d", &n))
      {
            printf("%d ", dfs(n));
            printf("%d\n", fp[n]);
      }
      return 0;
}
