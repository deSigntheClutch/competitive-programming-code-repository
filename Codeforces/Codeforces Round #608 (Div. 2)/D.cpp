#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 5;
typedef long long ll;
 
int n, m, k;
int a[N], b[N], c[N];
int dp[N][N];
int portal[N];
vector<int> G[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int sum = k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        sum += b[i];
    }
    for (int i = 0; i < m; i++) {
        int a , b;
        cin >> a >> b;
        portal[b] = max(portal[b], a);
    }
    for (int i = 1; i <= n; i++) {
        G[portal[i]].push_back(i);
    }

    memset(dp, -1, sizeof dp);
    dp[0][k] = 0;
    int cur_k = k;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= sum; j++) {
            if (dp[i - 1][j] == -1) continue;
            dp[i][j + b[i]] = dp[i - 1][j];
        }
        if (portal[i] == 0) {
            for (int j = 1; j <= sum; j++) {
                if (dp[i][j] == -1) continue;
                if (j >= 1) dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + c[i]);
            }
        }
        for (int x : G[i]) {
            for (int j = 1; j <= sum; j++) {
                if (dp[i][j] == -1) continue;
                if (j >= 1) dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + c[x]);
            }
        }
    }
    int max_val = -1;
    for (int j = 0; j <= sum; j++) {
        max_val = max(max_val, dp[n][j]);
    }
    cout << max_val << endl;
    return 0;
}