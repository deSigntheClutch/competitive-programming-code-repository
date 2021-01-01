#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long a[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long carry = -2e9;
        long long max_diff = 0;
        for (int i = 1; i <= n; i++) {
            carry = max(carry, a[i]);
            max_diff = max(max_diff, carry - a[i]);
        }
        bool flag = false;
        for (int i = 55; i >= 0; i--) {
            if (max_diff >> i & 1) {
                cout << i + 1 << endl;
                flag = true;
                break;
            }
        }
        if (!flag) cout << 0 << endl; 
    }
    return 0;
}