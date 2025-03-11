#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

ll n, k;
ll sum;
ll p2[N];

void cal_layer(ll u, ll depth) {
      if (u < k) return;

      if (u & 1) {
            if (depth == 0)
                  sum += (u + 1) / 2;
            else
                  sum += p2[depth - 1] * (n + 1);
      }
      cal_layer(u / 2, depth + 1);
}




int main() {
      p2[0] = 1, p2[1] = 2;
      for (int i = 2; i < 64; i++) {
            p2[i] = p2[i - 1] * 2ll;
      }

      int T;
      cin >> T;
      while (T--) {
            cin >> n >> k;
            sum = 0;
            cal_layer(n, 0);
            cout << sum << endl;
      }
      return 0;
}