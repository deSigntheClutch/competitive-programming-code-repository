#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e2 + 5;

int n;
int a[N][N];
int num1[N];

int cal(vector<int> x) {
      sort(x.begin(), x.end());
      for (int i = 1; i < x.size(); i++) {
            if (x[i] > x[i - 1] && x[i] - x[i - 1] > 1) {
                  x[i] = x[i - 1] + 1;
            }
      }

      set<int> s;

      for (auto y : x) s.insert(y);

      int res = 0;
      while (true) {
            if (s.find(res) == s.end()) {
                  return res;
            } else {
                  res += 1;
            }
      }
}


int main() {
      int T; cin >> T; while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= n; j++) {
                        cin >> a[i][j];
                  }
                  int cnt = 0;
                  for (int j = n; j >= 1; j--) {
                        if (a[i][j] == 1) cnt += 1;
                        else break;
                  }
                  num1[i] = cnt;
            }
            int ans = 1;
            for (int i = 1; i <= n; i++) {
                  vector<int> x;
                  for (int j = 1; j <= n; j++) {
                        if (i == j) {
                              x.push_back(0);
                        } else {
                              x.push_back(num1[j]);
                        }
                  }
                  ans = max(ans, cal(x));
            }

            cout << ans << endl;
      }
      return 0;
}
