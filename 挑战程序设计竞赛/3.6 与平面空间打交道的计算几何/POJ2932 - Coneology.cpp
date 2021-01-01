#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>

using namespace std;

#define fi first
#define se second
#define mp make_pair

const int N = 50000 + 10;
int n;
pair<pair<double, double>, double> p[N];
vector<pair<double, int> > Event;
set<pair<double, int> > s;
vector<int> ans;

bool inside(int u, int v) {
  double dx = p[u].fi.fi - p[v].fi.fi;
  double dy = p[v].fi.se - p[u].fi.se;
  return sqrt(dx * dx + dy * dy) <= p[v].se + p[u].se;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lf %lf %lf", &p[i].se, &p[i].fi.fi, &p[i].fi.se);
    Event.push_back(mp(p[i].fi.fi - p[i].se , i));
    Event.push_back(mp(p[i].fi.fi + p[i].se , -i));
  }
  sort(Event.begin(), Event.end());

  for(int i = 0; i < Event.size(); i++) {
    if(Event[i].se > 0) {
      set<pair<double, int> >::iterator it1;
      it1 = s.lower_bound(mp(p[Event[i].se].fi.se, Event[i].se));
      if(it1 != s.end() && inside(Event[i].se, it1->se)) continue;
      if(it1 != s.begin() && inside(Event[i].se, (--it1)->se)) continue;
      ans.push_back(Event[i].se);
      s.insert(mp(p[Event[i].se].fi.se, Event[i].se));
    } else {
      s.erase(mp(p[-Event[i].se].fi.se, -Event[i].se));
    }
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
  }
  return 0;
}
