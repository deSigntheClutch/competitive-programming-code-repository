#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;

int m, n;
int c[N], k[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> k[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> c[i];
        }
        sort(k + 1, k + 1 + n);
        int cost = 0;
        for (int i = n; i >= 1; i--) {
            cost += c[k[i]];
        }
        int ans = cost;
        for (int i = 1; i <= m; i++) {
            if (n + 1 - i >= 1 && i <= k[n + 1 - 1]) {
                cost = cost - c[k[n + 1 - i]] + c[i];
                //cout << cost << endl;
                ans = min(ans, cost);
            } else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}