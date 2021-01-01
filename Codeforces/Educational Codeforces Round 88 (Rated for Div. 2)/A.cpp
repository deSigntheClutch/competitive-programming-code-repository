#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        int p = n / k;
        if (p <= m) {
            cout << p - (int)ceil(1.0 * (m - p) / (k - 1)) << endl;
        } else {
            cout << m << endl;
        }
    }
    return 0;
}
