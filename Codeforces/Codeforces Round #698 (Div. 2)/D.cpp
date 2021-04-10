#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a[234567];

int _gcd(int x, int y) {
    return x ? _gcd(y % x, x) : y;
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        } 
        sort(a + 1, a + 1 + n);
        int gcd = 1000000000000000;
        for (int i = 2; i <= n; i++) {
            if (gcd == 1000000000000000) {
                gcd = a[i] - a[i - 1];
            } else {
                gcd = _gcd(a[i] - a[i - 1], gcd);
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if ((k - a[i]) % gcd == 0) {
                flag = true;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}