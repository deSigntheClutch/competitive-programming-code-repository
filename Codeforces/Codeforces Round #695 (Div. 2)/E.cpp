#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int x, n;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
       cin >> n >> x;
       int sa = 0, sb = 0;
       for (int i = 1; i <= n; i++) {
           cin >> a[i];
           sa += a[i];
           sb += (a[i] + x - 1) / x;
       }
       sa = (sa + x - 1) / x;
       cout << sa << " " << sb << endl;
    }
    return 0;
}