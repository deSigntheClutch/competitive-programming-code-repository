#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int p[123];
int ans[123];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int sum = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            if (i > 1) {
                ans[i] = (100 * p[i] + k - 1) / k - sum;
                res = max(res, ans[i]);
            }
            sum += p[i];
        }
        cout << res << endl;
    }
    return 0;
}