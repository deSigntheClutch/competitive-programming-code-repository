#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int MOD = 1e9 + 7;

int n, x, p;
int a[1234]; // -1 = <, 1 = >
int C[1234][1234];
int A[1234];

signed main() {
    ios::sync_with_stdio(false);
    A[0] = 1;
    for (int i = 1; i <= 1233; i++) {
        A[i] = A[i - 1] * i % MOD;
    }
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 1; i <= 1233; i++){
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                C[i][0] = 1;
                continue;
            }
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    cin >> n >> x >> p;
    int l = 0, r = n, md;
    while (l < r) {
        md = (l + r) >> 1;
        if (md <= p) {
            a[md] = -1;
            l = md + 1;
        } else {
            a[md] = 1;
            r = md;
        }
    }
    int cnt_less = 0, cnt_more = 0;
    for (int i = 0; i < n; i++) {
        //cout << a[i] << " ";
        cnt_less += (a[i] == -1 && i != p);
        cnt_more += (a[i] == 1);
    }
    //cout << endl;
    int less = x - 1;
    int more = n - x;

    int ans = C[less][cnt_less] * A[cnt_less] % MOD;
    ans = ans * A[cnt_more] % MOD * C[more][cnt_more] % MOD;
    ans = ans * A[n - 1 - cnt_less - cnt_more] % MOD;
    cout << ans << endl;
    return 0;
}
