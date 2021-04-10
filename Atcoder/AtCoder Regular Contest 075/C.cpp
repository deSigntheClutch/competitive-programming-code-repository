#include <bits/stdc++.h>
using namespace std;

int n;
int dp[123][12345];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    dp[0][0] = 1;
    for (int i=  1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < 12345; j++) {
            dp[i][j] |= dp[i - 1][j];
        }
        for (int j = t; j < 12345; j++) {
            if (dp[i - 1][j - t] == 1) {
                dp[i][j] = 1;
            }
        }
    }
    for (int i= 12344; i >=0; i--) {
        if(dp[n][i] && i % 10 != 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}