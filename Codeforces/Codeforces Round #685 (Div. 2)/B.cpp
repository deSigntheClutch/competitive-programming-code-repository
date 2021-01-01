#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int M = 2e5 + 4;

int n, q;
string s;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        cin >> s;
        for (int i = 0; i < q; i++) {
            int l, r; 
            cin >> l >> r;
            l--, r--;
            bool find_l = false;
            for (int j = 0; j < l; j++) {
                if (s[j] == s[l]) {
                    find_l = true;
                }
            }
            bool find_r = false;
            for (int j = r + 1; j < n; j++) {
                if (s[j] == s[r]) {
                    find_r = true;
                }
            }
            if (find_l || find_r) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
