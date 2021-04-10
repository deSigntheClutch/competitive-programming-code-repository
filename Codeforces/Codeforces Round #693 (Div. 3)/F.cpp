#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, m;
pair<int, int> p[N];
map<int, int> mp;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        mp.clear();
        int cnt[2] = {0, 0};
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            p[i] = {y, x};
            cnt[(x + y) % 2] += 1;
            mp[y] |= x;
        }
        if (m & 1) {
            cout << "NO" << endl;
            continue;
        } else if (cnt[0] != cnt[1]) {
            cout << "NO" << endl;
            continue;
        }

        bool flag = false;
        int from_which = 0;
        int start_x = -1;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int left = 3 ^ it->second;

            if (from_which != 0) {
                if (it->first % 2 == start_x % 2) {
                    if (left != (3 ^ from_which)) {
                        flag = true;
                    }
                    else {
                        from_which = 0;
                        start_x = -1;
                    }
                } else {
                    if (left != from_which) {
                        flag = true;
                    } else {
                        from_which = 0;
                        start_x = -1;
                    }
                }
            } else {
                if (left == 0) {
                    from_which = 0;
                    start_x = -1;
                } else {
                    from_which = left;
                    start_x = it->first;
                }
            }
        }
        if (!flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}