#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
int a[N], b[N];

int main() {
      int T; cin >> T; while (T--) {
            cin >> n;
            map<int, int> used1, used2;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  if (!used1[a[i]]) {
                        cnt1 += 1;
                        used1[a[i]] = 1;
                  }
            }
            for (int i = 1; i <= n; i++) {
                  cin >> b[i];
                  if (!used2[b[i]]) {
                        cnt2 += 1;
                        used2[b[i]] = 1;
                  }
            }

            if (cnt1 + cnt2 > 3) cout << "yes" << endl;
            else cout << "no" << endl;
      }
      return 0;
}
