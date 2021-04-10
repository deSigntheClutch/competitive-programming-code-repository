#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n, greater<int>());
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                flag = true;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] <= a[i + 1]) {
                flag = true;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}