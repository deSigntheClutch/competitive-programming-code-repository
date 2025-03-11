#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const int INF = 1e9;

int T, n, q;
int L[N], R[N];
int ans[N];


void solve(vector<pair<int, int>> events) {
      multiset<int> s;
      for (int i = 0; i < events.size(); i++) {
            if (events[i].second < 0) {
                  int pt = i;

                  while (pt < events.size() && events[pt].first == events[i].first && events[pt].second < 0) {
                       // cout << "inset" << R[abs(events[pt].second)] << endl;
                        s.insert(R[abs(events[pt].second)]);
                        pt += 1;
                  }

                  for (int j = i; j < pt; j++) {
                        auto p = events[j];
                        s.erase(s.lower_bound(R[abs(p.second)]));
                        auto left_R = s.lower_bound(R[abs(p.second)]);

                       // cout << j << "  "<< *left_R << " " << p.first << " " << p.second << endl;
                        if (left_R != s.end()) {
                              //cout << "!!" << R[abs(p.second)] << endl;
                              if (*left_R >= R[abs(p.second)]) {
                                    ans[abs(p.second)] += *left_R - R[abs(p.second)];
                              }
                        }
                        s.insert(R[abs(p.second)]);
                  }
                  i = pt - 1;
            } else {
                  s.erase(R[abs(events[i].second)]);
            }
      }
}


int main() {
      cin >> T;
      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  ans[i] = 0;
                  cin >> L[i] >> R[i];
            }


            vector<pair<int, int>> eventL, eventR;

            for (int i = 1; i <= n; i++) {
                  eventL.push_back(make_pair(L[i], -i));
                  eventL.push_back(make_pair(R[i], +i));
                  eventR.push_back(make_pair(INF - L[i], +i));
                  eventR.push_back(make_pair(INF - R[i], -i));
            }

            sort(eventL.begin(), eventL.end());

            sort(eventR.begin(), eventR.end());

            solve(eventL);

            for (int i = 1; i <= n; i++) {
                  int l = L[i], r = R[i];
                  L[i] = INF - r;
                  R[i] = INF - l;
            }
            solve(eventR);

            for (int i = 1; i <= n; i++) cout << ans[i] << endl;

      }
}
