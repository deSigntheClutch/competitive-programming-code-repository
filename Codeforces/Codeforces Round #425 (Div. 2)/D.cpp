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
const int LOG_N = 19;

int n, Q;
int fa[LOG_N][N], depth[N];
vector<int> G[N];

void dfs1(int u, int f, int dep) {
    fa[0][u] = f, depth[u] = dep;
    for (int e : G[u]) {
        if (e == f) continue;
        dfs1(e, u, dep + 1);
    }
}

void initLCA() {
    for (int i = 0; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i][j] = -1;
        }
    }
    dfs1(1, -1, 0);
    for (int i = 1; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            if (fa[i - 1][j] != -1) {
                fa[i][j] = fa[i - 1][fa[i - 1][j]];
            }
        }
    }
}

int query(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int w = depth[b] - depth[a], cnt = 0;
    while (w) {
        if (w & 1) b = fa[cnt][b];
        w >>= 1, cnt++;
    }
    if (a == b) return a;
    for (int i = LOG_N - 1; i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            a = fa[i][a], b = fa[i][b];
        }
    }
    return fa[0][a];
}

bool isAncestor(int a, int b) {
    if (depth[b] < depth[a]) return false;
    int w = depth[b] - depth[a], cnt = 0;
    while (w) {
        if (w & 1) b = fa[cnt][b];
        w >>= 1, cnt++;
    }
    return a == b;
}

int cal(int a, int b, int x) {
    //printf("%d %d %d:\n", a, b, x);
    if (depth[a] > depth[b]) swap(a, b);
    int lca = query(a, b), res = 0;
    int len_a = depth[a] - depth[lca], len_b = depth[b] - depth[lca];
    int x_a = query(x, a), x_b = query(x, b);
    if (lca == a) {
        //puts("a");
        if (x_b == b) return max(len_a, len_b) + 1;
        else {
            if (isAncestor(lca, x_b)) return max(depth[x_b] - depth[a], depth[b] - depth[x_b]) + 1;
            else return max(len_a, len_b) + 1;
        }
    }
    //printf("%d %d %d %d %d\n", lca, x_a, x_b, len_a, len_b);
    //printf("%d - > ", res);
    if (x_a != lca && isAncestor(lca, x_a)) {
        res = max(res, max(depth[a] - depth[x_a], depth[x_a] - depth[lca] + depth[b] - depth[lca]) + 1);
        //printf("%d - a >", res);
    }
    if (x_b != lca && isAncestor(lca, x_b)) {
        res = max(res, max(depth[b] - depth[x_b], depth[x_b] - depth[lca] + depth[a] - depth[lca]) + 1);
        //printf("%d - b >", res);
    }
    if(res == 0) res = max(res, max(len_a, len_b) + 1);
    //printf(" - > %d\n", res);
    return res;
}

int main() {
    scanf("%d%d", &n, &Q);
    for (int i = 0; i < n - 1; i++) {
        int p;
        scanf("%d", &p);
        G[p].push_back(i + 2);
        G[i + 2].push_back(p);
    }
    initLCA();
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int mx = 1;
        mx = max(mx, cal(a, b, c));
        mx = max(mx, cal(a, c, b));
        mx = max(mx, cal(b, c, a));
        printf("%d\n", mx);
    }
    return 0;
}

/*

8 4
1 2 3 4 3 2 7
5 8 8
4 1 6
2 8 5
4 8 5

51 1
3 34 38 38 3 24 43 46 14 31 48 1 1 6 34 43 39 1 23 50 4 46 14 35 62 52 15 51 58 50 1 3 24 4 8 26 1 13 7 13 13 1 10 6 34 34 35 3 4 16
31 44 29

*/
