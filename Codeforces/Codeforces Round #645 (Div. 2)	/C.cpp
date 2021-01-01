#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c || b == d) {
            cout << 1 << endl;
            continue;
        }
        int ml = min(abs(a - c), abs(b - d));
        int len = abs(a - c) + abs(b - d) - 1;
        if (2 * ml - 1 == len) {
            cout << ml * (ml + 1) / 2 + (ml - 1) * (ml) / 2 + 1 << endl;
        }
        else {
            cout << ml * (len - 2 * ml + 1) + ml * (ml + 1) / 2 + (ml - 1) * (ml) / 2 + 1 << endl;
        }
    }
    return 0;
}
