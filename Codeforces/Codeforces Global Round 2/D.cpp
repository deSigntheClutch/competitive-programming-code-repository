#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n, q;
ll s[N];
ll diff[N], sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s+1, s+1+n);
    for (int i = 1; i < n; i++) {
        diff[i] = s[i + 1] - s[i];
    }
    sort(diff+1, diff+n);
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + diff[i];
    }
    cin >> q;
    ll res = s[n] - s[1] + 1;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll len = b - a + 1;
        ll ans = res + len - 1;

        int l = 1, r = n, md;
        for (int xx = 0; xx < 20; xx++) {
            md = (l + r) >> 1;
            if(diff[md] <= len && md < n) l = md + 1;
            else r = md;
        }
        //cout << "a" << md << endl;
        //cout << ans << " " << (sum[n - 1] - sum[md - 1]) << endl;
        cout << ans - (sum[n - 1] - sum[md - 1]) + len * (n - md) << endl;
    }
    return 0;
}
