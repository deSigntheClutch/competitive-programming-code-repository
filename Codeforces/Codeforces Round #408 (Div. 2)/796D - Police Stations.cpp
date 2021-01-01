#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

vector<pair<int, int>> G[N];
int p[N], vis[N], n, k, d;
set<int> s;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> d;
  queue<pair<int, int>> Q;
  for (int i = 1; i <= k; i++) {
    cin >> p[i];
    Q.push(make_pair(p[i], 0));
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(make_pair(v, i + 1));
    G[v].push_back(make_pair(u, i + 1));
  }
  while (!Q.empty()) {
    pair<int, int> u = Q.front();
    Q.pop();
    if(vis[u.first]) continue;
    vis[u.first] = 1;
    for (pair<int, int> v : G[u.first]) {
      if (v.first != u.second) {
        if (vis[v.first]) s.insert(v.second + 1);
        else Q.push(make_pair(v.first, u.first));
      }
    }
  }
  cout << s.size() << endl;
  for (int x : s) cout << x << " ";
  cout << endl;
  return 0;
}
