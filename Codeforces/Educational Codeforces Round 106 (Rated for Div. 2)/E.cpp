#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 5;
const int MOD = 998244353;

int dp[N][N][2];
int f[26][N][2];

int n, m;
string s, t;

bool is_same_char(string& s1, int pos1, string& s2, int pos2) {
    if (pos1 == 0 || pos2 == 0) return false;
    else return s1[pos1 - 1] == s2[pos2 - 1]; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> s >> t;
    n = s.length();
    m = t.length();

    int bound = 1;
    char prev = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == prev) {
            bound = i;
        }
        left_bad_index[i][0] = bound;
        prev = s[i - 1];
    }

    bound = 1, prev = -1;
    for (int i = 1; i <= m; i++) {
        if (t[i - 1] == prev) {
            bound = i;
        }
        left_bad_index[i][1] = bound;
        prev = t[i - 1];
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0][0] = 1;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i][1] = 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][1] = ((!is_same_char(t, j - 1, t, j)) * dp[i][j - 1][1] + (!is_same_char(s, i, t, j)) * dp[i][j - 1][0]) % MOD;
            dp[i][j][0] = ((!is_same_char(s, i, s, i - 1)) * dp[i - 1][j][0] + (!is_same_char(s, i, t, j)) * dp[i - 1][j - 1][1]) % MOD;
            cout << i << " " << j << ": " << dp[i][j][1] + dp[i][j][0] << endl;
            sum = (sum + dp[i][j][1] + dp[i][j][0]) % MOD;
        }
    }

    cout << sum << endl;
    return 0;
}