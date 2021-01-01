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

int cnt[12], cc[12];
int c[3][6];
int n;

bool check(int u) {
    vector<int> order;
    for (int i = 0; i < n; i++) {
        order.pb(i);
    }
    memset(cnt, 0, sizeof cnt);
    int len = 0;
    while (u) {
        cnt[len++] = u % 10;
        u /= 10;
    }
    do {
        bool flag = true;
        memset(cc, 0, sizeof cc);
        for (int i = 0; i < len; i++) {
            bool ok = false;
            for (int j = 0; j < 6; j++) {
                if (c[order[i]][j] == cnt[i]) ok = true;
            }
            if (ok == false) flag = false;
        }
        if (flag) return true;
    } while (next_permutation(order.begin(), order.end()));
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> c[i][j];
        }
    }
    for (int target = 1; target <= 999; target++) {
        if (!check(target)) {
            cout << target - 1 << endl;
            return 0;
        }
    }
    cout << "999" << endl;
    return 0;
}

