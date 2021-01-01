#include<bits/stdc++.h>
using namespace std;

bitset<12345> cookie[12];
int r, c;

int main()
{
    while(~scanf("%d%d", &r, &c), r)
    {
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                int tt;
                scanf("%d", &tt);
                cookie[i][j] = tt;
            }
        }

        int ans = 0;

        for(int i = 0; i < (1 << r); i++)
        {
            for(int j = 0; j < r; j++) if(i >> j & 1) cookie[j].flip();
            int tmp = 0;

            for(int j = 0; j < c; j++)
            {
                int u = 0;
                for(int k = 0; k < r; k++)
                    u += cookie[k][j];
                tmp += max(u, r - u);
            }

            ans = max(tmp, ans);
            for(int j = 0; j < r; j++) if(i >> j & 1) cookie[j].flip();
        }
        printf("%d\n", ans);
    }

    return 0;
}
