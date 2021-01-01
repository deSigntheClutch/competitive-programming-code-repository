#include <bits/stdc++.h>
using namespace std;
#define find nvjoadnuadobg

const int N = 1E6 + 1;

int n, m;
string s[N];
string ans[N];
vector<int> dp1[N], dp2[N], dp[N];
//1 -
//2 |

bool find(int x, int y, int length) {

}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i - 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (j == m - 1) {
                dp1[i][j] = (s[i][j] == 'X');
                continue;
            }
            if (s[i][j] == '.') dp1[i][j] = 0;
            else dp1[i][j] = dp1[i][j + 1] + 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (j == n - 1) {
                dp2[j][i] = (s[j][i] == 'X');
                continue;
            }
            if (s[j][i] == '.') dp2[j][i] = 0;
            else dp2[j][i] = dp2[j + 1][i] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1) {
                dp[i][j] = (s[i][j] == 'X');
                continue;
            }
            if (j == m - 1) {
                dp[i][j] = (s[i][j] == 'X');
                continue;
            }
            dp[i][j] = min(dp[i+1][j+1]+1, min(dp1[i][j], dp2[i][j]));
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (find(1, 2) == true) {

            }
        }
    }
    return 0;
}

/*

3
10 20 10
6
3 3
*/