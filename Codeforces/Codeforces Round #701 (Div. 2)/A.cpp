#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 5;

int a, b;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int ans = 1e9 + 1;
        for (int i = 0; i < 100; i++) {
            if (b == 1 && i == 0) continue;
            int cur = i;
            int x = b + i;
            int y = a;
            while (y) {
                y /= x;
                cur += 1;
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
}