#include <bits/stdc++.h>
using namespace std;

const int N = 300;
const int MSK = 1 << 22;

int dp[MSK];
int cnt[N][N];
int n, m;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
        char a = s[i], b = s[i + 1];
        if (a > b) swap(a, b);
        cnt[a][b] += 1;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        for (int i = 0; i < m; i++) {
            if (!(mask >> i & 1)) {
                int sum = 0;
                for (int j = 0; j < m; j++) {
                    if (j == i) continue;
                    int a = j + 'a', b = i + 'a';
                    if (a > b) swap(a, b);
                    sum += (2 * (mask >> j & 1) - 1) * cnt[a][b] * __builtin_popcount(mask);
                }
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + sum);
            }
        }
    }
    cout << dp[(1 << m) - 1] << endl;
    return 0;
}