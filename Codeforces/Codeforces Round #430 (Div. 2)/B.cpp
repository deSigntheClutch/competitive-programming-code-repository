#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

ll r, d;
int n;

bool cal(ll x, ll y, ll t) {
    if (t > r) return 0;
    if (x * x + y * y > (r - t) * (r - t)) return 0;
    if (x * x + y * y >= (r - d + t) * (r - d + t)) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> r >> d;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll x, y, ri;
        cin >> x >> y >> ri;
        cnt += cal(x, y, ri);
    }
    cout << cnt << endl;
    return 0;
}

