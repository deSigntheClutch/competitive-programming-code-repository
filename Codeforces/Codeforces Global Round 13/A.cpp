#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
const int M = 123;

int n, q;
int cnt;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt += (a[i] == 1);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == 2) {
            if (y <= cnt) cout << 1 << endl;
            else cout << 0 << endl;
        } else {
            if (a[y] == 0) a[y] = 1, cnt += 1;
            else a[y] = 0, cnt -= 1;
        }
    }
    return 0;
}

