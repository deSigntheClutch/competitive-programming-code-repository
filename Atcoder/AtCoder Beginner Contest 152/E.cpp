#include <bits/stdc++.h>
using namespace std;

#define int long long

const double pi = acos(-1.0);
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int prime[N], prime_id[N], len;
bool isnp[N];
int n, a[N], b[N], cnt[N];

int powMod(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = res * u % MOD;
        v >>= 1;
        u = u * u % MOD;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    for (int i = 2; i < N; i++) {
        if (isnp[i] == true) continue;
        prime[len++] = i;
        prime_id[i] = len - 1;
        for (int j = 2 * i; j < N; j += i) {
            isnp[j] = true;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        a[i] = b[i];
        for (int j = 0; prime[j] * prime[j] <= b[i]; j++) {
            int total = 0;
            while (a[i] % prime[j] == 0) {
                a[i] /= prime[j];
                total += 1;
            }
            cnt[j] = max(cnt[j], total);
        }
        //cout << a[i] << " " << prime_id[a[i]] << endl;
        if (a[i] > 1) cnt[prime_id[a[i]]] = max(cnt[prime_id[a[i]]], 1ll);
    }
    int pre = 1;
    for (int i = 0; i < len; i++) {
        // if (cnt[i] > 0) {
        //     cout << prime[i] << " " << cnt[i] << endl;
        // }
        pre = pre * powMod(prime[i], cnt[i]) % MOD;
    }
    //cout << pre << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + pre * powMod(b[i], MOD - 2)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
