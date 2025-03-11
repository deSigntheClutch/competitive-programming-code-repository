#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, k;


int main() {
      int T; cin >> T;

      while (T--) {
            cin >> n >> k;
            delta.clear();
            sv[0].clear();
            sv[1].clear();

            for (int p, i = 2; i <= n; i++) {
                  cin >> p;
                  G[p].push_back(i);
            }

            for (int i = 1; i <= n; i++) {
                  cin >> s[i];
                  delta.push_back(0);
                  sv[0].push_back(0);
                  sv[1].push_back(0);
            }
            dfs0(1, -1, k);

            dfs1(1, -1);

//            for (int i = 1; i <= n; i++) {
//                  cout << f[0][i] << " " << f[1][i] << endl;
//            }
            cout << f[0][1] << endl;

            for (int i = 1; i <= n; i++) G[i].clear();
      }

      return 0;
}