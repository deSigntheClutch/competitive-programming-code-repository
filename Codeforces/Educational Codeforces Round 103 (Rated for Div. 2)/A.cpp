#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (n <= k)
            cout << (k + n - 1) / n << endl;
        else {
            int d = (n + k - 1) / k;
            k *= d;
            cout << (k + n - 1) / n << endl;
        }
    }
    return 0;
}