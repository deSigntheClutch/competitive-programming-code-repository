#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, k;
double sum[N];
double p[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i] * (1 + p[i]) / 2 / p[i];
    }
    double maximum = -1;
    for (int i = 1; i + k - 1 <= n; i++) {
        maximum = max(maximum, sum[i + k - 1] - sum[i - 1]);
    }
    cout << fixed << setprecision(12) << 1.0 * maximum << endl;
    return 0;
}