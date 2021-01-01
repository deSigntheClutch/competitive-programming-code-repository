#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 16;
const int M = 2e5 + 4;

int n;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        ans = max(ans, c - 1 + d - 1);
        ans = max(ans, c - 1 + b - d);
        ans = max(ans, a - c + b - d);
        ans = max(ans, a - c + d - 1);
        cout << ans << endl;
    }
    return 0;
}
