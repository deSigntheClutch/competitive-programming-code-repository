#include "bits/stdc++.h"
using namespace std;

const int N = 1e3 + 3;

int n, m;
string a[N], b[N];
bool used[N][N];

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            used[i][j] = (a[i][j] == 'X');
            cnt += (a[i][j] == 'X');
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        for (int j = 0; j < m; j++) {
            if (b[i][j] == '.') continue;
            if (used[i][j])
                x++;
            else
                y++;
        }
    }

    if (cnt - x + y <= m * n / 2) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ((a[i][j] == '.') ? 'X' : '.');
            }
            cout << endl;
        }
    }
    return 0;
}