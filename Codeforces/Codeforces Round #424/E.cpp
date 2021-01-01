#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int N = 1e5 + 10;

int n, a[N], b[N], pos[N], cnt[N], v[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        int x = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        v[x + cnt[a[i]]] = i;
        cnt[a[i]]++;
    }
    ll ans = 0;
    int cur = 0
    for (int i = 1; i <= n; i++) {

    }
    printf("%I64d\n", ans);
    return 0;
}

/*

7
6 6 3 3 1 1 2

10
4 3 4 3 3 3 4 4 4 3

*/
