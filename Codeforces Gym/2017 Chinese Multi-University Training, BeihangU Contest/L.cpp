#include "bits/stdc++.h"
using namespace std;

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

pair<int, int> p[N];
vector<int> G[N];
vector<pair<int, int>> _left[N];
int n;

int main() {
    int tcase = 0;
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            G[i].clear(), _left[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> p[i].first;
        }
        for (int i = 1; i <= n; i++) {
            cin >> p[i].second;
        }
        for (int i = 1; i <= n; i++) {
            _left[p[i].first].push_back({p[i].second, i});
        }
        stack<int> S;
        for (int i = 1; i <= n; i++) {
            if (_left[i].size() == 0) continue;
            sort(_left[i].begin(), _left[i].end());
            
        }
        cout << "Case #" << ++tcase << ": " << ans << endl;
    }
    return 0;
}
