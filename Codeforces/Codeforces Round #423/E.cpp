#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1  1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int N = 1e5 + 10;

char str[N];
int q, a[4][N], fwt[11][10][4][N];
int d[234], n;
char ch[4] = {'A', 'T', 'G', 'C'};

void add(int len, int md, int v, int p, int t) {
    while (p <= n) {
        fwt[len][md][v][p] += t;
        p += p & -p;
    }
}

int sum(int len, int md, int v, int p) {
    int res = 0;
    while (p) {
        res += fwt[len][md][v][p];
        p -= p & -p;
    }
    return res;
}

void init() {
    d['A'] = 0, d['T'] = 1, d['G'] = 2, d['C'] = 3;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = (str[j] == ch[i]);
        }
    }
    for (int len = 1; len <= 10; len++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[str[j]] == i) {
                    add(len, j % len, i, j, 1);
                }
            }
        }
    }
}

void update(int u, char s) {
    int k = d[str[u]], q = d[s];
    a[d[str[u]]][u]--;
    a[d[s]][u]++;
    for (int i = 1; i <= 10; i++) {
        add(i, u % i, k, u, -1);
    }
    for (int i = 1; i <= 10; i++) {
        add(i, u % i, q, u, 1);
    }
    str[u] = s;
}

int query(int len, int x, int md, int u) {
    return sum(len, md, x, u);
}

int main() {
    scanf("%s", str + 1);
    n = strlen(str + 1);
    init();
    scanf("%d", &q);
    while (q--) {
        int id;
        char s[12];
        scanf("%d", &id);
        if (id == 1) {
            int v;
            scanf("%d%s", &v, s);
            update(v, s[0]);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            scanf("%s", s);
            int res = 0, sz = strlen(s);
            for (int i = 0; i < sz; i++) {
                res += query(sz, d[s[i]], (l + i) % sz, r) - query(sz, d[s[i]], (l + i) % sz, l - 1);
            }
            printf("%d\n", res);
        }
    }
    return 0;
}

