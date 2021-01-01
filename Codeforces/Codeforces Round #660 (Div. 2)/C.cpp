#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int n, m;
int p[N];
int h[N];
vector<int> G[N];
bool flag = true;
int sum = 0;

void dfs(int u, int f) {
    int tmp = h[u];
    for (int v : G[u]) {
        if (f == v) continue;
        dfs(v, u);
        tmp -= h[v];
    }
    if (u == 1) {

        if (abs(sum % 2) == abs(tmp % 2) && sum >= tmp && sum + tmp >= 0) {
            return ;
        }
        cout << sum << " ------" << tmp << endl;
        flag = false;
        return ;
    }
    if (abs(p[u] % 2) == abs(tmp % 2) && p[u] >= tmp && p[u] + tmp >= 0) {
        return;
    } else {

        cout << tmp << " + " << u << endl;
        flag = false;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        sum = 0;
        flag = true;
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            sum += p[i];
        }
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        // int sum = 0;
        // for (int i = 2; i <= n; i++) {
        //     sum += abs(dp[i]);
        //     cout << dp[i] << endl;
        // }
        // cout << dp[1] << endl;
        // if (m >= sum && (m - sum == abs(h[1]) || (m - sum > abs(h[1]) && (m - sum - abs(h[1])) % 2 == 0))) cout << "YES" << endl;
        // else cout << "NO" << endl;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}