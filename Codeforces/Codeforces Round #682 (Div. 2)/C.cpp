#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int M = 2e2 + 4;

int a[M][M];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if ((i + j) & 1) {
                    if (a[i][j] & 1) a[i][j] += 1;
                } else {
                    if (!(a[i][j] & 1)) a[i][j] += 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
