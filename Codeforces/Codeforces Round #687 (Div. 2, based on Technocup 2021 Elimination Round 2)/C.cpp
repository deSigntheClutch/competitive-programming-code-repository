#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, k, p;
string s;
int x, y;
int dp[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> p >> k;
        p--;
        cin >> s;
        cin >> x >> y;
        for (int i = n - 1; i >= 0; i--) {
            int cost = 0;
            if (i + k <= n - 1) cost = dp[i + k];
            if (s[i] == '0') cost += x;
            dp[i] = cost;
        }
        int ans = 1e12;
        for (int i = p; i < n; i++) {
            ans = min(ans, (i - p) * y + dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
