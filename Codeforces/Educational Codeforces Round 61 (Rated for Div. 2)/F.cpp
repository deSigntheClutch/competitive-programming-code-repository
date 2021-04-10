#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

int n;
string s;
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    memset(f, 0x3f, sizeof f);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        f[i][i] = 1;
        if (i >= 2) {
            f[i - 1][i] = (s[i - 2] == s[i - 1]) ? 1 : 2;
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int j = i - 2; j >= 1; j--) {
            f[j][i] = min(f[j][i - 1] + 1, f[j][i]);

            // i == ?
            if (s[i - 1] == s[j - 1]) {
                f[j][i] = min(f[j][i], 1 + f[j + 1][i - 1]);
            }
            for (int k = j + 1; k < i; k++) {
                f[j][i] = min(f[j][i], f[j][k] + f[k + 1][i]);
                f[j][i] = min(f[j][i], f[j][k - 1] + f[k][i]);
                if (s[i - 1] == s[j - 1] && s[i - 1] == s[k - 1]) {
                    f[j][i] = min(f[j][i], f[j][k] + f[k][i] - 1);
                } 
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}