#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;


signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, p;
        cin >> p >> a >> b >> c;
        int ans = ((p + a - 1) / a) * a - p;
        ans = min(ans, ((p + b - 1) / b) * b - p);
        ans = min(ans, ((p + c - 1) / c) * c - p);
        cout << ans << endl;
    }
}