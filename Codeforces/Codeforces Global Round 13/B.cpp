#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
const int M = 123;

int n, u, v;
int cnt;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> u >> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool flag = true;
        for (int i = 2; i <= n; i++) {
            if (abs(a[i] - a[i - 1]) > 1) {
                flag = false;
            }
        }
        if (!flag) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 2; i <= n; i++) {
            if (abs(a[i] - a[i - 1]) == 1) {
                flag = false;
                cnt = min(u, v);
                break;
            }
        }
        if (!flag) {
            cout << cnt << endl;
            continue;
        }

        cout << min(2 * v, u + v) << endl;
    }
    return 0;
}
