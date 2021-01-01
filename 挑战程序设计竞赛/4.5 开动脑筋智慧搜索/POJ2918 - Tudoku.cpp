#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct choice
{
    int x, y;
    int ch[10];
    int len;
    bool operator < (struct choice u) const
    {
        return len < u.len;
    }
} c[100];

int ct;
int cLen;
int flag;
char sudoku[10][10];

bool check(int x, int y, int num)
{
    for(int i = 1; i <= 9; i++)
        if(sudoku[x][i] == '0' + num) return false;
    for(int i = 1; i <= 9; i++)
        if(sudoku[i][y] == '0' + num) return false;

    int sx = (x - 1) / 3, sy = (y - 1) / 3;
    for(int i = 3 * sx + 1; i <= 3 * sx + 3; i++)
        for(int j = 3 * sy + 1; j <= 3 * sy + 3; j++)
            if(sudoku[i][j] == '0' + num) return false;

    return true;
}

void dfs(int s, int e)
{
    if(flag == 1) return;
    if(s == e)
    {
        printf("Scenario #%d:\n", ct);
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
                printf("%c", sudoku[i][j]);
            puts("");
        }
        puts("");
        flag = 1;
        return ;
    }

    int tx = c[s].x, ty = c[s].y;
    if(c[s].len == 1)
    {
        sudoku[tx][ty] = c[s].ch[0] + '0';
        dfs(s + 1, e);
    }
    else
    {
        for(int i = 0; i < c[s].len; i++)
        {
            if(check(tx, ty, c[s].ch[i]))
            {
                sudoku[tx][ty] = c[s].ch[i] + '0';
                dfs(s + 1, e);
                if(flag == 1) return;
                sudoku[tx][ty] = '0';
            }
        }
    }
}

int main()
{
    int T;
    ct = 0;
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        ct++;
        cLen = 0;
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                scanf("%c", &sudoku[i][j]);
                if(sudoku[i][j] == '0')
                {
                    choice tmp;
                    tmp.len = 0, tmp.x = i, tmp.y = j;
                    c[cLen++] = tmp;
                }
            }
            getchar();
        }
        getchar();

        // make choices
        for(int i = 0; i < cLen; i++)
        {
            int tx = c[i].x, ty = c[i].y;
            for(int j = 1; j <= 9; j++)
                if(check(tx, ty, j))
                {
                    c[i].ch[c[i].len++] = j;
                }
        }
        sort(c, c + cLen);
        flag = 0;

        dfs(0, cLen);
    }
    return 0;
}
