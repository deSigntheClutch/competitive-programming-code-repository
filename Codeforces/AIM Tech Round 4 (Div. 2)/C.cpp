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
int a[N], b[N];
int loop[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
    vector<vector<int>> vec;
    for (int i = 1; i <= n; i++) {
        if (loop[i]) continue;
        int pt = i;
        loop[i] = 1;
        vector<int> v;
        v.pb(i);
        pt = a[i];
        while (pt != i) {
            loop[pt] = 1;
            v.pb(pt);
            pt = a[pt];
        }
        vec.pb(v);
    }
    cout << (int)vec.size() << endl;
    for (vector<int> v : vec) {
        cout << (int)v.size();
        for (int x : v) {
            cout << " " << x;
        }
        cout << endl;
    }
    return 0;
}

