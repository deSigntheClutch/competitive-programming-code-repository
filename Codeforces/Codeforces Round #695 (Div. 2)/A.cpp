#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int digit = 8;
        cout << 9;
        if (n == 1) {
            cout << endl;
            continue;
        }
        for (int i = 2; i <= n; i++) {
            cout << digit;
            digit += 1;
            if (digit == 10) digit = 0;
        }
        cout << endl;
    }
    return 0;
}