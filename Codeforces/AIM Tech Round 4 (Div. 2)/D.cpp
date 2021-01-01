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

int n, start, ui;
int vis[N], len;
pair<int, pair<int, int>> p[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> start >> ui;
    cout << "?" << " " << start << endl;
    fflush(stdout);
    int next, value;
    cin >> value >> next;
    vis[start] = 1;
    p[len++] = mp(value, mp(start, next));
    if (ui <= value) {
        cout << "!" << " " << value << endl;
        return 0;
    }
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        pos.pb(i);
    }
    random_shuffle(pos.begin(), pos.end());
    int t = 1200;
    for (int x : pos) {
        if (vis[x]) continue;
        vis[x] = 1;
        t--;
        cout << "?" << " " << x << endl;
        fflush(stdout);
        cin >> value >> next;
        p[len++] = mp(value, mp(x, next));
        if (t == 0) break;
    }
    t = 795;
    sort(p, p + len);
    int u = upper_bound(p, p + len, mp(ui, mp(1000000009, 1000000009))) - p;
    int v = u - 1;
    if (p[v].fi == ui) {
        cout << "! " << p[v].fi << endl;
        return 0;
    }
    int x = p[v].se.se;
    while (t--) {
        if(x == -1) break;
        cout << "?" << " " << x << endl;
        fflush(stdout);
        cin >> value >> next;
        if (value >= ui) {
            cout << "! " << value << endl;
            return 0;
        }
        if (next == -1) break;
        x = next;
    }
    cout << "! -1" << endl;
    return 0;
}
