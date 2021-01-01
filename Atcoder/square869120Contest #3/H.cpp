#include <bits/stdc++.h>
using namespace std;

int a[111][111];

void solve(int lx, int rx, int ly, int ry, int tot) {
    if (lx > rx || ly > ry) return;
    if (lx == rx && ly == ry) {
        a[lx][ly] = tot;
        return;
    }
    int midx = (lx + rx) >> 1;
    int midy = (ly + ry) >> 1;
    int sum = 0, ans;

    cout << "? " << lx << " " << ly << " " << midx << " " << midy << endl;
    cin >> ans;
    sum += ans;
    if (ans != 0) solve(lx, midx, ly, midy, ans);
    // if (sum == tot) return ;

    cout << "? " << lx << " " << midy + 1 << " " << midx << " " << ry << endl;
    cin >> ans;
    sum += ans;
    if (ans != 0) solve(lx, midx, midy + 1, ry, ans);
    // if (sum == tot) return ;

    cout << "? " << midx + 1 << " " << ly << " " << rx << " " << midy << endl;
    cin >> ans;
    sum += ans;
    if (ans != 0) solve(midx + 1, rx, ly, midy, ans);
    // if (sum == tot) return ;
    cout << "? " << midx + 1 << " " << midy + 1 << " " << rx << " " << ry << endl;
    cin >> ans;
    if (ans != 0) solve(midx + 1, rx, midy + 1, ry, ans);
}

int main() {
    ios::sync_with_stdio(false);
    int h, w, n, k;
    cin >> h >> w >> n >> k;
    solve(0, h - 1, 0, w - 1, n);
    int pw2 = 1, ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans = (ans + (long long)pw2 * a[i][j] % k) % k;
            pw2 = pw2 * 2 % k;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}
