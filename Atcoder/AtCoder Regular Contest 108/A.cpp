#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
signed main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            if (i + m / i == n) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}