#include <bits/stdc++.h>
using namespace std;

const long long INF = 9e18;
const int N = 1e5 + 10;

long long sum[N], a[N];
int x[N], y[N];
int n;
set<int> G[N];
pair<int, int> pX[N];
pair<int, int> pY[N];

struct edge {
    int a, b;
    int cost;
    bool operator < (struct edge e) const {
        return cost < e.cost;
    }
}e[N * 4];

int len;

int fa[N];

int find(int u) {
    if (fa[u] != u) return fa[u] = find(fa[u]);
    return fa[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cin >> x[i] >> y[i];
        pX[i] = {x[i], i};
        pY[i] = {y[i], i};
    }
    sort(pX + 1, pX + 1 + n);
    sort(pY + 1, pY + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n) G[pX[i].second].insert(pX[i + 1].second);
        if (i - 1 > 0) G[pX[i].second].insert(pX[i - 1].second);
    }
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n) G[pY[i].second].insert(pY[i + 1].second);
        if (i - 1 > 0) G[pY[i].second].insert(pY[i - 1].second);
    }
    for (int i = 1; i <= n; i++) {
        for (int t : G[i]) {
            e[len++] = {i, t, min(abs(x[i] - x[t]), abs(y[i] - y[t]))};
        }
    }
    sort(e, e + len);
    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < len; i++) {
        int u = find(e[i].a);
        int v = find(e[i].b);
        if (u != v) {
            cnt += 1;
            ans += e[i].cost;
            fa[u] = v;
        }
        if (cnt == n - 1) break;
    }
    cout << ans << endl;
    return 0;
}
