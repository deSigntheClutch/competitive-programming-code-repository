#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    int ans = 0;
    int n;
    cin >> n;
    int x, y;
    int a, b;
    x = y = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;   
        int inc = max(0, (min(a, b) - max(x, y) + 1));
        if (x == y) inc = max(inc - 1, 0);
        ans += inc;
        x = a, y = b;
    }
    cout << ans + 1 << endl;
    return 0;
}