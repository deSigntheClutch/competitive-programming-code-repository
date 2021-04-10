#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e2 + 3;

int a[N];
int ans[N * N], len;
int pos[N * N];
int n, k;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        len = 1;
        for (int i = 0; i <= 200 * n; i++) {
            pos[i] = ans[i] = 0;
        }
        while (true) {
            int inc = 0;
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i + 1]) {
                    inc = 1;
                    ans[len] = ans[len - 1] + inc;
                    pos[len] = i;
                    a[i] += 1;
                    len += 1;
                    break;
                } 
            }
            if (inc == 0) break;
        }

        int res = -1;
        //cout << len << endl;
        for (int i = 1; i < len; i++) {
           //cout << ans[i] << " " << pos[i] << endl;
            if (ans[i] >= k) {
                res = pos[i];
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}