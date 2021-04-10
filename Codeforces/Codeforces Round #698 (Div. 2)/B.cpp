#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, d;
bool check[2000];

bool yes(int u) {
    while (u) {
        if (u % 10 == d) return true;
        u /= 10;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        memset(check, 0, sizeof check);
        cin >> n >> d;
        for (int i = 1; i <= 2000; i++) {
            check[i] |= yes(i);
            for (int j = 1; j * d <= i; j++) {
                if ((i - j * d) % 10 == 0) {
                    check[i] = true;
                } else if (yes(i - j * d)) {
                    check[i] = true;
                }
            }
        }
        for (int t, i = 0; i < n; i++) {
            cin >> t;
            if (t > 2000) cout << "YES" << endl;
            else cout << (check[t] ? "YES" : "NO") << endl;
        }
    }
    return 0;
}