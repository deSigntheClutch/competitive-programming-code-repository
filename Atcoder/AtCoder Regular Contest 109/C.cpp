#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <set>
#define int long long
using namespace std;

const int N = 200;

int n, k;
string s;
char dp[N][N]; // i, j, 2^i game, start from j

int powMod(int u, int v, int mod) {
    int res = 1;
    while (v) {
        if (v & 1) res = res * u % mod;
        v >>= 1;
        u = u * u % mod;
    }
    return res;
}

char winner(char a, char b) {
    if ((a == 'S' && b == 'R' ) || (a == 'R' && b == 'S'))
        return 'R';
    else if ((a == 'S' && b == 'P' ) || (a == 'P' && b == 'S'))
        return 'S';
    else if ((a == 'P' && b == 'R' ) || (a == 'R' && b == 'P'))
        return 'P';
    else if (a == b) return a;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        dp[0][i] = s[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            int next = (j + powMod(2, i - 1, n)) % n;
            dp[i][j] = winner(dp[i - 1][j], dp[i - 1][next]);
        }
    }
    cout << dp[k][0] << endl;
    return 0;
}