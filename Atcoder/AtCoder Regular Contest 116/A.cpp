#include <bits/stdc++.h>
using namespace std;
#define int long long

int x;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> x;
        if (x % 2 == 0 && x % 4 != 0) {
            cout << "Same" << endl;
        } else if (x & 1) {
            cout << "Odd" << endl;
        } else {
            cout << "Even" << endl;
        }
    }
    return 0;
}