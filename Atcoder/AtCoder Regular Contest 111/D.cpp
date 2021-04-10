#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<int> G[N];
int c[N];
string ans[N];
pair<int, int> p[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        p[i] = {c[i], i};
    }
    
    return 0;
}