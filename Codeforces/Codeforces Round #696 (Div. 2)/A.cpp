#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
string s;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (prev == 1) {
                if (s[i] == '0') {
                    cout << '0';
                    prev = 0;
                } else {
                    cout << '1';
                    prev = 2;
                }
            } else if (prev == 2) {
                if (s[i] == '0') {
                    cout << '1';
                    prev = 1;

                } else {
                    cout << '0';
                    prev = 1;
                }
            } else {
                if (s[i] == '0') {
                    cout << '1';
                    prev = 1;

                } else {
                    cout << '1';
                    prev = 2;
                }
            }
        }
        cout << endl;
    }
    return 0;
}