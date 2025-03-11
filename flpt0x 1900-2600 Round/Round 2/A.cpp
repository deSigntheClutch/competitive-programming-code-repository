#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
vector<int> p;
map<int, int> pos;

void print(vector<int> x) {
      for (int y : x) cout << y << " ";
      cout << endl;
}

bool check(vector<int> x, vector<int> y) {
      for (int i = 1; i < (1 << n) - 1; i++) {
            ll s1 = 0, s2 = 0;
            for (int j = 0; j < n; j++) {
                  if ((i >> j) & 1) {
                        s1 += y[j];
                        s2 += x[j];
                  }
            }
            if (s1 == s2) return false;
      }
      return true;
}



int main() {
      cin >> n;

      vector<int> a(n);
      p = vector<int>(n);

      for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i] = a[i];
            pos[a[i]] = i;
      }

      if (n == 1) {
            cout << a[0] << endl;
            return 0;
      }

      sort(a.begin(), a.end());

      for (int i = 1; i < n; i++) {
            vector<int> b(n);

            for (int j = 0; j < n; j++) {
                  b[j] = a[(j - i + n) % n];
            }

            if (check(b, a)) {
                  vector<int> ans(n);
                  for (int j = 0; j < n; j++) {
                        ans[pos[a[j]]] = b[j];
                  }
                  print(ans);
                  return 0;
            }
      }

      cout << -1 << endl;
      return 0;
}
