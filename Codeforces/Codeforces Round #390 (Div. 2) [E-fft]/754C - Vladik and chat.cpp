#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define nono(x, ite) for(__typeof((x).begin()) ite=(x).begin(); ite != (x).end(); ite++)

const int N = 1E2 + 10;

bool F;
bool f[N][N], vis[N];
int from[N][N];
int n, k;
map<string, int> nameSet;
string message[N], nameList[N];
stack<string> stk;

bool isValid(char s) {
  if (s == '!' || s == '?' || s == '.' || s == ',' || s == ' ' || s == ':') return false;
  return true;
}

void proc(int v, string s) {
  memset(vis, 0, sizeof vis);
  int pt = 0;
  int type = (s[0] == '?');
  while (s[pt] != ':') pt++;
  string name = s.substr(0, pt);
  for (int i = pt; i < s.length(); i++) {
    if (!isValid(s[i])) continue;
    int no = i;
    while (no < s.length() && isValid(s[no])) no++;
    string handle = s.substr(i, no - i);
    i = no;
    vis[nameSet[handle]] = 1;
  }
  if (type == 1) {
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      bool flag = false;
      for (int j = 0; j <= n; j++) {
        if (i == j) continue;
        if (f[v - 1][j] == 1) {
          f[v][i] = true;
          from[v][i] = j;
          break;
        }
      }
    }
  } else {
    if (vis[nameSet[name]]) F = false;
        int id = nameSet[name];
    for (int i = 0; i <= n; i++) {
      if (i == id) continue;
      if (f[v - 1][i] == 1) {
        f[v][id] = true;
        from[v][id] = i;
        break;
      }
    }
  }
}

void print(int u, int v) {
  int pt = 0;
  while (message[u][pt] != ':') pt++;
  string s =nameList[v] + message[u].substr(pt, message[u].length() - pt);
  stk.push(s);
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    F = true;
    nameSet.clear();
    for (int i = 1; i <= n; i++) {
      string str;
      cin >> str;
      nameList[i] = str;
      nameSet[str] = i;
    }
    cin >> k;
    string buf;
    getline(cin, buf);
    memset(f, 0, sizeof f);
    memset(from, -1, sizeof from);
    f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
      string str;
      getline(cin, str);
      message[i] = str;
      proc(i, str);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += f[k][i];
    }
    if (sum == 0) F = false;
    if (!F) cout << "Impossible" << endl;
    else {
      int cs = 0;
      for (int i = 1; i <= n; i++) {
        if (f[k][i]) {
          cs = i;
          break;
        }
      }
      for (int j = k; j >= 1; j--) {
        print(j, cs);
        cs = from[j][cs];
      }
      while(!stk.empty()) {
        cout << stk.top() << endl;
        stk.pop();
      }
    }
  }
  return 0;
}
