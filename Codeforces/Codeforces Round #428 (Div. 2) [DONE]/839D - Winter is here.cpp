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

const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
int pw[N];
int f[M], a[N], cnt[M];
vector<int> factors[M];

void init() {
    for (int i = 2; i < M; i++) {
        for (int j = i; j < M; j += i) {
            factors[j].pb(i);
        }
    }
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
}

int cal(int x) {
    if (x < 1) return 0;
    return (ll)x * pw[x - 1] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        for (int x : factors[a[i]]) {
            cnt[x]++;
        }
    }
    int ans = 0;
    for (int gcd = M - 1; gcd >= 2; gcd--) {
        f[gcd] = cal(cnt[gcd]);
        for (int i = 2 * gcd; i < M; i += gcd) {
            f[gcd] = (f[gcd] - f[i] + MOD) % MOD;
        }
        ans = (ans + (ll)gcd * f[gcd] % MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}

