#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 6;

int n, m;
int s[N], y[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        vector<int> a, b;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> y[i];
            if (y[i] == 1) {
                a.push_back(s[i]);
            } else {
                b.push_back(s[i]);
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        int cur = 0;
        for (int x : b) cur += x;

        int ans = (int)2 * b.size();
        int pt = (int)b.size() - 1;
        int res = 999999999;
        while (pt >= 0) {
            if (cur - b[pt] >= m) {
                cur -= b[pt];
                pt -= 1;
                ans -= 2;
            } else {
                break;
            }
        }
        if (cur >= m) res = ans;

        for (int i = 0; i < a.size(); i++) {
            cur += a[i];
            ans += 1;
            while (pt >= 0) {
                if (cur - b[pt] >= m) {
                    cur -= b[pt];
                    pt -= 1;
                    ans -= 2;
                } else {
                    break;
                }
            }
            if (cur >= m) res = min(res, ans);
        }

        if (res != 999999999) {
            cout << res << endl;
        } else
            cout << -1 << endl;
    }
    return 0;
}