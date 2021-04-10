#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m = 1;
int a[N], b[N];
int dp[N], sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != a[i - 1]) {
            b[m++] = a[i];
        }
    }
    dp[0] = 0;
    for (int i = 1; i < m; i++) {
        int v = b[i];
        dp[i] = dp[i - 1] + 1;
        dp[i] = min(dp[i], i - sum[v]); 
        sum[v] = max(sum[v], i + 1 - dp[i]);
        cout << dp[i] << ' ';
    }
    cout << dp[m - 1] << endl;
}