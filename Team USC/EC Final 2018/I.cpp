#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e2 + 2;

ll a[N], b[N], c[N];
ll dp[2][N][N * N];
int n;
ll sumi[N];

void init() {
    for (int i = 1; i <= n; i++) {
        sumi[i] = sumi[i - 1] + i; 
    }
}

inline void relax(ll& t, ll x) {
    if (t < x) t = x;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        init();

        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n * (n + 1) / 2; j++) {
                dp[0][i][j] = -1;
                dp[1][i][j] = -1;
            }
        }
        dp[(n + 1) & 1][0][0] = accumulate(a + 1, a + 1 + n, 0ll);
        ll ans = dp[(n + 1) & 1][0][0];
        for (int i = n; i >= 1; i--) {

            // init
            for (int j = 0; j <= n; j++) {
                for (int s = 0; s <= sumi[n] - sumi[i - 1]; s++) {
                    dp[i & 1][j][s] = -1;
                }
            }

            // iterate old dp
            // num_of_case2/3
            for (int num_op = 0; num_op <= n - i; num_op++) {

                // sum_of_op_index
                for (int sum_of_idx = 0; sum_of_idx <= sumi[n] - sumi[i]; sum_of_idx++) {
                    if (dp[(i & 1) ^ 1][num_op][sum_of_idx] == -1) continue;

                    // nothing
                    relax(dp[i & 1][num_op][sum_of_idx], dp[(i & 1) ^ 1][num_op][sum_of_idx]);
                    relax(ans, dp[i & 1][num_op][sum_of_idx]);

                    // operation / check biggest contribution
                    ll contribution = max((n - i - num_op) * c[i] - a[i], (sumi[n] - sumi[i] - sum_of_idx - (n - i - num_op) * i) * b[i] - a[i]);
                    relax(dp[i & 1][num_op + 1][sum_of_idx + i], dp[(i & 1) ^ 1][num_op][sum_of_idx] + contribution);
                    relax(ans, dp[i & 1][num_op + 1][sum_of_idx + i]);
                }
            }
        }
        cout << ans << endl;
    } 
    return 0;
}

/*


3
2
3 1 2
3 1 2
3
3 1 2
3 1 2
3 1 2

1

5
3 1 2
3 1 2
3 1 2
3 1 2
3 1 2


*/