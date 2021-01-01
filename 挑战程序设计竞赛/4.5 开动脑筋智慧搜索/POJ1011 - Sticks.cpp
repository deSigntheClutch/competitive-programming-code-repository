#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;

int n, e;
int stand;
int sticks[80];
int vis[80];

int dfs(int s, int len, int cur)
{
    if(s == e) return true;
    int ts = -1;
    for(int i = cur; i < n; i++)
    {
        if(vis[i] | ts == sticks[i]) continue;
        vis[i] = 1;
        if(len + sticks[i] == stand)
        {
            if(dfs(s + 1, 0, 0)) return 1;
        }
        else if(len + sticks[i] < stand)
        {
            if(dfs(s, len + sticks[i], i)) return 1;
        }
        ts = sticks[i];
        vis[i] = 0;
        if(len == 0) break;
    }
    return 0;
}

int main()
{
    while(~scanf("%d", &n), n)
    {
        int maxlen = 0;
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", sticks + i);
            sum += sticks[i];
            if(maxlen < sticks[i]) maxlen = sticks[i];
        }

        sort(sticks, sticks + n, greater<int>());

        for(int i = maxlen; i <= sum; i++)
        {
            if(sum % i) continue;
            e = sum / i;
            stand = i;
            memset(vis, 0, sizeof vis);

            if(dfs(0, 0, 0) == 1)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
