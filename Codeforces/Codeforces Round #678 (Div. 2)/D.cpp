#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
const int INF = 1e18;

int n;
vector<int> G[N];
int dp[N];
int a[N];

void dfs(int u, int val) {
    int empty = 0;
    for (int v : G[u]) {
        dfs(v, val);
        empty += dp[v];
        if (empty > INF) {
            empty = INF;
        }
    }
    if (G[u].size() == 0) {
        dp[u] = val - a[u];
        return;
    }
    empty -= a[u];
    dp[u] = empty;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int t, i = 0; i < n - 1; i++) {
        cin >> t;
        G[t].push_back(i + 2);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxi = *max_element(a + 1, a + 1 + n);
    int l = 0, r = 2e14 + 5, md;
    for (int i = 0; i < 53; i++) {
        md = (l + r) >> 1;
        memset(dp, 0, sizeof dp);
        int flag = 0;
        dfs(1, md);
        for (int i = 1; i <= n; i++) {
            if (dp[i] < 0) {
                flag = -1;
            }
        }
        if (flag == 0)
            r = md;
        else
            l = md + 1;
    }
    cout << r << endl;
    return 0;
}
