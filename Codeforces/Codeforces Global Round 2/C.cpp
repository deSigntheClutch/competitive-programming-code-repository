#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
int a[N][N];
int b[N][N];
int row1[N], col1[N], row2[N], col2[N];

void prove() {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 1) {
                a[i][j] = 0;
                a[i][m] ^= 1;
                a[n][m] ^= 1;
                a[n][j] ^= 1;
            }
            if (b[i][j] == 1) {
                b[i][j] = 0;
                b[i][m] ^= 1;
                b[n][m] ^= 1;
                b[n][j] ^= 1;
            }
        }
    }
    bool real = true;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] != b[i][j]) real = false;
    if (real) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    if (n == 1 || m == 1) {
        bool res = true;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] != b[i][j]) res = false;
        if (res) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    prove();
    return 0;
}