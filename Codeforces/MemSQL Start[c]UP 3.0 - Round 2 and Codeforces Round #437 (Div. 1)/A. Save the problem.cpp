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

const int N = 1e6 + 10;

int n;
ll f[N];
int vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    f[0] = 1;
    for (int j = 1; j <= 2; j++) {
        for (int i = 1; i < N; i++) {
            if(i - j >= 0) f[i] += f[i - j];
        }
    }
    for (int i = 1; i < N; i++) {
        if (f[i] < N && f[i] >= 0) {
            vis[f[i]] = i;
        }
    }
    cout << vis[n] << " " << 2 << endl;
    cout << 1 << " " << 2 << endl;
    return 0;
}

