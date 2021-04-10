#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 5;

int x, y;

signed main() {
    // for (int i = 1; i <= 50; i++) {
    //     for (int j = 1; j <= 3; j++) {
    //         if (i / j == i % j) {
    //             cout << i << " " << j << endl;
    //         }
    //     }
    // }
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        double c = sqrt(x * 1.0);
        int ans = 0;
        for (int r = 1; r <= c; r++) {
            if (r >= y) break;
            ans += max(0ll, min(r * (y + 1), x) / r - (r + 1));
            //cout << ans << endl;
        }
        cout << ans << endl;
        //cout << "---" << endl;
    }
}