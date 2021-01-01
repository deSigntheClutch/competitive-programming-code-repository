#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 16;
const int M = 2e5 + 4;

int sum[M], perm[N], tmp[N];
int n, q;
bool used[N];

int cal(int pl, int l, int r) {
    int len = min(n, 15ll);
    memset(used, 0, sizeof used);
    for (int i = 0; i < len; i++) {
        int id = pl / perm[len - 1 - i], val;
        for (int cnt = 0, i = 1; i <= len; i++) {
            if (used[i] == true) continue;
            if (cnt == id) {
                val = i;
            }
            cnt += 1;
        }
        used[val] = true;
        tmp[i] = val;
        pl = pl % perm[len - 1 - i];
    }
    return accumulate(tmp + l, tmp + r + 1, 0ll);
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    perm[0] = perm[1] = 1;
    for (int i = 2; i < N; i++) {
        perm[i] = perm[i - 1] * i;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + i;
    }
    int cur = 0;
    for (int type, l, r, i = 0; i < q; i++) {
        cin >> type;
        if (type == 2) {
            cin >> l;
            cur += l;
        } else {
            cin >> l >> r;
            if (n <= 15) {
                cout << cal(cur, l - 1, r - 1) << endl;
            } else {
                if (r <= n - 15)
                    cout << sum[r] - sum[l - 1] << endl;
                else if (l <= n - 15) {
                    cout << cal(cur, 0, r + 14 - n) + (r + 15 - n) * (n - 15) + sum[n - 15] - sum[l - 1] << endl;
                } else {
                    cout << cal(cur, l + 14 - n, r + 14 - n) + (r - l + 1) * (n - 15) << endl;
                }
            }
        }
    }
    return 0;
}
