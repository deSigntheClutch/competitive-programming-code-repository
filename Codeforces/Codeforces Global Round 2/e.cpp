#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;

int n;
long long a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
    }
    ll carry = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll able = a[i] / 2;
        ll used = min(carry, a[i] / 2);
        
        carry -= used;
        ans += used;
        a[i] -= used * 2;

        carry += a[i] % 3;
        ans += a[i] / 3;
    }
    cout << ans << endl;
    return 0;
}