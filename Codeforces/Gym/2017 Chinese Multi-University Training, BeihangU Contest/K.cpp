#include <bits/stdc++.h>
using namespace std;

long long m, n;

int main() {
    ios::sync_with_stdio(false);
    int cnt = 0;
    while (cin >> m >> n) {
        if (n <= m - 1) cout << "Case #" << ++cnt << ": " << n << endl;
        else {
            n -= m;
            int di = n % (m - 1);
            if (di == 0) {
                cout << "Case #" << ++cnt << ": " << (((n / (m - 1)) & 1) ? m - 1 : m) << endl;
            } else {
                cout << "Case #" << ++cnt << ": " << di << endl;
            }
        }
    }
    return 0;
}