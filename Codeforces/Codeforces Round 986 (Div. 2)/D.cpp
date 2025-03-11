#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const char* mask = new char[3]{'q', 'k', 'j'};

int n;
int a[3][N], rk[3][N];

struct State {
      int p[3];
      int c;
      bool operator<(const State& other) const {
            for (int i = 0; i < 3; ++i) {
                  if (p[i] != other.p[i]) {
                        return p[i] < other.p[i]; // Compare arrays element by element
                  }
            }
            return c < other.c; // Compare the `c` member if arrays are equal
      }
};

map<int, bool> used;
pair<int, int> previ[N];

int main() {

      int T; cin >> T;

      while (T--) {
            used.clear();
            cin >> n;
            for (int x = 0; x < 3; x++) {
                  for (int i = 1; i <= n; i++) {
                        cin >> a[x][i];
                        rk[x][a[x][i]] = i;
                        previ[i] = {0, 0};
                  }
            }

            bool flag = false;
            int who = -1;

            queue<State> q;

            q.push({{0, 0, 0}, 1});

            while (!q.empty()) {
                  State s = q.front();
                  //cout << s.p[0] << " " << s.p[1] << " " << s.p[2] << " " << s.c << endl;

                  q.pop();

                  for (int i = 0; i < 3; i++) {
                        int x = a[i][s.c];

                        if (s.p[i] < x) {
                              for (int j = s.p[i] + 1; j <= x; j++) {
                                    State t = s;
                                    t.p[i] = j;
                                    t.c = rk[i][j];
                                    if (t.c > s.c && !used[t.c]) {
                                          if (t.c == n) {
                                                flag = true;
                                                who = i;
                                          }

                                          used[t.c] = true;
                                          previ[t.c] = {i, s.c};
                                          q.push(t);
                                    }
                              }
                        }
                  }
            }

            if (flag) {
                  cout << "yes" << endl;

                  vector<pair<int, int>> res;
                  int tmp = n;
                  res.push_back({who, tmp});
                  tmp = previ[tmp].second;
                  while(tmp != 1) {
                        res.push_back({previ[tmp].first, tmp});
                        tmp = previ[tmp].second;
                  }

                  reverse(res.begin(), res.end());

                  cout << res.size() << endl;
                  for (auto x : res) {
                        cout << mask[x.first] << ' ' << x.second << endl;
                  }
            }
            else cout << "no" << endl;
      }
      return 0;
}