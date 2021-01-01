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

ll total, change;
int n, S;
int s[N], a[N], b[N];
pair<int, int> p[N];

ll cal(ll usedA, ll usedB) {
    if(usedA < 0) return 0;
    ll res = 0, carry = 0;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        int id = p[i].se;
        carry += s[id];
        if(carry > usedA * S) {
            flag = 0;

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> a[i] >> b[i];
        p[i] = mp(a[i] - b[i], i);
        total += s[i];
    }
    total = (ll)ceil(1.0 * total / S);
    sort(p + 1, p + 1 + n, greater<pair<int, int>>());
    for (int i = 1; i <= n; i++) {
        if (p[i].fi <= 0) break;
        change += s[p[i].se];
    }
    ll used = (ll)ceil(1.0 * change / S);
    cout << max(cal(used, total - used), cal(used - 1, total - used + 1)) << endl;
    return 0;
}

