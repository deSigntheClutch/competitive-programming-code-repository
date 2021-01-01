#include <bits/stdc++.h>
#define int long long

using namespace std;

const long long INF = 9e17 + 6;
const int N = 16;

int a[N], b[N], q[N];
long long f[N][1 << 16];
int n, k;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> q[i];
    }

    for (int mask = 0; mask < (1 << 16); mask++) {
        for (int j = 0; j < N; j++) {
            f[j][mask] = INF;
        }
    }

    f[0][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < k; j++) {
            if (f[j][mask] == INF) continue;
            // new env 
            for (int width = 0; width < n; width++) {
                if ((mask >> width) & 1) continue;
                for (int length = 0; length < n; length++) {
                    if ((mask >> length) & 1) continue;
                    int total_quant = 0;    
                    int new_mask = 0;
                    for (int i = 0; i < n; i++) {
                        if ((mask >> i) & 1) continue;

                        if (a[width] >= a[i] && b[length] >= b[i]) {
                            new_mask |= 1 << i;
                            total_quant += q[i];
                        }
                    }
                    f[j + 1][mask | new_mask] = min(f[j][mask] + (long long)total_quant * a[width] * b[length], f[j + 1][mask | new_mask]);
                }
            }
        }
    }

    long long ans = INF;
    long long constant_sum = 0;
    for (int i = 0; i < n; i++) {
        constant_sum += (long long) a[i] * b[i] * q[i];
    }
    for (int i = 0; i <= k; i++) {
        ans = min(ans, f[i][(1 << n) - 1]);
    }
   // cout << ans << " " << constant_sum << endl;
    cout << ans - constant_sum << endl; 
    return 0;
}