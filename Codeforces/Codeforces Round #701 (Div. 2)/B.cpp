#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 5;

int n, q, k;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
        cin >> n >> q >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= q; i++) {
            int l, r;
            cin >> l >> r;
            cout << k - 1 + a[r] - a[l] - (r - l) * 2<< endl;
        }
    
}