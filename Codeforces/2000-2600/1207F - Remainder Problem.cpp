#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int K = 800 + 5;

int n;
int a[N];
int dp[K][K];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int type;
        int x, y;

        cin >> type;
        if (type == 1) {
            cin >> x >> y;
            a[x] += y;
            for (int i = 1; i < K; i++) {
                dp[i][x % i] += y;
            }
        } else {
            cin >> x >> y;

            if (x >= K) {
                int res = 0;
                for (int i = y; i <= 500000; i += x) {
                    res += a[i];
                }
                cout << res << endl;
            } else {
                cout << dp[x][y] << endl;
            }
        }
    }
    return 0;
}