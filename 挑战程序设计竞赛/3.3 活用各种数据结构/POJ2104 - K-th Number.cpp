#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100000 + 50;

int n , m;
int a[MAXN] , I[MAXN] , J[MAXN] , K[MAXN];
int nums[MAXN];
const int B = 1000;
vector <int> bucket[MAXN / B];

void solve()
{
    for(int i = 0 ; i < n ; i++)
    {
        bucket[i / B].push_back(a[i]);
        nums[i] = a[i];
    }
    sort(nums , nums + n);
    for(int i = 0; i < n / B ; i++)sort(bucket[i].begin() , bucket[i].end());
    for(int i = 0 ; i < m  ; i++)
    {
        int l = I[i] - 1, r = J[i], k = K[i];
        int lb = -1 , ub = n - 1;
        while(ub - lb > 1)
        {
            int mid = (lb + ub) / 2;
            int x = nums[mid];
            int tl = l , tr = r , c = 0;
            while(tl < tr && tl % B != 0)if(a[tl++] <= x)c++;
            while(tl < tr && tr % B != 0)if(a[--tr] <= x)c++;
            while(tl < tr)
            {
                int b = tl / B;
                c += upper_bound(bucket[b].begin() , bucket[b].end() , x) - bucket[b].begin();
                tl += B;
            }
            if(c >= k)ub = mid;
            else lb = mid;
        }
        printf("%d\n", nums[ub]);
    }
}

int main()
{
    while(~scanf("%d%d" , &n , &m))
    {
        for(int i = 0 ; i < n ; i++) scanf("%d", &a[i]);
        for(int i = 0 ; i < m ; i++) scanf("%d%d%d" , &I[i] , &J[i] , &K[i]);
        solve();
    }
    return 0;
}
