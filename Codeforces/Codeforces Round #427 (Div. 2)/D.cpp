#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e3 + 3;
const int BASE = 47;
const int MOD = 1e9 + 7;

string s;

int n;
int _hash[N], _revhash[N];
int dp[N][N];
int ans[N];
int inv[N];

int pow_mod(int x, int t) {
    int res = 1;
    while (t) {
        if (t & 1) res = res * x % MOD;
        x = x * x % MOD;
        t >>= 1;
    }
    return res;
}

int get_hash(int l, int r) {
   // cout << _hash[r] << " " <<  _hash[l - 1] << " " << inv[l - 1] << endl;
    return (_hash[r] - _hash[l - 1] + MOD) * inv[l - 1] % MOD;
}

int rev_get_hash(int l, int r) {
   // cout << _revhash[l] << " " <<  _revhash[r + 1] << " " << inv[n - r] << endl;
    return (_revhash[l] - _revhash[r + 1] + MOD) * inv[n - r] % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();

    int v = pow_mod(BASE, MOD - 2);

    inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        inv[i] = inv[i - 1] * v % MOD;
    }

    int base = 1;
    for (int i = 1; i <= n; i++) {
        _hash[i] = (_hash[i - 1] + base * (s[i - 1] - 'a')) % MOD;
        base = base * BASE % MOD;
    }
    base = 1;

    for (int i = n; i >= 1; i--) {
        _revhash[i] = (_revhash[i + 1] + base * (s[i - 1] - 'a')) % MOD;
        base = base * BASE % MOD;
    }
    // cout << get_hash(1, 8) << endl;
    // cout << rev_get_hash(9, 16) << endl;

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int left_hash = get_hash(l, l + len / 2 - 1);
            int right_hash = rev_get_hash(l + len - len / 2, l + len - 1);
            // if (l == 2 && len == 3) {
            //     cout << left_hash << " " << right_hash << " | " << l << " " <<  l + len / 2 - 1 << " | " << l + len - len / 2 << " " << l + len - 1 << endl;
            // }
            if (left_hash != right_hash) dp[l][l + len - 1] = 0;
            else dp[l][len + l - 1] = min(dp[l][l + len / 2 - 1], dp[l + len - len / 2][l + len - 1]) + 1;
            // if (dp[l][len + l - 1] > 1) {
            //     cout << l << " " << len + l - 1 << endl;
            // }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans[dp[i][j]] += 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        ans[i - 1] += ans[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}