#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1000000 + 1000;

int deq1[MAXN], deq2[MAXN];
int ans1[MAXN], ans2[MAXN];
int a[MAXN];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n; i++) scanf("%d", a + i);

    int l = 0, r = 0;

    for(int i = 0; i < n; i++)
    {
        while(l < r && a[deq1[r - 1]] >= a[i]) r--;
        deq1[r++] = i;

        if(i >= k - 1)
        {
            ans1[i] = a[deq1[l]];
            if(i - deq1[l] == k - 1) l++;
        }
    }

    l = 0, r = 0;
    for(int i = 0; i < n; i++)
    {
        while(l < r && a[deq2[r - 1]] <= a[i]) r--;
        deq2[r++] = i;
        if(i >= k - 1)
        {
            ans2[i] = a[deq2[l]];
            if(i - deq2[l] == k - 1) l++;
        }
    }

    for(int i = k - 1; i < n; i++)
        printf("%d%c", ans1[i], i == n - 1 ? '\n' : ' ');
    for(int i = k - 1; i < n; i++)
        printf("%d%c", ans2[i], i == n - 1 ? '\n' : ' ');

    return 0;
}
