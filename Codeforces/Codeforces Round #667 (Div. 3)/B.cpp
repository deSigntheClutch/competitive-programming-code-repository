#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int T;
int a, b, x, y, n, m;

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> a >> b >> x >> y >> n;
        int ans = a * b;
        int to_b = b - y;
        int to_a = a - x;

        if (n <= to_b) {
            ans = min(ans, a * (b - n));
        } else if (n >= to_b && n <= to_b + to_a) {
            ans = min(ans, (a - n + to_b) * y);
        } else {
            ans = min(ans, x * y);
        }
        if (n <= to_a) {
            ans = min(ans, (a - n) * b);
        } else if (n >= to_a && n <= to_b + to_a) {
            ans = min(ans, x * (b - n + to_a));
        } else {
            ans = min(ans, x * y);
        }

        cout << ans << endl;
    }
    return 0;
}
