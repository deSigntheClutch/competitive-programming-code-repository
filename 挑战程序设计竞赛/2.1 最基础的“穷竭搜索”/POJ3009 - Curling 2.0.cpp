#include<cstdio>
#include<cstring>
using namespace std;

#define INF 20

int G[25][25], mov[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
int n, m;
int sx, sy, ex, ey;
int cnt;

void dfs(int x, int y, int ord)
{
    if(x == ex && y == ey)
        cnt = ord;
    for(int i = 0; i < 4; i++)
    {
        int flag = 0, tx, ty;
        for(int k = 0; k < 25; k++)
        {
            tx = x + k * mov[i][0], ty = y + k * mov[i][1];
            if(G[tx + mov[i][0]][ty + mov[i][1]] == 1)
            {
                if(k) flag = 1;
                break;
            }
            if(G[tx + mov[i][0]][ty + mov[i][1]] == 3)
            {
                flag = 9;
                break;
            }
            if(tx + mov[i][0] < 0 || tx + mov[i][0] >= n || ty + mov[i][1] < 0 || ty + mov[i][1] >= m)
                break;
        }

        if(ord + 1 <= cnt && flag && ord + 1 <= 10)
        {
            if(flag == 9)
                dfs(tx + mov[i][0], ty + mov[i][1], ord + 1);
            else
            {
                G[tx + mov[i][0]][ty + mov[i][1]] = 0;
                dfs(tx, ty, ord + 1);
                G[tx + mov[i][0]][ty + mov[i][1]] = 1;
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &m, &n), m + n)
    {
        memset(G, 0, sizeof(G));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &G[i][j]);
                if(G[i][j] == 2) sx = i, sy = j;
                if(G[i][j] == 3) ex = i, ey = j;
            }
        cnt = INF;
        dfs(sx, sy, 0);
        printf("%d\n", cnt == 20 ? -1 : cnt);
    }
    return 0;
}
