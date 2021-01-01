//  g++ -std=c++14 E.cpp -o e && ./e
#include <bits/stdc++.h>
using namespace std;

#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right

const int N = 2e5 + 2;
const int INF = 1e9 + 10;

pair<int, int> intv[N];
int n, m;
int max_in[N << 1], cnt[N << 1], pa[N];
vector<pair<int, int>> one_segment[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= 2 * n; i++) max_in[i] = cnt[i] = 0;
        for (int i = 0; i <= n; i++) one_segment[i].clear();
        vector<int> val;
        for (int i = 1; i <= n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            intv[i] = {t1, t2};
            val.push_back(t1), val.push_back(t2);
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        vector<pair<int, int>> event;
        for (int i = 1; i <= n; i++) {
            intv[i].first = lower_bound(val.begin(), val.end(), intv[i].first) - val.begin() + 1;
            intv[i].second = lower_bound(val.begin(), val.end(), intv[i].second) - val.begin() + 1;
            event.push_back({intv[i].first, -i});
            event.push_back({intv[i].second, i});
        }
        m = val.size();
        sort(event.begin(), event.end());
        set<int> s;
        int pre = -1, id = -1;
        bool is_connected = false;
        int total_ans = 0;
        int pt = 0;
        for (int i = 1; i <= m; i++) {
            vector<pair<int, int>> in_event, out_event;
            while (pt < event.size() && i == event[pt].first ) {
                if (event[pt].second < 0) in_event.push_back(event[pt]);
                else out_event.push_back(event[pt]);
                pt += 1;
            }
            for (auto p : in_event) s.insert(abs(p.second));
            if (s.size() != 1 && pre != -1) one_segment[id].push_back({pre, i}), pre = -1, id = -1;
            if (s.size() == 1 && pre == -1) pre = i, id = *s.begin();
            max_in[i] = s.size();
            for (auto p : out_event) s.erase(abs(p.second));
            if (s.size() != 1 && pre != -1) one_segment[id].push_back({pre, i}), pre = -1, id = -1;
            if (s.size() == 1 && pre == -1) pre = i, id = *s.begin();

            if (s.size() == 1) cnt[i] = *s.begin();
            else if (s.size() > 1) cnt[i] = -1;
            else cnt[i] = 0;

            if (max_in[i] >= 0 && !is_connected) is_connected = true;
            if (max_in[i] == 0 && is_connected) is_connected = false, total_ans += 1;
            //cout << cnt[i] << " ";
        }
        if (is_connected) total_ans += 1;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int cur = 0;
            for (auto e : one_segment[i]) {
                int l = e.first, r = e.second;
                //cout << l << " " << r << endl;
                if (max_in[l] > 1 && max_in[r] > 1) cur += 1;
            }
            //cout << endl;
            ans = max(ans, total_ans + cur);
            //cout << total_ans + cur << endl;
        }
        cout << ans << endl;
    }
    return 0;
}

/*

10000
4
2 4
3 7
4 5
1 6

3
4
1 4
2 3
3 6
5 7
3
5 5
5 5
5 5
6
3 3
1 1
5 5
1 5
2 2
4 4

*/