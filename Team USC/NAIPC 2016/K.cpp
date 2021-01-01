#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18;
 
struct Line {
      long long a, b;
      long long get(long long x) {
            return a * x + b;
      }
};
 
struct ConvexHull {
    int size;
    vector<Line> hull;
 
    ConvexHull() {
        this->clear();
    }
 
    void clear() {
        hull.clear();
        size = 0;
    }
 
    bool is_bad(long long curr, long long prev, long long next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }
 
    void add_line(long long a, long long b) {
        hull.push_back((Line){a, b});
        size += 1;
        while (size > 2 && is_bad(size - 2, size - 3, size - 1)) hull[size - 2] = hull[size - 1], size--, hull.pop_back();
    }
    void print() {
        for (auto x : hull) {
            cout << x.a << " " << x.b << endl;
        }
    }
    long long query(long long x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
                int m = (l + r) / 2;
                if (hull[m].get(x) <= hull[m + 1].get(x))
                    l = m;
                else
                    r = m;
        }
        return hull[r].get(x);
    }
};
 
struct Edge {
    int to;
    long long cost;
};
 
int n;
vector<Edge> G[N];
int max_subtree_size[N], subtree_size[N];
long long ans[N], val[N];
bool used[N]; 
 
int get_centroid(int u, int f, int total_num) {
    int root = -1;
    subtree_size[u] = 1;
    max_subtree_size[u] = 0;
 
    for (Edge x : G[u]) {
        int v = x.to;
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
 
void dfs(int u, int f, long long sum, vector<pair<int, long long>> &vec) {
    vec.push_back({u, sum});
    for (Edge e : G[u]) {
        int v = e.to;
        if (f == v || used[v]) continue;
        dfs(v, u, sum + e.cost, vec);
    }
}
 
ConvexHull hull; 

bool cmp(pair<int, long long> a, pair<int, long long> b) {
    if (val[a.first] == val[b.first]) return a.second < b.second;
    return val[a.first] > val[b.first];
}

void solve(int root, int total_num) {
    int centroid = get_centroid(root, -1, total_num);
    hull.clear();
    vector<pair<int, long long>> vec;
    dfs(centroid, -1, 0, vec);
    sort(vec.begin(), vec.end(), cmp);

    for (auto p : vec) {
        hull.add_line(-val[p.first], -p.second);
    }
    for (auto p : vec) {
        cout << p.first << val[p.first] << " " <<" " << p.second << endl;
        ans[p.first] = min(ans[p.first], -hull.query(val[p.first]) + p.second);
    }
    cout << endl;
    used[centroid] = true;
    for (Edge e : G[centroid]) {
        int v = e.to;
        if (!used[v]) {
            solve(v, subtree_size[v]);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
 
    for (int i = 1; i <= n; i++) {
        ans[i] = INF;
        cin >> val[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        G[x].push_back((Edge){y, z});
        G[y].push_back((Edge){x, z});
    }
 
    solve(1, n);
 
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += min(val[i] * val[i], ans[i]);
    }
    cout << res << endl;
    return 0;
}
 
/*
 
5
9 7 1 1 9
3 2 8
5 2 10
4 3 10
2 1 2
 
*/