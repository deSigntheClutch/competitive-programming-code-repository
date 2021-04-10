#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;
int w[N], h[N];
int val[2 * N], l;
pair<pair<int, int>, int> p[N];
int ans[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        l = 0;
        set<pair<int, int>> s;

        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> h[i];
            if (w[i] > h[i]) swap(w[i], h[i]);
            val[l++] = w[i];
            val[l++] = h[i];
        }
        sort(val, val + l);
        l = unique(val, val + l) - val;

        for (int i = 1; i <= n; i++) {
            w[i] = lower_bound(val, val + l, w[i]) - val + 1;
            h[i] = lower_bound(val, val + l, h[i]) - val + 1;
            p[i] = {{w[i], h[i]}, i};
        }
        sort(p + 1, p + 1 + n);
        for (int i = 1; i <= n; i++) {
            int pt = i;
            while (pt <= n && p[i].first.first == p[pt].first.first) pt += 1;
            for (int j = i; j < pt; j++) {
                auto x = s.lower_bound({p[j].first.second, -1});
                if (x == s.begin()) ans[p[j].second] = -1;
                else {
                    x--;
                    ans[p[j].second] = (*x).second;
                }
            }
            for (int j = i; j < pt; j++) {
                //cout << p[j].first.first << " " << p[j].first.second << " " <<  p[j].second << endl;
                s.insert({p[j].first.second, p[j].second});
            }
            //cout  << endl;
            i = pt - 1;
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}