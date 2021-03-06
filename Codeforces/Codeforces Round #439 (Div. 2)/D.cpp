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

int n;
int a[N], b[N], vis[10000002];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
        vis[b[j]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int u = a[i] ^ b[j];
            if (u > (int)1e7) continue;
            if (vis[u] == 1) cnt++;
        }
    }
    if (cnt & 1)cout << "Koyomi" << endl;
    else cout << "Karen" << endl;
    return 0;
}

