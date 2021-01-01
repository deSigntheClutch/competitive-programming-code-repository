#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
const int M = 1e2 + 4;
const int INF = 1e9 + 5;

int n, a[N];
int xorsum[M];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t ^= a[i];
        if (n <= 66) {
            xorsum[i] = t;
        }
    }
    if (n > 66) cout << 1 << endl;
    else {
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int p = j + 1; p <= n; p++) {
                    for (int q = p; q <= n; q++) {
                        if ((xorsum[j] ^ xorsum[i - 1]) > (xorsum[q] ^ xorsum[p - 1])) {
                            ans = min(ans, j - i + q - p);
                        }
                    }
                }
            }
        }
        if (ans == INF) ans = -1; 
        cout << ans << endl;
    }
    return 0;
}
