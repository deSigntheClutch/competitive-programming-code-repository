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
const int MOD = 1e9 + 7;

const int N = 42;
const int M = 1 << 23;

int n, k;
ll adj[N], f[M];

double fun(int v) {
    return 0.5 * (v - 1) * k * k / v;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll v = 0;
        for (int j = 0; j < n; j++) {
            ll u;
            cin >> u;
            v |= (u << j);
        }
        adj[i] = v;
    }
    int sz = max(0, n - 20);
    for (int i = 1; i < (1 << sz); i++) {
        ll s = i;
        bool flag = true;
        for (int j = 0; j < n - 20; j++) {
            if (s >> j & 1) {
                ll cnt = ((adj[j + 20] | (1ll << (j + 20))) >> 20) & s;
                if (cnt != s) flag = false;
            }
        }
        if (flag == false) continue;
        f[i] = __builtin_popcountll(s);
    }
    for (int i = 1; i < (1 << sz); i++) {
        for (int j = 0; j < sz; j++) {
            f[i | (1 << j)] = max(f[i | (1 << j)], f[i]);
        }
    }
    int res = 0;
    for (int i = 0; i < (1 << min(20, n)); i++) {
        ll u = i;
        ll w = -1;
        ll key = 0;
        bool flag = true;
        for (int j = 0; j < min(20, n); j++) {
            if (u >> j & 1) {
                w &= adj[j];
                ll cnt = (adj[j] | (1 << j)) & u;
                if (cnt != u) flag = false;
            }
        }
        if (flag == false) continue;
        res = max(res, (int)f[w >> 20] + __builtin_popcountll(u));
    }
    cout << fixed << setprecision(10) << fun(res) << endl;
    return 0;
}

