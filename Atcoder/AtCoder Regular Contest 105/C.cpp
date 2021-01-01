#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 1;

int n, m;
int w[N];
int l[N], v[N];
int t[N], vv;
vector<pair<int, int>> G[N];
int dp[N];
int max_len[N];
vector<int> val;

void dfs(int u) {
    for (auto x : G[u]) {
        int to = x.first;
        int v = x.second;
        dfs(to);
        dp[u] = max(dp[u], dp[to] + v);
    }
}

int cal(vector<int> order) {
    for (int i = 0; i < n; i++) {
        G[i].clear();
        dp[i] = 0;
    }
    int sum_weight = 0;
    for (int i = 0; i < n; i++) {
        sum_weight = w[order[i]];
        for (int j = 1 + i; j < n; j++) {
            int next_weight = sum_weight + w[order[j]] - 1;
            int id = upper_bound(val.begin(), val.end(), next_weight) - val.begin();
            id--;
            if (id < 0) {
                G[order[i]].push_back({order[j], 0});
            } else {
                G[order[i]].push_back({order[j], max_len[id]});
            }
            sum_weight += w[order[j]];
        }
    }
    dfs(order[0]);
    return dp[order[0]];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> v[i];
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (w[j] > v[i]) {
                flag = true;
            }
        }
        if (flag == true) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < m; i++) {
        val.push_back(v[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    vv = val.size();
    for (int i = 0; i < m; i++) {
        int id = lower_bound(val.begin(), val.end(), v[i]) - val.begin();
        max_len[id] = max(max_len[id], l[i]);
    }
    for (int i = 1; i < vv; i++) {
        max_len[i] = max(max_len[i - 1], max_len[i]);
    }
    vector<int> order;
    for (int i = 0; i < n; i++) order.push_back(i);
    int ans = INF;
    do {
        int current = cal(order);
        ans = min(ans, current);
    } while (next_permutation(order.begin(), order.end()));
    cout << ans << endl;
    return 0;
}

/*

8 20
57 806 244 349 608 849 513 857
778 993
939 864
152 984
308 975
46 860
123 956
21 950
850 876
441 899
249 949
387 918
34 965
536 900
875 889
264 886
583 919
88 954
845 869
208 963
511 975

*/