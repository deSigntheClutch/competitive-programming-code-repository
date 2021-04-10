#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;
int s[234567];
int c[234567];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        map<int, int> a, b;
        map<pair<int, int>, int> cnt;
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++) {
            cin >> s[i];
            a[s[i]] += 1;
        }
        for (int i = 1; i <= k; i++) {
            cin >> c[i];
            b[c[i]] += 1;
            cnt[{s[i], c[i]}] += 1;
        }

        int ans = (k - 1) * k / 2;
        int deleted = 0;
        for (int i = 1; i <= k; i++) {
            //cout << a[s[i]] << " " << b[c[i]] << " " << cnt[{s[i], c[i]}] << endl;
            deleted += (a[s[i]] - 1) + (b[c[i]] - 1) - 2 * (cnt[{s[i], c[i]}] - 1); 
        }
        cout << ans - deleted / 2 << endl;
    }
    return 0;
}