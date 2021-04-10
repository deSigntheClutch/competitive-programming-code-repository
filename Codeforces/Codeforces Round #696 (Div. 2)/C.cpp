#include <bits/stdc++.h>
using namespace std;
#define int long long

int d;
int n, a[12345];
bool used[2235];
set<pair<int, int>> s;

void solve() {
    sort(a + 1, a + 1 + n);
    for (int st = n - 1; st >= 1; st--) {
        int start = a[n] + a[st];
        int x = a[n];
        memset(used, 0, sizeof used);
        used[n] = true;
        used[st] = true;
        s.clear();
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            s.insert({a[i], i});
        }
        bool yes = false;
        vector<pair<int, int>> ans;
        ans.push_back({a[n], a[st]});
        for (int j = n; j >= 1; j--) {
            if (used[j]) continue;
            used[j] = true;
            s.erase({a[j], j});
            int val = x - a[j];
            //cout << j << " " << a[j] << " val " << val << endl;
            auto tmp = s.lower_bound({val, -1});
            if (tmp == s.end() || (*tmp).first != val) {
                yes = true;
                break;
            }
            used[(*tmp).second] = true;
            ans.push_back({a[j], (*tmp).first});
            s.erase(tmp);
            x = a[j];
        }
        if (!yes) {
            cout << "YES" << endl;
            cout << start << endl;
            for (auto pp : ans) {
                cout << pp.first << " " << pp.second << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        n *= 2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        solve();
    }
    return 0;
}