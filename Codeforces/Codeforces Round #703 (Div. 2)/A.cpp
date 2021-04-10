#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;

int T;
int n, m;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        bool flag = true;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] + cur < i) flag = false;
            cur += a[i] - i;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}