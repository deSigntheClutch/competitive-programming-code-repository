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
        bool f = false;
        for (int i = 0; i * 2021 <= n; i++) {
            if ((n - i * 2021) % 2020 == 0) {
                cout << "yes" << endl;
                f = true;
                break;
            }
        }
        if (!f) cout << "no" << endl;
    }
    return 0;
}