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

const int N = 1e5 + 1;
int n, a[71];
int g[71];
int f[71][1 << 19];
bool isn[71];
int pr[71], l;
int pw[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
        int t;
        cin >> t;
        a[t]++;
    }
    for (int i = 2; i <= 70; i++) {
        if (isn[i] == true) continue;
        pr[l++] = i;
        for (int j = 2 * i; j <= 70; j += i) {
            isn[j] = true;
        }
    }
    for (int i = 1; i <= 70; i++) {
        for (int j = 0; j < l; j++) {
            int t = i;
            int cnt = 0;
            while (t % pr[j] == 0) t /= pr[j], cnt++;
            if (cnt & 1) g[i] |= (1 << j);
        }
    }
    f[0][0] = 1;
    for (int i = 1; i <= 70; i++) {
        if (a[i] == 0) {
            for (int j = 0; j < (1 << l); j++) {
                f[i][j] = f[i - 1][j];
            }
            continue;
        }
        for (int j = 0; j < (1 << l); j++) {
            if (f[i - 1][j] == 0) continue;
            f[i][j ^ g[i]] = (f[i][j ^ g[i]] + (long long)(pw[a[i] - 1]) * f[i - 1][j]) % MOD;   // odd
            f[i][j] = (f[i][j] + (long long)(pw[a[i] - 1]) * f[i - 1][j]) % MOD;    // even
        }
    }
    cout << f[70][0] - 1 << endl;
    return 0;
}

