#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3 + 6;

int n;
string a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            if (a[0][i] == '1') {
                for (int j = 0; j < n; j++) {
                    a[j][i] = ((a[j][i] - '0') ^ 1) + '0';
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (a[i][0] == '1') {
                for (int j = 0; j < n; j++) {
                    a[i][j] = ((a[i][j] - '0') ^ 1) + '0';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (b[0][i] == '1') {
                for (int j = 0; j < n; j++) {
                    b[j][i] = ((b[j][i] - '0') ^ 1) + '0';
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (b[i][0] == '1') {
                for (int j = 0; j < n; j++) {
                    b[i][j] = ((b[i][j] - '0') ^ 1) + '0';
                }
            }
        }
        bool flag = false;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (a[i][j] != b[i][j]) {
                    flag = true;
                }
            }
        }
        cout << (flag ? "no" : "yes") << endl;
    }
    return 0;
}