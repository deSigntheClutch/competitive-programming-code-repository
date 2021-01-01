#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int M = 2e5 + 4;

int n;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 1) cout << 0 << endl;
        else if (n == 2) cout << 1 << endl;
        else if (n == 3) cout << 2 << endl;
        else {
            if (n & 1) cout << 3 << endl;
            else cout << 2 << endl;
        }

    }
    return 0;
}
