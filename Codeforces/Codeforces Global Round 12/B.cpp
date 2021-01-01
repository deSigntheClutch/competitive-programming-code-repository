#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 123;

int n, k;
pair<int, int> inv[M];
int x[M], y[M];

int man(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

int G[M][M];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            for (int j = 0; j < i; j++) {
                if (man(i, j) <= k) {
                    G[i][j] = G[j][i] = 1;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) cnt += (G[i][j] == 1);
            }
            if (cnt == n - 1) {
                flag = true;
            }
        }
        if (flag == true)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
/*

gg B.cpp && run


*/
