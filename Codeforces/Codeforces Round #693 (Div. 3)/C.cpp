#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int dp[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = 0;
        }
        int mx = 0;
        for (int i = n; i >= 1; i--) {
            int nxt = i + a[i];
            int val = 0;
            if (nxt <= n) val = max(val, dp[nxt]); 
            dp[i] = a[i] + val;
            mx=  max(mx, dp[i]);
        }
        cout  << mx << endl;
    }
    return 0;
}