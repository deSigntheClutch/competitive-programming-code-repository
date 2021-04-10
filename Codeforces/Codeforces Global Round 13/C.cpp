#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int M = 123;

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
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int needed = a[i] - 1;
            if (dp[i] > needed) {
                for (int jump = 2; jump <= a[i] && jump + i <= n; jump++) {
                    dp[i + jump] += 1;
                }
                dp[i + 1] += dp[i] - needed;
            } else {
                cnt += needed - dp[i];
                for (int jump = 2; jump <= a[i] && jump + i <= n; jump++) {
                    dp[i + jump] += 1;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
