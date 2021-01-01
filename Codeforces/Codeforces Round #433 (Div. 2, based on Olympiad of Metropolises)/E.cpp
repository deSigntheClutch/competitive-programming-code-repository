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
const int SZ = 2e7 + 10;

struct Seg {
    int l, r, v;
} t[SZ];

int n, q;
int p[N];
int head[N], total;

int Insert(int id, int left, int right, int v) {
    int res = ++total;
    t[res] = t[id];
    t[res].v++;
    if (left == right) return res;
    if (v <= mid) t[res].l = Insert(t[id].l, left, mid, v);
    else t[res].r = Insert(t[id].r, mid + 1, right, v);
    return res;
}

int Query(int id, int left, int right, int l, int r) {
    if (r < l) return 0;
    if (!id) return 0;
    if (l == left && r == right) return t[id].v;
    if (mid >= r) return Query(t[id].l, left, mid, l, r);
    else if (mid < l) return Query(t[id].r, mid + 1, right, l, r);
    else return Query(t[id].l, left, mid, l, mid) + Query(t[id].r, mid + 1, right, mid + 1, r);
}

void init() {
    for (int i = 1; i <= n; i++) {
        head[i] = Insert(head[i - 1], 1, n, p[i]);
    }
}

ll cal(int u) {
    return (ll)u * (u - 1) / 2;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
    }
    init();
    for (int i = 0; i < q; i++) {
        int l, d, u, r;
        scanf("%d%d%d%d", &l, &d, &u, &r);
        ll ans = 0;
        ans += cal(Query(head[n], 1, n, u + 1, n));
        ans += cal(Query(head[n], 1, n, 1, d - 1));
        ans += cal(Query(head[l - 1], 1, n, 1, n));
        ans += cal(Query(head[n], 1, n, 1, n) - Query(head[r], 1, n, 1, n));
        ans -= cal(Query(head[n], 1, n, 1, d - 1));
        ans -= cal(Query(head[n], 1, n, u + 1, n));
        ans -= cal(Query(head[n], 1, n, u + 1, n) - Query(head[r], 1, n, u + 1, n));
        ans -= cal(Query(head[n], 1, n, 1, d - 1) - Query(head[r], 1, n, 1, d - 1));
        printf("%I64d\n", (ll)n * (n - 1) / 2 - ans);
    }
    return 0;
}
