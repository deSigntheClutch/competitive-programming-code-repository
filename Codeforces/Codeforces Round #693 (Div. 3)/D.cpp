#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int alice = 0, bob = 0;
        int first = 0;
        for (int i = n; i >= 1; i--) {
            if (first == 0) {
                if (a[i] % 2 == 0) alice += a[i];
            } else {
                if (a[i] % 2 == 1) bob += a[i];
            }
            first ^= 1;
        }
        if (alice > bob) cout << "Alice" << endl;
        else if (alice == bob) cout << "Tie" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}