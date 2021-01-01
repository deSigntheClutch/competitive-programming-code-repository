#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

ll l, r, x, y, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> l >> r >> x >> y >> k;
    for(ll i = x; i <= y; i++) {
        ll t = i * k;
        if(t >= l && t <= r) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
