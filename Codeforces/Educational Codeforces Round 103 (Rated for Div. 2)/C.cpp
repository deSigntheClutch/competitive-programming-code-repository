#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[123456];
int b[123456];
int c[123456];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int ans = 0;
        int cur = abs(a[1] - b[1]);
        for (int i = 1; i <= n; i++) {
            if (i >= 2) 
                ans = max(cur + c[i] - 1, ans);

            if (i == n) {
                ans = max(cur + c[i] - 1, ans);
                //cout << i << ' ' << cur << " " << ans << endl;
                continue;
            }
            if (a[i] == b[i]) {
                ans = max(cur + c[i] - 1, ans);
                cur = 2;
               // cout << i << ' ' << cur << " " << ans << endl;
                continue;
            } else {
                int u = a[i], v = b[i];
                if (u > v) swap(u, v);
                cur += (u - 1) + (c[i] - v);
                cur += 2;
            }
           // cout << i << ' ' << cur << " " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}