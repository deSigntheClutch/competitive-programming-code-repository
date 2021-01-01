#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 55;
const int B = 27;
const int INF = 1e9 + 5;

int dp[N][M][M];
string a, b, c;
int pi[2][M];
int n, m, d;

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    n = a.length();
    m = b.length();
    d = c.length();

    pi[0][0] = pi[1][0] = -1;
    int tmp = -1;
    for (int i = 1; i <= m; i++) {
        while (tmp >= 0 && b[tmp + 1 - 1] != b[i - 1]) tmp = pi[0][tmp];
        pi[0][i] = ++tmp;
    }
    tmp = -1;
    for (int i = 1; i <= d; i++) {
        while (tmp >= 0 && c[tmp + 1 - 1] != c[i - 1]) tmp = pi[1][tmp];
        pi[1][i] = ++tmp;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= d; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b.length(); j++) {
            for (int k = 0; k < c.length(); k++) {
                if (dp[i][j][k] == -INF) continue;
                for (int z = 'a'; z <= 'z'; z++) {
                    if (a[i] != '*' && (char)z != a[i]) continue;

                    int val = 0;
                    int ptr_b = j;
                    while (ptr_b >= 0 && b[ptr_b + 1 - 1] != (char)z) ptr_b = pi[0][ptr_b];
                    ptr_b++;
                    if (ptr_b == b.length()) {
                        val += 1;
                        ptr_b = pi[0][ptr_b];
                    }

                    int ptr_c = k;
                    while (ptr_c >= 0 && c[ptr_c + 1 - 1] != (char)z) ptr_c = pi[1][ptr_c];
                    ptr_c++;
                    if (ptr_c == c.length()) {
                        val -= 1;
                        ptr_c = pi[1][ptr_c];
                    }
                    
                    dp[i + 1][ptr_b][ptr_c] = max(dp[i + 1][ptr_b][ptr_c], dp[i][j][k] + val);
                }
            }
        }
    }
    int ans = -INF;
    for (int j = 0; j < b.length(); j++) {
        for (int k = 0; k < c.length(); k++) {
            ans = max(ans, dp[n][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}
