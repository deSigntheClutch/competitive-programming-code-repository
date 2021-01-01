#include <bits/stdc++.h>
using namespace std;
#define debug(x, a, b) for(int (ii)=(a);(ii)<(b);(ii++)) printf("%d: %d\n", ii, x[ii]);
#define mp make_pair
#define pb push_back
#define fi first
#define se second
 
const int N = 1e5 + 10;
 
struct edge {
    int x, y, cost;
    bool operator < (struct edge e) const {
        return cost > e.cost;
    }
};
 
vector<edge> edges;
int n;
int x[N], y[N];
pair<int, int> p[N];
int pa[N];

void init() {
    for (int i = 1; i <= n; i++) {
        pa[i] = i;
    }
}
 
int f(int x) {
    if (pa[x] != x) return pa[x] = f(pa[x]);
    else return pa[x];
}
 
int Kruskal() {
    sort(edges.begin(), edges.end());
    int cnt = 0;
    for (edge e : edges) {
        int u = f(e.x), v = f(e.y);
        if (u != v) {
            pa[u] = v;
            cnt += 1;
        } 
        if (cnt == n - 1) {
            return e.cost;
        }
    }
}

void add_edge(int x, int y) {
    if (x == y) return;
    else edges.push_back((edge){x + 1, y + 1, max(abs(p[x].first - p[y].first), abs(p[x].second - p[y].second))});
}
 
int main() {
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; i++) {
        scanf("%d %d", x + i, y + i);
        int tx = (x[i] + y[i]);
        int ty = (x[i] - y[i]);
        p[i] = {tx, ty};
    }
    sort(p, p + n);
    int min_y_id =-1, max_y_id = -1;
    int max_val = -2e9 - 10, min_val = 2e9 + 10;
    for (int i = 0; i < n; i++) {
        if (p[i].second < min_val) min_val = p[i].second, min_y_id = i;
        if (p[i].second > max_val) max_val = p[i].second, max_y_id = i;
    }
    for (int i = 0; i < n; i++) {
        add_edge(i, 0);
        add_edge(i, n - 1);
        add_edge(i, min_y_id);
        add_edge(i, max_y_id);
    }
    printf("%d\n", Kruskal());
    return 0;
}