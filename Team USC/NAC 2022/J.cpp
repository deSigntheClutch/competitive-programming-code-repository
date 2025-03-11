#include <bits/stdc++.h>
using namespace std;

int n;
string S;
map<string, pair<int, int>> f;
map<string, int> used;
vector<pair<string, pair<int, int>>> pr;

int checkWinner(string s) {
      // row
      if (s[0] == s[1] && s[1] == s[2]) {
            if (s[0] == 'X') {
                  return 1;
            }
            else if (s[0] == 'O') {
                  return -1;
            }
      }
      if (s[3] == s[4] && s[4] == s[5]) {
            if (s[3] == 'X') {
                  return 1;
            }
            else if (s[3] == 'O') {
                  return -1;
            }
      }
      if (s[6] == s[7] && s[7] == s[8]) {
            if (s[6] == 'X') {
                  return 1;
            }
            else if (s[6] == 'O') {
                  return -1;
            }
      }

      // --------------- col -----------------
      if (s[0] == s[3] && s[3] == s[6]) {
            if (s[0] == 'X') {
                  return 1;
            }
            else if (s[0] == 'O') {
                  return -1;
            }
      }
      if (s[1] == s[4] && s[4] == s[7]) {
            if (s[1] == 'X') {
                  return 1;
            }
            else if (s[1] == 'O') {
                  return -1;
            }
      }
      if (s[2] == s[5] && s[5] == s[8]) {
            if (s[2] == 'X') {
                  return 1;
            }
            else if (s[2] == 'O') {
                  return -1;
            }
      }
      // diag
      if (s[0] == s[4] && s[4] == s[8]) {
            if (s[0] == 'X') {
                  return 1;
            }
            else if (s[0] == 'O') {
                  return -1;
            }
      }

      if (s[2] == s[4] && s[4] == s[6]) {
            if (s[2] == 'X') {
                  return 1;
            }
            else if (s[2] == 'O') {
                  return -1;
            }
      }
      return 0;
}

void dfs(string cur, bool X_turn) {
      if (used[cur]) {
            return;
      }

      used[cur] = 1;

      int res = checkWinner(cur);

      if (res == 1) {
            f[cur] = {1, 0};
            pr.push_back({cur, {1, 0}});

            return;
      } else if (res == -1) {
            f[cur] = {0, 1};
            pr.push_back({cur, {0, 1}});

            return;
      }

      int xx = 0, oo = 0;

      for (int i = 0; i < 9; i++) {
            if (cur[i] == '.') {
                  if (X_turn) {
                        cur[i] = 'X';
                        dfs(cur, false);
                  } else {
                        cur[i] = 'O';
                        dfs(cur, true);
                  }
                  xx += f[cur].first;
                  oo += f[cur].second;
                  cur[i] = '.';
            }
      }

      f[cur] = {xx, oo};

      pr.push_back({cur, {f[cur].first, f[cur].second}});
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);

      used.clear();
      dfs(".........", true);
      sort(pr.begin(), pr.end());

      cin >> n;

      for (int i = 1; i <= n; i++) {
            cin >> S;

            if (!used[S]) {
                  cout << -1 << " " << -1 << endl;
                  continue;
            }

            cout << f[S].first << " " << f[S].second << endl;
      }
      return 0;
}
