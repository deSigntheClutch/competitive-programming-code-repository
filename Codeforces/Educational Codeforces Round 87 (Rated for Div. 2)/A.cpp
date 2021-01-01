#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

int a, b, c, d;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        int sum = b;
        if (b >= a) {
            cout << b << endl;
            continue;
        }
        if (c <= d) {
            cout << -1 << endl;
            continue;
        }
        cout << b + (long long)ceil(1.0 * (a - b) / (c - d)) * c << endl;
    }
    return 0;
}
