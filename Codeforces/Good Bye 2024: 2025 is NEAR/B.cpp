#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

bool used[N];
int used_cnt[N];
int sum[N];
int l[N], r[N], n;

int main() {
      int T;
      cin >> T;
      while (T--) {

            for (int i = 1; i <= 2 * n; i++) {
                  used[i] = 0;
                  used_cnt[i] = 0;
                  sum[i] = 0;
            }

            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> l[i] >> r[i];
                  if (l[i] == r[i]) {
                        used[l[i]] = 1;
                        used_cnt[l[i]] += 1;
                  }
            }

            for (int i = 1; i <= 2 * n; i++) {
                  sum[i] = sum[i - 1] + used[i];
            }

            for (int i = 1; i <= n; i++) {
                  if (l[i] == r[i]) {
                        //cout << "!" << i << " " << used_cnt[l[i]] << endl;
                        if (used_cnt[l[i]] == 1) {
                              cout << "1";
                        } else {
                              cout << "0";
                        }
                        continue;
                  }

                  int res = sum[r[i]] - sum[l[i] - 1];
                  if (res == r[i] - l[i] + 1) {
                        cout << "0";
                  } else {
                        cout << "1";
                  }
            }

            cout << endl;
      }
      return 0;
}