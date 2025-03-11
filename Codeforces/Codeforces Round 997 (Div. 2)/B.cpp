#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

vector<int> G[N];

int n;
int deg[N];

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n;
            fill(deg, deg + 1 + n, 0);
            for (int i = 1; i <= n; i++) {
                  G[i].clear();
                  string s;
                  cin >> s;
                  for (int j = i + 1; j <= n; j++) {
                        char c = s[j - 1];

                        if (c == '1') {
                              G[i].push_back(j);
                              deg[j] += 1;
                        }
                  }
            }

            priority_queue<int> Q;
            for (int i = 1; i <= n; i++) {
                  if (!deg[i]) Q.push(i);
            }

            while (!Q.empty()) {
                  int x = Q.top();
                  Q.pop();
                  cout << x << " ";

                  for (int v : G[x]) {
                        deg[v]--;
                        if (!deg[v]) {
                              Q.push(v);
                        }
                  }
            }

            cout << endl;
      }
      return 0;
}