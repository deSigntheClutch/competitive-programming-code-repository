#include <bits/stdc++.h>
using namespace std;

const int W = 1e5 + 5;
const int S = 3e2 + 5;

int n, k;
int max_s;
vector<long long> opt[S];
long long dp[S][W];

void solve(int l, int r, int x, int y, int sz, int rem) {
    if (l > r) return ;
    int md = (l + r) >> 1; 
    int current_decision = md;
    dp[sz][rem + md * sz] = dp[sz - 1][rem + md * sz];
    for (int i = min(md - 1, y); i >= x; i--) {
        int number_of_items = md - i;
        if (number_of_items > opt[sz].size()) continue;
        if (dp[sz - 1][rem + i * sz] + opt[sz][number_of_items - 1] > dp[sz][rem + md * sz]) {
            dp[sz][rem + md * sz] = dp[sz - 1][rem + i * sz] + opt[sz][number_of_items - 1];
            current_decision = i;
        }
    }
    solve(l, md - 1, x, current_decision, sz, rem);
    solve(md + 1, r, current_decision, y, sz, rem);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
       int w, v;
       cin >> w >> v;
       max_s = max(max_s, w);
       opt[w].push_back(v);
    }
    for (int i = 1; i < S; i++) {
        sort(opt[i].begin(), opt[i].end(), greater<long long>());
        for (int j = 1; j < opt[i].size(); j++) {
            opt[i][j] += opt[i][j - 1];
        }
    }
    for (int i = 1; i <= max_s; i++) {
        if (opt[i].size() == 0) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }
        for (int reminder = 0; reminder < i; reminder++) {
            solve(0, (k - reminder) / i, 0, (k - reminder) / i, i, reminder);
        }
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << dp[max_s][i] << " ";
    }
    cout << endl;
    return 0;
}