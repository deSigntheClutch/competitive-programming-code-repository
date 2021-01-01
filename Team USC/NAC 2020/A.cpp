#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 4;
const int MOD = 998244353;

int miu[N];
bool flag[N];
int p[N], tot;
int n, k;

void getMiu() {
    miu[1] = 1;
    for (int i = 2; i <= k; ++i) {
        if (!flag[i]) p[++tot] = i, miu[i] = -1;
        for (int j = 1; j <= tot && i * p[j] <= k; ++j) {
            flag[i * p[j]] = 1;
            if (i % p[j] == 0) {
                miu[i * p[j]] = 0;
                break;
            }
            miu[i * p[j]] = -miu[i];
        }
    } 
}

int powMod(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = (long long)res * u % MOD;
        v >>= 1;
        u = (long long)u * u % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    getMiu();
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        ans = (ans + miu[i] * (powMod(k / i * 2 + 1, n) - 1)) % MOD;
        if (ans < 0) ans = (ans + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}