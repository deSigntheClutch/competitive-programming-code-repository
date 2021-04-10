#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 5;

int n;
string s;
int f[2][N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.length();

        for (int i = 1; i <= n; i++) {
            f[0][i] = (i >= 2 && s[i - 1] == s[i - 2] && s[i - 1] == '1') ? 1 : 0;
            f[0][i] |= f[0][i - 1];
        }

        for (int i = n; i >= 1; i--) {
            f[1][i] = (i <= n - 1 && s[i - 1] == s[i] && s[i - 1] == '0') ? 1 : 0;
            f[1][i] |= f[1][i + 1];
        }

        bool flag = f[1][1] ^ 1;

        for (int i = 1; i <= n; i++) {
            flag |= (f[0][i] | f[1][i + 1]) ^ 1;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}