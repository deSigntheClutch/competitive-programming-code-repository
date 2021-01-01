#include <bits/stdc++.h>
using namespace std;

#define int long long
int h, c, t;

double get(int x) {
    //cout << x << " " << 1.0 * h - (1.0 * (x / 2) / x) * (h - c) << endl;
    return h - (1.0 * (x / 2) / x) * (h - c);
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> h >> c >> t;
        int l = 0, r = 1e9 + 1, md;
        for (int cs = 0; cs < 32ll; cs++) {
            md = (l + r) / 2;
            if (get(2 * md + 1) > t - 1e-7) l = md + 1;
            else r = md;
        }
        int ans = 2 * l + 1;
        double val = fabs(get(2 * l + 1) - t);
        //cout << ans  <<  " " << val << endl;
        // if (2 * l - 1 >= 1 && val + 1e-7 > fabs(get(2 * l - 1) - t)) {
        //     ans = 2 * l - 1;
        //     val = fabs(get(2 * l - 1) - t);
        // }
        // if (2 * (l - 1) - 1 >= 1 && val + 1e-7 > fabs(get(2 * (l - 1) - 1) - t)) {
        //     ans = 2 * (l - 1)  - 1;
        //     val = fabs(get(2 * (l - 1)  - 1) - t);
        // }
        if (2 * (l + 1) - 1 >= 1 && val > fabs(get(2 * (l + 1) - 1) - t)) {
            ans = 2 * (l + 1) - 1;
            val = fabs(get(2 * (l + 1) - 1) - t);
        }
        if (val + 1e-7 > fabs(0.5 * (h + c) - t)) {
            ans = 2;
            val = fabs(0.5 * (h + c) - t);
        }
        cout << ans << endl;
    }
    return 0;
}
// 1 41 15 30