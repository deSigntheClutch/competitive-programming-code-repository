#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, h, H;
int x[N], c[N];
int ans[N];
int mask[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> h >> H;
        for (int i = 0; i <= H; i++) mask[i] = i;
        for (int i = H - 1; i > 0; i--) mask[i] = i;

        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        for (int i = 1; i <= n; i++) {
            int crown_pos = mask[x[i] % (2 * H)];
            if (crown_pos <= h)
                ans[i] = x[i] + c[i];
            else {
                if (x[i] % (2 * H) >= H) {
                    ans[i] = x[i] + (crown_pos - h) + c[i];
                } else {
                    ans[i] = x[i] + (2 * (H - crown_pos) + crown_pos - h) + c[i];
                }
            }
        }

        int res = 1e9 + 10, winner = -1;
        for (int i = 1; i <= n; i++) {
            if (res > ans[i]) {
                res = ans[i];
                winner = i;
            }
        }
        cout << winner << endl;
    }
    return 0;
}