#include <bits/stdc++.h>

#define ENDL cerr << "\n";
#define DB(x) cerr << #x << " = " << (x) << " ";
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T& x, U y) {
    if (y < x) x = y;
}
template<typename T, typename U> static void rmax(T& x, U y) {
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

bool forbidden[N];
int cnt[N], n, m, f[N], to[N];

vector<int> G[N], elements[N];

int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int res = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

int dfs(int u) {
    if (f[u] != -1) return f[u];
    pii ans(0, -1);
    for (int x : G[u]) {
        int v = dfs(x);
        rmax(ans, mp(v, x));
    }
    to[u] = ans.se;
    return f[u] = ans.fi + cnt[u];
}

void change(int &u, int v) {
    int x, y;
    int tmp = extgcd(u, -m, x, y);
    cout << ((long long)x * (v / tmp) % m + m) % m << " ";
    u = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        forbidden[x] = true;
    }
    for (int i = 0, x; i < m; i++) {
        if (forbidden[i]) continue;
        x = __gcd(i, m);
        cnt[x]++;
        elements[x].pb(i);
    }
    for (int gcd = 1; gcd <= m; gcd++) {
        for (int i = gcd * 2; i <= m; i += gcd) {
            G[gcd].pb(i);
        }
    }
    memset(f, -1, sizeof f), memset(to, -1, sizeof to);
    dfs(1);
    cout << f[1] << endl;
    int cur = 1, v = -1;
    while (cur != -1) {
        for (int x : elements[cur]) {
            if (v == -1) {
                v = x;
                cout << v << " ";
            } else change(v, x);
        }
        cur = to[cur];
    }
    cout << endl;
    return 0;
}
