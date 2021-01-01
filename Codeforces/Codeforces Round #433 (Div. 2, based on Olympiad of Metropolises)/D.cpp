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
const ll INF = 9e17 + 4;
const int N = 1e5 + 10;

struct flight {
    int d;
    int f, t;
    ll c;
    bool operator < (struct flight u) const {
        return d < u.d;
    }
} f[N];

int n, m, k;
multiset<ll> bl[N], bg[N];
ll m1 = 0, m2 = 0;
int cntl, cntg;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%I64d", &f[i].d, &f[i].f, &f[i].t, &f[i].c);
    }
    sort(f, f + m);
    int bound = 0;
    for (int i = 0; i < m; i++) {
        if (f[i].f == 0) {
            if ((int)bl[f[i].t].size() == 0) {
                cntl++;
                m2 += f[i].c;
                bl[f[i].t].insert(f[i].c);
            } else {
                m2 -= *bl[f[i].t].begin();
                bl[f[i].t].insert(f[i].c);
                m2 += *bl[f[i].t].begin();
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < m; i++) {
        while (f[bound].d <= f[i].d + k && bound < m) {
            if (f[bound].f == 0) {
                m2 -= *bl[f[bound].t].begin();
                auto kk = bl[f[bound].t].find(f[bound].c);
                bl[f[bound].t].erase(kk);
                if ((int)bl[f[bound].t].size() == 0) {
                    cntl--;
                } else {
                    m2 += *bl[f[bound].t].begin();
                }
            }
            bound++;
        }
        if (f[i].t == 0) {
            if ((int)bg[f[i].f].size() == 0) {
                cntg++;
                bg[f[i].f].insert(f[i].c);
                m1 += f[i].c;
            } else {
                m1 -= *bg[f[i].f].begin();
                bg[f[i].f].insert(f[i].c);
                m1 += *bg[f[i].f].begin();
            }
        }
        if (cntg == cntl && cntl == n) {
            ans = min(ans, m1 + m2);
        }
    }
    if (ans == INF) puts("-1");
    else printf("%I64d\n", ans);
    return 0;
}

