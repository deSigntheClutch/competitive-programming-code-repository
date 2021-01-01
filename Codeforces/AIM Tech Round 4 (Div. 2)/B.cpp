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

const int N = 55 + 10;

int a[N][N];
int n, m;

ll cal(int u) {
    if (u <= 1) return 0;
    return (1ll << u) - u - 1;
}


int main() {
    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    ll ans = 0;
    for (int row = 0; row < n; row++) {
        int blk = 0, wht;
        for (int j = 0; j < m; j++) {
            blk += (a[row][j] == 1);
        }
        wht = m - blk;
        ans += cal(blk) + cal(wht);
    }
    for (int row = 0; row < m; row++) {
        int blk = 0, wht;
        for (int j = 0; j < n; j++) {
            blk += (a[j][row] == 1);
        }
        wht = n - blk;
        ans += cal(blk) + cal(wht);
    }
    ans += n * m;
    printf("%I64d\n", ans);
    return 0;
}

