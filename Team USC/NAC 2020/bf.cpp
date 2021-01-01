#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 4;
const int MOD = 998244353;

int miu[N];
bool flag[N];
int p[N], tot;
int n, k;
int f[N];
vector<int> divisor[N];

void getMiu() {
    miu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!flag[i]) p[++tot] = i, miu[i] = -1;
        for (int j = 1; j <= tot && i * p[j] <= n; ++j) {
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

int gcd(int u, int v) {
    return v == 0? u : gcd(v, u % v); 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int cnt = 0;
    for (int i = -k; i <= k; i++) {
        for (int j = -k; j <= k; j++) {
            if (!(gcd(i, j) == 1 || gcd(i, j) == -1)) cout << i << " " << j << " " << gcd(i, j) << endl;
            cnt += (gcd(i, j) == 1 || gcd(i, j) == -1 || gcd(i, j) == 0);
        }
    }
    cout << cnt << endl;
    return 0;
}