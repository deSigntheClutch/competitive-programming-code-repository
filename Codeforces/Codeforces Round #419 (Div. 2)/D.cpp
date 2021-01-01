#include <bits/stdc++.h>

#define MB(x) cerr << ((int)x >> 18) <<" mb" << endl;
#define DB(x) cerr << #x << " = " << (x) << " ";
#define ENDL cerr << "\n";
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
const int MOD = 1e9 + 7;

const int N = 2e5 + 10;

int n, a[N];
int f[N], inv[N], finv[N];

void init() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (ll)f[i - 1] * i % MOD;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i < N; i++) {
        finv[i] = ((ll)finv[i - 1] * inv[i]) % MOD;
    }
}

int C(int x, int y) {
    if (y < 0) return 0;
    return ((ll)f[x] * finv[y] % MOD) * finv[x - y] % MOD;
}

void solve(vector<ll> v) {
    int u = (int)v.size(), p;
    if (u % 4) p = 1;
    else p = -1;
    int ans = 0;
    for (int i = 1, j = 1; i <= u; i += 2, j++) {
        if (p == 1) ans = (ans + C(u / 2 - 1, j - 1) * (v[i - 1] + v[i]) % MOD) % MOD;
        else ans = (ans + C(u / 2 - 1, j - 1) * ((v[i - 1] - v[i] + MOD) % MOD) % MOD) % MOD;
    }
    printf("%d\n", ans);
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    if(n == 1) {
        printf("%d\n", a[1]);
        return 0;
    }
    vector<ll> vec;
    if (n & 1) {
        for (int i = 1, pt = 1; i < n; i++, pt *= -1) {
            if(pt == 1) vec.pb(a[i] + a[i + 1]);
            else vec.pb(a[i] - a[i + 1]);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            vec.pb(a[i]);
        }
    }
    solve(vec);
    return 0;
}
/*



4
9 -3 21 -3

*/
