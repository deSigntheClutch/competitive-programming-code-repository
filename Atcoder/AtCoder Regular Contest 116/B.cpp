#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
const int MOD = 998244353;

int n;
int a[N];
int sum[N];
int pw2[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pw2[i] = 2 * pw2[i - 1] % MOD;
    }
    int ans = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        sum[i] = a[i];
        ans = (ans + a[i] * a[i] + a[i] * sum[i - 1]) % MOD; 
        sum[i] = (2 * sum[i - 1] + sum[i]) % MOD;
       // cout << sum[i] << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}