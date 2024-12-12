#include "bits/stdc++.h"
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const double PI = acos(-1.0);
 
int n, max_deep;
vector<int> G[N];
int max_subtree_size[N], subtree_size[N];
int ans[N << 1];
int inv[N];
bool used[N];
 
void init() {
    inv[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        inv[i] = (long long)inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
}
 
struct base {
    double a, b;
    base() { a = 0, b = 0; }
    base(double a, double b) : a(a), b(b) {}
    base operator + (const base& y) const { return (base) {a + y.a, b + y.b}; }
    base operator - (const base& y) const { return (base) {a - y.a, b - y.b}; }
    base operator * (const base& y) const { return (base) {a * y.a - b * y.b, a * y.b + b * y.a}; }
    base operator ! () const { return (base) {a, -b}; }
};
 
void fft(vector<base> & a, bool invert) {
    int n = (int)a.size(), lg_n = 0;
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1, 0);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j],  v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) {
            a[i].a /= n;
            a[i].b /= n;
        }
    }
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
    vector<base> fa, fb;
    for (auto x : a) fa.push_back(base(x, 0));
    for (auto x : b) fb.push_back(base(x, 0));
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);
    fft(fa, false),  fft(fb, false);
    for (size_t i = 0; i < n; ++i) {
        fa[i] = fa[i] * fb[i];
    }
    fft(fa, true);
    res.resize(n);
    for (size_t i = 0; i < n; ++i) {
        res[i] = (long long)(fa[i].a + 0.5) % MOD;
    }
}

int get_centroid(int u, int f, int total_num) {
    int root = -1;
    subtree_size[u] = 1;
    max_subtree_size[u] = 0;
 
    for (int v : G[u]) {
        if (f == v || used[v]) continue;
        int cur_root = get_centroid(v, u, total_num);
        if (root == -1 || max_subtree_size[root] > max_subtree_size[cur_root]) root = cur_root;
        subtree_size[u] += subtree_size[v];
        max_subtree_size[u] = max(max_subtree_size[u], subtree_size[v]);
    }
    max_subtree_size[u] = max(max_subtree_size[u], total_num - subtree_size[u]);
    if (root == -1 || max_subtree_size[root] > max_subtree_size[u]) root = u;
    return root;
}
 
void dfs(int u, int f, int depth, vector<int> &cnt) {
    cnt[depth] += 1;
    max_deep = max(max_deep, depth);
 
    for (int v : G[u]) {
        if (f == v || used[v]) continue;
        dfs(v, u, depth + 1, cnt);
    }
}
 
void solve(int root, int total_num) {
    int centroid = get_centroid(root, -1, total_num);
    vector<int> cnt(max_subtree_size[centroid] + 2, 0), res;
    max_deep = 0;
    dfs(centroid, -1, 0, cnt);
    used[centroid] = true;
    multiply(cnt, cnt, res);
 
    for (int i = 0; i <= 2 * max_deep; i++) {
        ans[i] = (ans[i] + res[i]) % MOD;
    }
 
    for (int v : G[centroid]) {
        if (used[v]) continue;
        vector<int> duplicated;
        for (int i = 0; i <= max_deep; i++) cnt[i] = 0;
        dfs(v, centroid, 1, cnt);
        multiply(cnt, cnt, duplicated);
        for (int i = 0; i <= 2 * max_deep; i++) {
            ans[i] = (ans[i] + MOD - duplicated[i]) % MOD;
        }
    }
 
    for (int v : G[centroid]) {
        if (!used[v]) {
            solve(v, subtree_size[v]);
        }
    }
}
 
int main() {
    scanf("%d", &n);
    init();
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
 
    solve(1, n);
 
    int res = 0;
    for (int i = 0; i <= n; i++) {
        res = (res + (long long)ans[i] * inv[i + 1] % MOD) % MOD;
    }
    for (int i = 2; i <= n; i++) {
        res = (long long)res * i % MOD;
    }
    printf("%d\n", res);
    return 0;
}