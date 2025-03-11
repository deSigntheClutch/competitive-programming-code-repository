#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;

const int N = 1e3 + 4;

int n;
pii p[N];

pii ask(ll x, ll y) {
      cout << x << " " << y << endl;
      fflush(stdout);

      ll r, s;
      cin >> r >> s;
      return make_pair(r, s);
}

pii beauty(pair<ll, ll> x) {
      ll gcd = std::gcd(x.first, x.second);
      return make_pair(x.first / gcd, x.second / gcd);
}

void add_area(pii &s, pii a, pii b, pii x0, pii x1) {
      pii delta_x = beauty(make_pair(x1.first * x0.second - x0.first * x1.second, x0.second * x1.second));

      pii tmp_sum = beauty(make_pair(a.first * b.second + a.second * b.first, a.second * b.second));

      pii tmp_area = beauty(make_pair(delta_x.first * tmp_sum.first, delta_x.second * tmp_sum.second * 2));

      s = beauty(make_pair(s.first * tmp_area.second + s.second * tmp_area.first, tmp_area.second * s.second));
}

int main() {
      int T;
      cin >> T;

      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> p[i].first >> p[i].second;
            }

            sort(p + 1, p + 1 + n);

            pii area = make_pair(0, 1);
            pii prev_len = make_pair(0, 1); // line length
            pii prev_x = make_pair(p[0].first, 1);

            for (int i = 1; i <= n; i++) {
                  int pt = i;
                  while (pt <= n && p[pt].first == p[i].first) pt += 1;


                  // i - pt - 1
                  if (pt - i == 1) {
                        if (i == 1) {
                              continue;
                        } else if (i == n) {
                              add_area(area, make_pair(0, 1), prev_len, prev_x, p[i]);
                        } else {
                              pii res = ask(p[i].first, 1);

                              add_area(area, res, prev_len, prev_x, p[i]);

                              prev_len = res;
                              prev_x = make_pair(p[i].first, 1);
                        }
                  } else {
                        if (i == 1) {
                              pii res = ask(p[i].first, 1);

                              prev_len = res;
                              prev_x = make_pair(p[i].first, 1);
                        } else if (i == n) {
                              pii res = ask(p[i].first, 1);

                        } else {
                              pii res = ask(p[i].first, 1);

                              add_area(area, res, prev_len, prev_x, p[i]);

                              prev_len = res;
                              prev_x = make_pair(p[i].first, 1);
                        }
                  }
                  i = pt - 1;
            }


      }
}