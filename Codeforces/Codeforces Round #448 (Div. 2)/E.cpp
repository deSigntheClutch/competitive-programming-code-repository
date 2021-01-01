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

double t[N << 3], lazy1[N << 3], lazy2[N << 3];
int n, m;

void push_down(int rt, int len) {
    if (!(lazy1[rt] == 1 && lazy2[rt] == 0)) {
        lazy1[rt << 1] *= lazy1[rt], lazy2[rt << 1] *= lazy1[rt], lazy2[rt << 1] += lazy2[rt];
        t[rt << 1] *= lazy1[rt], t[rt << 1] += lazy2[rt] * (len - len / 2);
        lazy1[rt << 1 | 1] *= lazy1[rt], lazy2[rt << 1 | 1] *= lazy1[rt], lazy2[rt << 1 | 1] += lazy2[rt];
        t[rt << 1 | 1] *= lazy1[rt], t[rt << 1 | 1] += lazy2[rt] * (len / 2);
        lazy1[rt] = 1, lazy2[rt] = 0;
    }
}

void push_up(int rt) {
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}

void build(int rt, int left, int right) {
    lazy1[rt] = 1;
    if (left == right) {
        cin >> t[rt];
        return ;
    }
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int rt, int left, int right, int l, int r, double v, double w) {
    push_down(rt, right - left + 1);
    if (left == l && r == right) {
        t[rt] *= v, t[rt] += (right - left + 1) * w;
        lazy1[rt] = v;
        lazy2[rt] = w;
        return ;
    }
    if (mid >= r) update(lson, l, r, v, w);
    else if (mid < l) update(rson, l, r, v, w);
    else update(lson, l, mid, v, w), update(rson, mid + 1, r, v, w);
    push_up(rt);
}

double sum(int rt, int left, int right, int l, int r) {
    push_down(rt, right - left + 1);
    if (left == l && r == right) {
        return t[rt];
    }
    if (mid >= r) return sum(lson, l, r);
    else if (mid < l) return sum(rson, l, r);
    else return sum(lson, l, mid) + sum(rson, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int type, r1, r2, l1, l2;
        cin >> type;
        if (type == 1) {
            cin >> l1 >> r1 >> l2 >> r2;
            double s1 = sum(1, 1, n, l1, r1) / (r2 - l2 + 1) / (r1 - l1 + 1), s2 = sum(1, 1, n, l2, r2) / (r1 - l1 + 1) / (r2 - l2 + 1);
            double v1 = 1 - 1.0 / (r1 - l1 + 1), v2 = 1 - 1.0 / (r2 - l2 + 1);
            update(1, 1, n, l1, r1, v1, s2);
            update(1, 1, n, l2, r2, v2, s1);
        } else {
            cin >> l1 >> r1;
            cout << fixed << setprecision(10) << sum(1, 1, n, l1, r1) << endl;
        }
    }
    return 0;
}
/*

10 10
1 2 3 4 5 6 7 8 9 10
1 1 5 6 10
1 1 3 6 9
1 5 7 8 10
1 1 1 10 10
2 1 5

*/
