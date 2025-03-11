#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 4;
const long long INF = 1e18 + 1;

int n, m, k;
int T;

void print(multiset<int> s) {
      for (auto x : s) {
            cout << (x) << " ";
      }
      cout << endl;
}

int main() {
      cin >> T;
      while (T--) {
            cin >> n >> k;
            multiset<int> s;

            s.insert(n);
            int cnt = 0;

            while (s.size() != n) {
                  auto x = s.upper_bound(1);
                  if (x == s.end() || *x == 1) break;
                  cout << "DSA=" << *x << endl;

                  int q = (*x) / k, p = (*x) % k;
                  cout << q << " " << p << " " << (*x) << " " << k << endl;
                  for (int i = 0; i < p; i++) {
                        s.insert(q + 1);
                  }

                  for (int i = 0; i < k - p; i++) {
                        if (q) s.insert(q);
                  }

                  s.erase(*x);
                  cnt += 1;
                  print(s);
            }
            cout << cnt << endl;
      }
      return 0;
}
