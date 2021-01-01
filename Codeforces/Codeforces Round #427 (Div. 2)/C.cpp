#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 3;

int n, q, c;
int sum[12][N][N];
int a[12][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q >> c;
    c += 1;
    for (int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        for (int i = 0; i < c; i++) {
            a[i][x][y] += (s + i) % c;
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                sum[i][j][k] = sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i][j - 1][k - 1] + a[i][j][k];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int t, x1, x2, y1, y2;
        cin >> t;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        t = t % c;
        cout << sum[t][x2][y2] - sum[t][x1 - 1][y2] - sum[t][x2][y1 - 1] + sum[t][x1 - 1][y1 - 1] << endl;
    }
    return 0;
}