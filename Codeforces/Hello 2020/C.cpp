#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
typedef long long ll;

ll fact[N], m;
int n;
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = (long long)fact[i - 1] * i % m;
    }
    ll ans = 0;
    if (n == 1) {
        cout << 1 << endl; return 0;
    }
    for (int i = 1; i <= n; i++) {
        ll num = (long long)(n + 1 - i) * (n + 1 - i) % m;
        ll val = num * fact[i] % m;
        val = val * fact[n - i] % m; 
        ans = (ans + val) % m;
    }
    cout << ans << endl;
    return 0;
}