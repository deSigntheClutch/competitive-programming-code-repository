#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
       int a, b;
       cin >> a >> b;
       if (2 * a >= 1 + b) cout << "YES" << endl;
       else cout << "NO" << endl;
    }
    return 0;
}
