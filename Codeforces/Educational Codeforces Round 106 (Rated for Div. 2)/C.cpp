#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 5;
const int INF = 2e9 + 9;

int n;
int c[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        int la = 1, lb = 1;
        int sa = c[0], sb = c[1];
        int ma = c[0], mb = c[1];
        int ans = n * (ma + mb);

        for (int i = 2; i < n; i++) {
            if (i & 1) {
                lb += 1;
                sb += c[i];
                mb = min(mb, c[i]);
            } else {
                la += 1;
                sa += c[i];
                ma = min(ma, c[i]);
            }
            //cout << ma << " " << la << " " << mb << " " << lb << sa << " " << sb << endl;
            ans = min(ans, sa + (n - la) * ma + sb + (n - lb) * mb);
        }
        cout << ans << endl;
    }
    return 0;
}