#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 4;

int n, m;
string g[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> g[i];
        }

        // case 1 
        bool flag = false;
        int x = -1, y = -1, z = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j] == g[j][i]) {
                    flag = true;
                    x = i, y = j;
                }
            }
        }

        if (flag) {
            cout << "YES" << endl;
            for (int t, i = 0; i < m + 1; i++) {
                t = (i & 1 ? x : y);
                cout << t + 1 <<  " ";
            } 
            cout << endl;
            continue;
        }

        if (m & 1) {
            cout << "YES" << endl;
            for (int t, i = 0; i < m + 1; i++) {
                t = i & 1 ? 1 : 2;
                cout << t << " ";
            }
            cout << endl;
            continue;
        }

        if (n == 2) {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            x = -1, y = -1, z = -1;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (g[i][j] == 'a') {
                    x = j;
                } else {
                    y = j;
                }
            }
            if (x != -1 && y != -1) {
                flag = true;
                z = i;
                break;
            }
        }

        // case 2
        if (flag) {
            cout << "YES" << endl;
            int half = m / 2;
            if (half & 1) {
                cout << x + 1 << " ";
                for (int t, i = 0; i < half; i++) {
                    t = (i & 1 ? x : z);
                    cout << t + 1 << " ";
                }
                for (int t, i = 0; i < half; i++) {
                    t = (i & 1 ? z : y);
                    cout << t + 1 << " ";
                }
            } else {
                cout << z + 1 << " ";
                for (int t, i = 0; i < half; i++) {
                    t = (i & 1 ? z : x);
                    cout << t + 1 << " ";
                }
                for (int t, i = 0; i < half; i++) {
                    t = (i & 1 ? z : y);
                    cout << t + 1 << " ";
                }
            }
            cout << endl;
            continue;
        }

        cout << "NO" << endl;
    }
    return 0;
}