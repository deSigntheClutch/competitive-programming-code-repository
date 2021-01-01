#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int a[12343], n;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if(n & 1) a[n++] = 0;
        sort(a, a + n);
        int res = 0;
        for(int i = 0 ; i < n; i += 2)
        {
            res ^= (a[i + 1] - a[i] - 1);
        }
        if(res) puts("Georgia will win");
        else puts("Bob will win");
    }
    return 0;
}
