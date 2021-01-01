#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

const int N = 1e3 + 10;

int n;
int c[5], t[5];
char place[N];
pair<int, char> p[N];

int main() {
   freopen("B-small-attempt1.in", "r", stdin);
   freopen("B-small-attempt1.out", "w", stdout);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    memset(place, 0, sizeof place);
    cout << "Case #" << cs << ": ";
    cin >> n;
    for (int i = 1; i <= 3; i++) {
      cin >> c[i] >> t[i];
      if (i == 1) p[i] = make_pair(c[i], 'R');
      else if (i == 2) p[i] = make_pair(c[i], 'Y');
      else p[i] = make_pair(c[i], 'B');
    }
    sort(p + 1, p + 1 + 3);
    int cnt = 0;
    for (int i = 0; i < n - 1; i += 2) {
      p[3].fi--;
      place[i] = p[3].se;
      if (p[3].fi == 0) {
        cnt = i;
        break;
      }
    }
    if (p[3].fi > 0) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    int pm = 0;
    for (int i = cnt + 1; i < n; i++) {
      pm++;
      if (pm & 1) p[2].fi--, place[i] = p[2].se;
      else p[1].fi--, place[i] = p[1].se;
    }
    for (int i = 0; i < n; i++) {
      if (place[i] != 'B' && place[i] != 'Y' && place[i] != 'R') {
        if (p[2].fi > 0) place[i] = p[2].se, p[2].fi--;
        else p[1].fi--, place[i] = p[1].se;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << place[i];
    }
    cout << endl;
  }
  return 0;
}

