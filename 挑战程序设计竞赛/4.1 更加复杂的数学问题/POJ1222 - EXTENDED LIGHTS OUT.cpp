#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[40][40];

void gauss()
{
    int i, j, k;
    for(i = 0; i < 30; i++)
    {
        for(k = i; k < 30; k++)
            if(a[k][i]) break;// pivot
        if(k != i)
            for(j = 0; j <= 30; j++) swap(a[i][j], a[k][j]);
        for(j = 0; j < 30; j++)
        {
            if(i != j && a[j][i])
                for(k = 0; k <= 30; k++)
                    a[j][k] ^= a[i][k];
        }

    }
}

int main()
{
    int n, cas = 1;
    scanf("%d", &n);
    while(n--)
    {
        memset(a, 0, sizeof a);
        for(int i = 0; i < 30; i++) scanf("%d", &a[i][30]);
        for(int i = 0; i < 30; i++)
        {
            a[i][i] = 1;
            if(i >= 6)
                a[i][i - 6] = 1;
            if(i < 24)
                a[i][i + 6] = 1;
            if(i % 6)
                a[i][i - 1] = 1;
            if((i + 1) % 6)
                a[i][i + 1] = 1;
        }
        gauss();
        printf("PUZZLE #%d\n", cas++);
        for(int i = 0; i < 30; i++)
        {
            printf("%d", a[i][30]);
            if((i + 1) % 6 == 0) printf("\n");
            else printf(" ");
        }
    }
}

/*


3
0 1 0
1 1 1
0 1 0


*/
