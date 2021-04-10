#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 5e2 + 5;

int n, m;
int a[N][N];
int b[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] = 720720;
            if ((i + j) & 1) {
                b[i][j] += a[i][j] * a[i][j] * a[i][j] * a[i][j];
            }
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

}