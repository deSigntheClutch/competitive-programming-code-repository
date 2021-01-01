#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

const int N = 220;
const int B = 42701;

int n;
int a[N], b[N];
int dp[2][102][2 * N * N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        b[i] *= 2;
        a[i] *= 2;
    }
    memset(dp, -1, sizeof dp);
    dp[0][0][0 + B] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= n; k++) {
            for (int empty = -(i - 1) * (N - 1); empty <= (i - 1) * (N - 1); empty++) {
                if (dp[(i + 1) % 2][k][empty + B] == -1) continue;
                dp[i % 2][k][empty + B] = max(dp[i % 2][k][empty + B], dp[(i + 1) % 2][k][empty + B]);
                // as answer
                if (empty >= 0) {
                    dp[i % 2][k + 1][empty + a[i] - b[i] + B] =
                        max(dp[i % 2][k + 1][empty + a[i] - b[i] + B], dp[(i + 1) % 2][k][empty + B] + b[i]);
                } else {
                    dp[i % 2][k + 1][empty + a[i] - b[i] + B] =
                        max(dp[i % 2][k + 1][empty + a[i] - b[i] + B],
                            dp[(i + 1) % 2][k][empty + B] + min(a[i] - b[i], -empty) + b[i]);
                }
                // pour into some cups
                if (empty >= b[i] / 2)
                    dp[i % 2][k][empty - b[i] / 2 + B] =
                        max(dp[i % 2][k][empty - b[i] / 2 + B], dp[(i + 1) % 2][k][empty + B] + b[i] / 2);
                else if (empty >= 0)
                    dp[i % 2][k][empty - b[i] / 2 + B] =
                        max(dp[i % 2][k][empty - b[i] / 2 + B], dp[(i + 1) % 2][k][empty + B] + empty);
                else
                    dp[i % 2][k][empty - b[i] / 2 + B] =
                        max(dp[i % 2][k][empty - b[i] / 2 + B], dp[(i + 1) % 2][k][empty + B]);
            }
        }
//        for (int k = 0; k <= n; k++) {
//            for (int empty = -1000; empty <= 1000; empty++) {
//                if (dp[i % 2][k][empty + B] != -1) {
//                    cout << empty << " " << k << ": ";
//                    cout << dp[i % 2][k][empty + B] << endl;
//                }
//            }
//            cout << endl;
//        }
//        cout << "---" << endl;
    }
    for (int k = 1; k <= n; k++) {
        int ans = -1;
        for (int e = 0; e < 2 * N * N; e++) {
            ans = max(ans, dp[n % 2][k][e]);
        }
        cout << fixed << setprecision(14) << ans * 0.5 << " ";
    }
    cout << endl;
    return 0;
}