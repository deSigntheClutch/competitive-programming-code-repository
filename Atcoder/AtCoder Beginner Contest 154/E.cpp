#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
string num;
int k;
int res = 0;
int C[123][4];
int dp[123][4];

int dfs(int pos, int left) {
    if (left == 0) return 1;
    if (pos > n) return 0;
    int ss = 0;
    for (int i = 0; i < num[pos - 1] - '0'; i++) {
        if (i == 0) ss += dp[n - pos][left];
        else ss += dp[n - pos][left - 1];
    }
    if (num[pos - 1] > '0') return ss + dfs(pos + 1, left - 1);
    else return ss + dfs(pos + 1, left);
}

signed main() {
    C[0][0] = 1;
    for (int i = 1; i <= 122; i++) {
        C[i][0] = 1;
        C[i][1] = i;
    }
    for (int i = 2; i <= 122; i++) {
        for (int j = 2; j <= min(3ll, i); j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    ios::sync_with_stdio(false);
    cin >> num >> k;
    n = num.length();
    for (int i = 1; i < n; i++) {
        if (i < k) continue;
        res += 9 * C[i - 1][k - 1];
    }
    for (int i = 0; i <= 122; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= 122; i++) {
        dp[i][1] = 9ll * C[i][1];
        if (i >= 2) dp[i][2] = 9ll * 9ll * C[i][2];
        if (i >= 3) dp[i][3] = 9ll * 9ll * 9ll * C[i][3];
    }
    cout << dfs(1, k) << endl;
    return 0;
}