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

const int N = 10 + 5;
const int M = 1e5 + 10;

int n, m, q;
int a[N][M], fa[i][j];
int t[M << 2];

int getId(int x, int y) {

}

int find(int x) {

}

void unite(int u, int v, int x, int y) {
    int a = find()
}

int uniteLine(int x) {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int pt = i;
        while(num[i][x] == num[pt][x] && pt < n) {
            unite(i, x, pt, x);
            pt++;
        }
        res++;
        i = pt - 1;
    }
    return res;
}

void build(int rt, int left, int right) {
    if(left == right) {
        t[rt] = uniteLine(left);
        return ;
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fa[i][j] = (i - 1) * m + j;
        }
    }
    build(1, 1, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    init();
    while (q--) {
        int l, r;
        cout << Q(l, r) << endl;
    }
    return 0;
}
