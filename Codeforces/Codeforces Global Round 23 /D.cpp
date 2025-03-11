#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, k;
ll bv[N], s[N];
ll f[2][N];
int sz[N];
vector<int> G[N];
vector<ll> delta, sv[2];

ll cal(int h, int len) {
      for (int i = 0; i < len; i++) {
            delta[i] = (sv[1][i] - sv[0][i]);
      }
      ll ans = accumulate(sv[0].begin(), sv[0].begin() + len, 0ll);

      sort(delta.begin(), delta.begin() + len);

      for (int i = 0; i < h; i++) {
            ans += delta[len - 1 - i];
      }
      return ans;
}

void dfs0(int u, int fa, ll x) {
      bv[u] = x;
      sz[u] = 0;
      for (int v : G[u]) {
            if (fa == v) continue;
            sz[u] += 1;
      }

      for (int v : G[u]) {
            if (fa == v) continue;
            dfs0(v, u, x / sz[u]);
      }
}

void dfs1(int u, int fa) {
      f[0][u] = s[u] * bv[u];
      f[1][u] = s[u] * (bv[u] + 1);

      if (sz[u] == 0) {
            return ;
      }

      for (int v : G[u]) {
            if (fa == v) continue;
            dfs1(v, u);
      }

      // can be 0
      int high = bv[u] - sz[u] * (bv[u] / sz[u]);

      int cnt = 0;
      for (int v : G[u]) {
            if (fa == v) continue;
            sv[0][cnt] = f[0][v];
            sv[1][cnt] = f[1][v];
            cnt += 1;
      }

      f[0][u] += cal(high, sz[u]);
      f[1][u] += cal(high + 1, sz[u]);
}


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