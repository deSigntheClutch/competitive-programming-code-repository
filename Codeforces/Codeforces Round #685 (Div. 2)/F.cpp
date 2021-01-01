#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m;
int a[N][N];
int xorsum[N + N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 2; i <= n + m; i++) {
            xorsum[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                xorsum[i + j] ^= a[i][j];
            }
        }
        bool flag = false;
        for (int i = 2; i <= n + m; i++) {
            flag |= (xorsum[i] != 0);
        }
        if (flag) cout << "Ashish" << endl;
        else cout << "Jeel" << endl;

    }
    return 0;
}
