#include <bits/stdc++.h>
using namespace std;
#define int long long

// 1:41pm

int n, l;
int a[123456];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] + a[i + 1] >= l) {
            cout << "Possible" << endl;
            for (int j = 1; j < i; j++) {
                cout << j << endl;
            }
            for (int j = n - 1; j >= i + 1; j--) {
                cout << j << endl;
            }
            cout << i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}