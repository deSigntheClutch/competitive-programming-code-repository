#include <bits/stdc++.h>
using namespace std;
#define __max(x, y) (x > y ? x : y)
typedef long long ll;

const int N = 1e2 + 10;

int n;
ll a[N], k;
set<ll> s;

ll __ceil(ll x, ll y) {
    if(y == 1) return x;
    else return (x - 1) / y + 1;
}

void update(ll x) {
    for(int i = 1; (ll)i * i <= x; i++) {
        s.insert(__ceil(x, i)), s.insert(i);
    }
}

int main() {
    scanf("%d%I64d", &n, &k);
    s.insert((ll)1e12);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", a + i);
        k += a[i];
        update(a[i]);
    }
    ll cur = 1, mx = 1;
    for (ll x : s) {
        if(x == 1) continue;
        ll l = cur, r = x - 1, res = 0;
        for(int i = 1; i <= n; i++) {
            res += __ceil(a[i], cur);
        }
        if (l <= k / res && r >= k / res) {
            mx = __max(mx, k / res);
        }
        cur = x;
    }
    printf("%I64d\n", mx);
    return 0;
}

