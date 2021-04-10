#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int w, h, n;
        cin >> w >> h >> n;

        int cnt0 = 0, cnt1 = 0;
        while (w % 2 == 0) w /= 2, cnt0 += 1;
        while (h % 2 == 0) h /= 2, cnt1 += 1;

        if ((1ll << cnt0) * (1ll << cnt1) >= n)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}