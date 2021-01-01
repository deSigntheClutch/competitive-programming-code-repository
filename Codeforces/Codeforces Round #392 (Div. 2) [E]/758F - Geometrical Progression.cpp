#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 9E18 + 10;

ll ans, n, l, r;

ll pow(ll u, ll v) {
  ll res = 1;
  while (v) {
    if (v & 1) res = res * u;
    if (INF / u <= u) return INF;
    u *= u;
    v >>= 1;
  }
  return res;
}

int main() {
  cin >> n >> l >> r;
  if (n == 1) cout << r - l + 1 << endl;
  else if (n == 2) cout << (r - l + 1) * (r - l) << endl;
  else {
    ll b = (ll)sqrt(1.0 * r) + 10;
    for (ll i = 1; i <= b; i++) {
      for (ll j = i + 1; j <= b; j++) {
        if (__gcd(i, j) == 1) {
          ll u = pow(i, n - 1), v = pow(j, n - 1);
          ll b1 = (ll)floor(1.0 * r / v), b2 = (ll)ceil(1.0 * l / u);
          if (b2 > b1 || v > r || u > r) continue;
          ans += b1 - b2 + 1;
        }
      }
    }
    cout << ans * 2 << endl;
  }
  return 0;
}

