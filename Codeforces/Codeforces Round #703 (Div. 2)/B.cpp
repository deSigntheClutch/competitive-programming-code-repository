#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;

int T;
int n, m;
int x[N], y[N];
signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        sort(x, x + n);
        sort(y, y + n);
        if (n & 1) cout << 1 << endl;
        else cout << (x[n / 2] - x[n /2 - 1] + 1) * (y[n / 2] - y[n /2 - 1] + 1) << endl;
    }
}