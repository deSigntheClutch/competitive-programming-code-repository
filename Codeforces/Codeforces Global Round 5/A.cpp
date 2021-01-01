#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    int flag = 0;
    for (int i = 1; i <= T; i++) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            cout << val / 2 << endl;
        } else {
            if (!flag) cout << (int)ceil(val * 0.5) << endl;
            else cout << (int)floor(val * 0.5) << endl;
            flag ^= 1;
        }
    }
    return 0;
}