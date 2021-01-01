#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define nono(x, ite) for(__typeof((x).begin()) ite=(x).begin(); ite != (x).end(); ite++)

typedef long long ll;

const int N = 3e5 + 10;

int n, k;
pair<pair<int, int>, int> p[N];
set<pair<int, int>> s;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].fi.fi >> p[i].fi.se;
    p[i].se = i;
  }
  sort(p + 1, p + 1 + n);
  int mx = 0, when = -1;
  for (int i = 1; i <= n; i++) {
    s.insert(mp(p[i].fi.se, p[i].se));
    if (s.size() > k) s.erase(s.begin());
    if (i >= k) {
      if (mx < max(0, (*s.begin()).fi - p[i].fi.fi + 1)) {
        when = i;
        mx = max(0, (*s.begin()).fi - p[i].fi.fi + 1);
      }
    }
  }
  cout << mx << endl;
  s.clear();
  for (int i = 1; i <= max(k, when); i++) {
    s.insert(mp(p[i].fi.se, p[i].se));
    if (s.size() > k) s.erase(s.begin());
  }
  nono(s, ite) {
    cout << ite->se << " ";
  }
  cout << endl;
  return 0;
}
