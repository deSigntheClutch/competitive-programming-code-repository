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

const int N = 2e5 + 10;

int n, q;
vector<int> G[N];
int c[N];
int l[N << 2], r[N << 2], ord[N << 2], cnt;
int rev[N << 2], s[N << 2];

void dfs(int u, int f) {
    l[u] = ++cnt;
    ord[cnt] = u;
    for (int x : G[u]) {
        if (x == f) continue;
        dfs(x, u);
    }
    r[u] = cnt;
}

void pushup(int rt) {
    s[rt] = s[rt << 1] + s[rt << 1 | 1];
}

void pushdown(int rt, int len) {
    if (rev[rt] == 1) {
        rev[rt] = 0;
        rev[rt << 1] ^= 1;
        s[rt << 1] = len - len / 2 - s[rt << 1];
        s[rt << 1 | 1] = len / 2 - s[rt << 1 | 1];
        rev[rt << 1 | 1] ^= 1;
    }
}

void build(int rt, int left, int right) {
    if (left == right) {
        s[rt] = c[ord[left]];
        return;
    }
    build(lson);
    build(rson);
    s[rt] = s[rt << 1] + s[rt << 1 | 1];
}

int Q(int rt, int left, int right, int l, int r) {
    if (l == left && right == r) {
        return s[rt];
    }
    pushdown(rt, right - left + 1);
    if (mid >= r) return Q(lson, l, r);
    else if (mid < l) return Q(rson, l, r);
    else return Q(lson, l, mid) + Q(rson, mid + 1, r);
}

void U(int rt, int left, int right, int l, int r) {
    if (l == left && right == r) {
        rev[rt] ^= 1;
        s[rt] = r + 1 - l - s[rt];
        return ;
    }
    pushdown(rt, right - left + 1);
    if (mid >= r) U(lson, l, r);
    else if (mid < l) U(rson, l, r);
    else U(lson, l, mid), U(rson, mid + 1, r);
    pushup(rt);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int t, i = 0; i < n - 1; i++) {
        cin >> t;
        G[t].pb(i + 2);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }   dfs(1, -1);
    build(1, 1, n);
    cin >> q;
    while (q--) {
        string op;
        cin >> op;
        if (op == "get") {
            int x;
            cin >> x;
            cout << Q(1, 1, n, l[x], r[x]) << endl;
        } else {
            int x;
            cin >> x;
            U(1, 1, n, l[x], r[x]);
        }
    }
    return 0;
}
/*

10
1 2 3 4 2 4 1 7 8
1 1 0 1 1 0 0 0 1 1
2
pow 1
get 2

*/
