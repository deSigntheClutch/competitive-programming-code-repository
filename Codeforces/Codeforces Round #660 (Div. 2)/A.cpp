#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, x;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n < 31) cout << "NO" << endl;
        else {
            int tmp = n - 6 - 10;
            if (tmp - 14 == 6 || tmp - 14 == 10 || tmp - 14 == 14) {
                cout << "YES" << endl;
                cout << "6 10 15 " << tmp - 15 << endl;
            }
            else {
                cout << "YES" << endl;
                cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << endl;
            }
        }
    }
    return 0;
}