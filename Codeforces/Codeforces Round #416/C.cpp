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

const int N = 5e3 + 10;

int vis[N];
int n, a[N];
int f[N], first[N], last[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (!first[a[i]]) first[a[i]] = i;
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int key = 0;
        if (i == last[a[i]]) {
            memset(vis, 0, sizeof vis);
            int mn = first[a[i]];
            bool flag = false;
            for (int j = i; j >= mn; j--) {
                if(last[a[j]] > i) flag = true;
                if (vis[a[j]] == 0) {
                    key ^= a[j];
                    vis[a[j]] = 1;
                }
                mn = min(first[a[j]], mn);
            }
            if(!flag) f[i] = max(key + f[mn - 1], f[i]);
        }
        f[i] = max(f[i], f[i - 1]);
    }
    printf("%d\n", f[n]);
    return 0;
}

