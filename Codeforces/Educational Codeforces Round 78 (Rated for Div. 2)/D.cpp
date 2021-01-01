#include <bits/stdc++.h>
using namespace std;
#define dadkopasdkasop find

const int N = 5e5 + 1;

struct interval {
    int l, r;
    void read() {
        cin >> l >> r;
    }
    bool operator < (struct interval i) const {
        return l < i.l;
    }
}intv[N];

int n;
int pa[N];
vector<pair<int, int>> edges;
vector<int> G[N];
bool vis[N];

int get_parent(int u) {
    if (pa[u] != u) return pa[u] = get_parent(pa[u]);
    return pa[u];
}

bool add_edge(int id1, int id2) {
    int u = get_parent(id1);
    int v = get_parent(id2);
    if (u != v) {
        pa[u] = v;
        edges.push_back({id1, id2});
        return true;
    }
    else return false;
}

void dfs(int x) {
    vis[x] = 1;
    for (int y : G[x]) {
        if (!vis[y])
            dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pa[i] = i;
        intv[i].read();
    }
    sort(intv + 1, intv + n + 1);
    set<pair<int, int>> right_end;
    for (int i = 1; i <= n; i++) {
        auto itr = right_end.lower_bound({intv[i].l, -1});
        while (itr != right_end.end() && itr->first < intv[i].r) {
            bool flag = add_edge(itr->second, i);
            if (flag == false) {
                cout << "NO" << endl;
                return 0;
            }
            if (edges.size() == n) {
                cout << "NO" << endl;
                return 0;
            }
            itr++;
        }
        right_end.insert({intv[i].r, i});
    }
    for (auto x : edges) {
        G[x.first].push_back(x.second);
        G[x.second].push_back(x.first);
    }
    bool flag = true;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) flag = false;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}