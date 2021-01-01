#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) {
    if (y < x) x = y;
}
template<typename T, typename U> static void rmax(T &x, U y) {
    if (x < y) x = y;
}

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
typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 998244353;

const int N = 1e5 + 10;

int a, b, c;
ll pw[11111];

ll pw_mod(ll u, ll v) {
    ll res = 1;
    while (v) {
        if (v & 1) res = res * u % MOD;
        v >>= 1;
        u = u * u % MOD;
    }
    return res;
}
// m < v
ll calcu(ll m, ll v) {
    ll vv = 1, mm = 1;
    for (ll i = 1; i <= v; i++) {
        vv = vv * i % MOD;
    }
    for (ll i = 1; i <= m; i++) {
        mm = mm * i % MOD;
    }
    ll rvv = pw_mod(vv, MOD - 2), rmm = pw_mod(mm, MOD - 2);
    ll cal = 1;
    ll ii = 1, vi = rvv, mi = rmm;
    cal = mi * vi % MOD;
    for (ll i = 1; i <= m; i++) {
        ii = ii * pw_mod(i, MOD - 2) % MOD;
        vi = vi * (v - i + 1) % MOD;
        mi = mi * (m - i + 1) % MOD;
        cal = (cal + ii * vi % MOD * mi % MOD) % MOD;
    }
    cal = cal * vv % MOD * mm % MOD;
    return cal;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    if (c > a) swap(a, c);
    if (c > b) swap(b, c);
    // add blue
    ll ans = 1;
    ans = ans * calcu(c, a) % MOD;
    ans = ans * calcu(c, b) % MOD;
    if (a > b) swap(a, b);
    ans = ans * calcu(a, b) % MOD;
    cout << ans << endl;
    return 0;
}

