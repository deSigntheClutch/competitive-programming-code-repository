#include<bits/stdc++.h>
using namespace std;

int n, m, d;
bool mat[650][650];
bool a[25][25];

bool valid(int x, int y)
{
    if(x < n && x >= 0 && y < m && y >= 0) return true;
    return false;
}

int main()
{
    int cnt = 0;
    while(~scanf("%d%d%d", &m, &n, &d), n + m + d)
    {

        cnt++;
        memset(mat, 0, sizeof mat);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);

        int row = n * m, col = n * m + 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int k = 0; k <= d; k++)
                {
                    int t1x = i + k, t1y = j + d - k;
                    int t2x = i - k, t2y = j + d - k;
                    int t3x = i + k, t3y = j - d + k;
                    int t4x = i - k, t4y = j - d + k;
                    if(valid(t1x, t1y)) mat[t1x * m + t1y][i * m + j] = 1;
                    if(valid(t2x, t2y)) mat[t2x * m + t2y][i * m + j] = 1;
                    if(valid(t3x, t3y)) mat[t3x * m + t3y][i * m + j] = 1;
                    if(valid(t4x, t4y)) mat[t4x * m + t4y][i * m + j] = 1;
                }
                mat[i * m + j][i * m + j] = 1;
            }
        }

        int flag = 0, pivot = 0;

        for(int i = 0; i < n * m; i++)
            mat[i][n * m] = a[i / m][i % m];

        int ansl = 0, matl = 0;

        for(int i = 0; i < col - 1; i++)
        {
            int pt = pivot;
            while(mat[pt][i] == 0 && pt < row) pt++;
            if(pt >= row) continue;
            for(int j = 0; j < col; j++) swap(mat[pivot][j], mat[pt][j]);
            for(int j = pivot + 1; j < row; j++)
                if(mat[j][i] == 1)
                    for(int k = i; k < col; k++)
                        mat[j][k] ^= mat[pivot][k];
            pivot++;
        }

        for(int u = row - 1; u >= 0; u--)
        {
            int fla = 0;
            for(int v = 0; v < col - 1; v++)
                if(mat[u][v] == 1) fla = 1;
            if(fla == 0 && mat[u][col - 1] == 1)
            {
                flag = 1;
                break;
            }
        }
        printf("%d\n", flag ^ 1);
    }
    return 0;
}

/*

2 3 1
0 0 1
0 0 0
2 3 1
1 0 1
0 0 0
2 3 1
0 1 1
0 0 0

*/
