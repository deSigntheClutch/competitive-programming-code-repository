#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 3;
const int INF = 1e15;

string s;
int n, m;
int a[2][N], b[2][N];
int sum[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cin >> s;

        int l = 0, r = 0, val = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '+')
                val += 1, sum[i] = 1;
            else
                val -= 1, sum[i] = -1;
            l = min(l, val);
            r = max(r, val);
            a[0][i] = l, a[1][i] = r;
            sum[i] += sum[i - 1];
        }
        l = 0, r = 0, val = 0;
        b[0][n + 1] = 0, b[1][n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            if (s[i - 1] == '+')
                val += 1;
            else
                val -= 1;
            l = min(l, val);
            r = max(r, val);
            b[0][i] = l, b[1][i] = r;
        }

        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            int xl = a[0][l - 1];
            int xr = a[1][l - 1];
            int yl = sum[l - 1] + (sum[n] - sum[r]) - b[1][r + 1];
            int yr = sum[l - 1] + (sum[n] - sum[r]) - b[0][r + 1];
            //cout << xl << " " << xr << " " << yl << " " << yr << endl;
            if (yl > xr || xl > yr) {
                cout << (xr - xl) + 1 + 1 + (yr - yl) << endl;
            } else {
                cout << max(yr, xr) - min(xl, yl) + 1 << endl;
            }
        }
    }
    return 0;
}