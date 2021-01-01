#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
long long ans;
int color[N], sz[N], sum[N]; 
vector<int> G[N];

void dfs1(int u, int f) {
    sz[u] = 1;
    for (int v : G[u]) {
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int f) {
    int tot = 0;
    for (int v : G[u]) {
        if (v == f) continue;
        int prev_sum = sum[color[u]];
        dfs2(v, u);
        int current = sz[v] - (sum[color[u]] - prev_sum);
        tot += current;
        ans += (long long)current * (current - 1) / 2;
    }
    sum[color[u]] += 1 + tot;
}

int main() {
    int tcase = 0;
    ios::sync_with_stdio(false);
    while (cin >> n) {
        ans = 0;
        memset(sum, 0, sizeof sum);
        int Ncol = 0;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            cin >> color[i];
            s.insert(color[i]);
        }
        Ncol = s.size();
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(1, -1);
        dfs2(1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[1] == i || sum[i] == 0) continue;
            int current = n - sum[i];
            ans += (long long)current * (current - 1) / 2;
        }
        cout << "Case #" << ++tcase << ": " << (long long)Ncol * n * (n - 1) / 2  - ans << endl;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
    }
    return 0;
}

/*

3
1 2 1
1 2
2 3
6
1 2 1 3 2 1
1 2
1 3
2 4
2 5
3 6

*/

