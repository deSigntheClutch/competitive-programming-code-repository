#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

int map[6][6];
set<int> s;

void dfs(int res, int k, int x, int y)
{
    if(k == 6)
    {
        s.insert(res);
        return;
    }
    res = res * 10 + map[x][y];
    if(x > 1) dfs(res, k + 1, x - 1, y);
    if(x < 5) dfs(res, k + 1, x + 1, y);
    if(y > 1) dfs(res, k + 1, x, y - 1);
    if(y < 5) dfs(res, k + 1, x, y + 1);
}

int main()
{
    s.clear();
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++)
            scanf("%d", &map[i][j]);

    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++)
            dfs(0, 0, i, j);

    printf("%d\n", s.size());
    return 0;
}
