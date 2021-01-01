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

const int N = 3e5 + 10;

int n, a[N], b[N], ans[N];
int fa[N], total = 1;

int find(int u) {
    if (fa[u] != u) return fa[u] = find(fa[u]);
    return fa[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        fa[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b[i] = t;
        a[t] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) continue;
        while (a[i] == 0 && i <= n) i++;
        i--;
        total++;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 1) continue;
        if (a[i - 1] != 1) {
            unite(i - 1, i);
        }
    }
    ans[n] = total;
    for (int i = n - 1; i >= 1; i--) {
        int v = b[i + 1];
        if (a[v - 1] == a[v + 1] && a[v - 1] == 0) total--;
        else if (a[v - 1] == a[v + 1] && a[v - 1] == 1) total++;
        if (a[v + 1] == 0) unite(v, v + 1);
        if (a[v - 1] == 0) unite(v - 1, v);
        a[v] = 0;
    }
    cout << 1;
    for (int i = 1; i <= n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}

