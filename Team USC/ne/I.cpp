#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 5;

int n;
int dis[N][N];

signed main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        int cnt = 0;
        int mn = 1e6 + 10;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dis[i][j];
                if (i != j)
                    mn = min(mn, dis[i][j]);
            }
        }
        //cout << mn << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt += (mn == dis[i][j]);
            }
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}