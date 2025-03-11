#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 1e18;

int n;
long long a[N], b[N];
long long pref[N];
int T;

pair<long long, long long> get_pair(int li, int ri) {
      if (li > ri) return make_pair(0, 0);

      long long min0 = INF, min_cur = 0;
      long long max0 = -INF, max_cur = 0;

      for (int i = li; i <= ri; i++) {
            min_cur = min(min_cur + a[i], a[i]);
            min0 = min(min_cur, min0);
      }

      for (int i = li; i <= ri; i++) {
            max_cur = max(max_cur + a[i], a[i]);
            max0 = max(max_cur, max0);
      }
      return make_pair(min0, max0);
}


int main() {
      cin >> T;
      while (T--) {
            set<long long> s;
            s.insert(0);
            cin >> n;

            int target = 0;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  pref[i] = pref[i - 1] + a[i];
                  if (a[i] != -1 && a[i] != 1)
                        target = i;
            }

            pair<long long, long long> l1 = get_pair(1, target - 1);
            pair<long long, long long> r1 = get_pair(target + 1, n);

           //cout << l1.first << " l1 " << l1.second << endl;
            for (int i = l1.first; i <= l1.second; i++) {
                  s.insert(i);
            }
            //cout << r1.first << " r1 " << r1.second << endl;

            for (int i = r1.first; i <= r1.second; i++) {
                  s.insert(i);
            }

            pair<long long, long long> left_val = make_pair(0, 0);
            pair<long long, long long> right_val = make_pair(0, 0);

            for (int i = target - 1; i >= 0; i--) {
                  long long val = pref[target] - pref[i] - a[target];
                  if (val < left_val.first) {
                        left_val.first = val;
                  }
                  if (val > left_val.second) {
                        left_val.second = val;
                  }
            }

            for (int i = target + 1; i <= n; i++) {
                  long long val = pref[i] - pref[target];
                  if (val < right_val.first) {
                        right_val.first = val;
                  }
                  if (val > right_val.second) {
                        right_val.second = val;
                  }
            }

            long long L = min(right_val.first, min(left_val.first, left_val.first + right_val.first));
            long long R = max(right_val.second, max(left_val.second, left_val.second + right_val.second));


            // cout << L << " LR1: " << R << endl;
            L += a[target];
            R += a[target];

            // cout << L << " LR2: " << R << endl;



            //cout << length_one << " 1 and -1 " << length_minus_one << endl;

            for (int i = L; i <= R; i++) {
                  s.insert(i);
            }

            cout << s.size() << endl;
            for (auto x : s) {
                  cout << x << " ";
            }
            cout << endl;
      }
      return 0;
}
