#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MOD = 998244353;

int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            b[i] = 0;
            cin >> a[i];
        }
        for (int i = 1; i <= k; i++) {
            int t;
            cin >> t;
            b[t] = i;
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (b[a[i]] == 0) continue;
            int cnt = 0;
            if (i - 1 >= 1 && b[a[i - 1]] < b[a[i]]) cnt += 1;
            if (i + 1 <= n && b[a[i + 1]] < b[a[i]]) cnt += 1;
            ans = cnt * ans % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
