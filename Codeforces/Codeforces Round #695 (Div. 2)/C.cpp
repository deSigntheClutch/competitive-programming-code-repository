#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;
const int INF = 1e18;

int n[3];
int a[3][N];
int sum[3];
int min_val[3];

signed main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; i++) {
        cin >> n[i];
        min_val[i] = INF;
        sum[i] = 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
            min_val[i] = min(min_val[i], a[i][j]);
        }
    }

    int ans = -INF;

    for (int i = 0; i < 3; i++) {
        ans = max(ans, sum[1] + sum[0] + sum[2] - 2 * sum[i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            ans = max(ans, sum[1] + sum[0] + sum[2] - 2 * min_val[i] - 2 * min_val[j]);
        }
    }

    cout << ans << endl;
    return 0;
}