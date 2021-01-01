#include <bits/stdc++.h>
using namespace std;

const int GAP = 1e4 + 1;
int n, b;

bool check_prime(int x) {
    for (int c = 2; c <= n; c++) {
        if (c * c > x) return true;
        if (x % c == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> b;
    for (int i = b; i >= b - GAP; i--) {
        if (i == n) break;
        if (check_prime(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}