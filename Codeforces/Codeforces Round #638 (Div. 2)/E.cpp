#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[511][511];
int n, k;
int a[511], b[511];

signed main() {
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i] + b[i];
    }
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int base = 0; base < k; base++) {
            if (f[i - 1][base] == -1) continue;
            for (int j = 0; j < min(k, a[i]); j++) {
                int final_state = (base + j) % k;
                int yes = (a[i] + b[i] - j) / k;
                if (yes == 0) continue;
                f[i][final_state] = max(f[i][final_state], f[i - 1][base] + (a[i] + b[i] - j) / k + (base + j >= k));
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        cout << f[n][i] << endl;
        if (f[n][i] == -1) continue;
        ans = max(ans, f[n][i] + (sum - f[n][i] * k - i) / k);
    }
    cout << ans << endl;
    return 0;
}