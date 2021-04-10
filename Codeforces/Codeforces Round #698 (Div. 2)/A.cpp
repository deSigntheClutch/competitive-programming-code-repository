#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            cnt[t] += 1;
            ans = max(ans, cnt[t]);
        }
        cout << ans << endl;
    }
    return 0;
}