#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int dp[N][N];
int n;
string AA, BB, BA, AB;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> AA >> AB >> BA >> BB;
    dp[0][2] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i + 1; j++) {
            if (dp[i - 1][j] == 0) continue;
            (dp[i][j] += ) % MOD; //AA

             // BB
             // AB
             // BA
        }
    }
    return 0;
}