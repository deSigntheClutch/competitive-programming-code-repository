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

const int N = 1e5 + 10;
const int M = 4e6 + 10;

vector<string> Q;
vector<string> pattern;

int vis[M];
int to[M][5], cnt[M], total = 1;
int n, m;
string t;

int dfs(int sig, int u, int s) {
    if (s == t.length() && vis[u] != sig) {
        vis[u] = sig;
        return cnt[u];
    }
    if (t[s] == '?') {
        int res = 0;
        for (int i = 0; i < 5; i++) {
            if (to[u][i] == 0) continue;
            res += dfs(sig, to[u][i], s + 1);
        }
        res += dfs(sig, u, s + 1);
        return res;
    } else {
        if (to[u][t[s] - 'a'] == 0) return 0;
        return dfs(sig, to[u][t[s] - 'a'], s + 1);
    }
}

void build() {
    for (int i = 0; i < n; i++) {
        string s = Q[i];
        int cur = 1, len = s.length();
        for (int j = 0; j < len; j++) {
            if (to[cur][s[j] - 'a'] == 0) to[cur][s[j] - 'a'] = ++total;
            cur = to[cur][s[j] - 'a'];
        }
        cnt[cur]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        Q.pb(tmp);
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        pattern.pb(tmp);
    }
    build();
    for (int i = 0; i < m; i++) {
        t = pattern[i];
        cout << dfs(i + 1, 1, 0) << endl;
    }
    return 0;
}

/*

3 2
a
a
be
??
???

*/
