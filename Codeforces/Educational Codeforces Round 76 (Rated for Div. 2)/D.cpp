#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m;
int mon[N];
pair<int, int> p[N];
int max_kill[N];

vector<int> val;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        val.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> mon[i];
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> p[i].first >> p[i].second;
            val.push_back(p[i].first);
        }

        sort(val.begin(), val.end());
        vector<int>::iterator len = unique(val.begin(), val.end());
        val.resize(std::distance(val.begin(), len));

        int l = val.size();
        for (int i = l - 1; i >= 0; i--) {
            max_kill[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int id = lower_bound(val.begin(), val.end(), p[i].first) - val.begin();
           // cout << "d" << id << endl;
            max_kill[id] = max(max_kill[id], p[i].second);
        }
        for (int i = l - 2; i >= 0; i--) {
            max_kill[i] = max(max_kill[i], max_kill[i + 1]);
            //cout << "db" << max_kill[i] << endl;
        }
        int start = 0;
        int ans = 0;
        bool flag = true;
        while (start != n) {
            int pt = start;
            int mx = 0;
            //cout << mx << " - " << pt << endl;
            while (lower_bound(val.begin(), val.end(), mx) != val.end() && pt - start <= max_kill[lower_bound(val.begin(), val.end(), mx) - val.begin()]) {
                //cout << max_kill[lower_bound(val.begin(), val.end(), mx) - val.begin()] << " " << pt - start << endl;
                pt += 1;
                if (pt > n) break;
                mx = max(mx, mon[pt]);
            }
            //cout << mx << " + " << pt << endl;
            if (pt - 1 == start) {
                cout << -1 << endl;
                flag = false;
                break;
            }
            start = pt - 1;
            ans += 1;
        }
        if (flag == false) continue;
        cout << ans << endl;
    }
    return 0;
}