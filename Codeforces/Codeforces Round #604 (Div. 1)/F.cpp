#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

struct edge {
    int to;
    ll v;
};

int k;
vector<edge> G[N];
ll dp[N], max_cnt;
int cnt[N];

void dfs(int u, int f) {
    // 0 not chosen
    cnt[u] = 1;
    ll res = 0;
    for (edge e : G[u]) {
        if (e.to == f) continue;
        ll cost = e.v;
        dfs(e.to, u);
        cnt[u] += cnt[e.to];
        if (cnt[e.to] & 1) res += dp[e.to] + cost;
        else res += dp[e.to];
    }
    dp[u] = res;
}

void dfs2(int u, int f) {
    for (edge e : G[u]) {
        if (e.to == f) continue;
        dfs2(e.to, u);
        ll cost = e.v;
        max_cnt += cost * min((ll)2 * k - cnt[e.to], (ll)cnt[e.to]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> k;
        for (int i = 0; i <= 2 * k; i++) {
            G[i].clear();
        }
        for (int i = 0; i < 2 * k - 1; i++) {
            int a, b, v;
            cin >> a >> b >> v;
            G[a].push_back({b, (ll)v});
            G[b].push_back({a, (ll)v});
        }
        dfs(1, -1);
        max_cnt = 0;
        dfs2(1, -1);
        cout << dp[1] << " " << max_cnt << endl;
    }
    return 0;
}