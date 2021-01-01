#include <bits/stdc++.h>

using namespace std;

#define debug(x, a, b) for(int (ii)=(a);(ii)<(b);(ii++)) printf("%d: %d\n", ii, x[ii]);
#define mp make_pair
#define pb push_back
#define fi first
#define se second 

int n, k, m;
vector<int> num[123456];
int p[123456];
vector<int> G[123456];
bool flag = false;
int start_num = -1;

void construct_graph(int cur, int left, int right) {
  if (cur == m) {
    if (left < right) flag = true;
    return;
  }
  int prev = -1;
  for (int i = left; i <= right; i++) {
    int pt = i, val = num[i][cur];
    while (pt <= right && num[pt][cur] == num[i][cur]) pt++;
    construct_graph(cur + 1, i, pt - 1);
    if (prev != -1) {
      G[prev].push_back(val);
      cout << cur << " " << i << endl;
      cout << prev << "->" << val << endl;
    }
    prev = val;
    i = pt - 1;
  }
}

int deg[123456];
bool used[123456];
bool special;

void topo() {
  for (int i = 0; i < k; i++) {
    for (int v : G[i]) {
      deg[v] += 1;
    }
  }
  
  int done = 0;
  queue<int> q;
  for (int i = 0; i < k; i++) {
    cout << deg[i] << " ";
    if (deg[i] == 0) q.push(i);
  }
  cout << endl;
  while (!q.empty()) {
    int x = q.front();
    if (x == start_num && done == 0) {
      p[x] = 1;
      special = true;
    } else {
      p[x] = done++;
      if (special == true && done == 1) {
        done++;
      }
    }
    q.pop();
    for (int v : G[x]) {
      deg[v]--;
      if (deg[v] == 0) {
        q.push(v);
      }
    }
  }
  if (done != k) flag = true;
}

int main() {
  ios::sync_with_stdio(false);
  memset(p, -1, sizeof p);
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
    for (int v, j = 1; j <= m; j++) {
      cin >> v;
      num[i].push_back(v);
    }
  }
  flag = false;
  start_num = num[0][0];
  construct_graph(0, 0, n - 1);
  topo();
  if (flag == true) cout << -1 << endl;
  else {
    for (int i =0 ; i < k; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
  return 0;
}