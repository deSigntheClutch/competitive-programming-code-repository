#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n, m, max_val = -N * 2;
int mxid[N], mnid[N];
int a[N];

int left_max;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    memset(mxid, 0, sizeof mxid);
    memset(mnid, 0x3f, sizeof mnid);

    int r = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
        mxid[a[i]] = max(mxid[a[i]], i);
        mnid[a[i]] = min(mnid[a[i]], i);
    }
    long long ans = 0;
    int cur_min = N;
    stack<pair<int, int>> q;
    for (int tmp = m; tmp >= 1; tmp--) {
        if (mnid[tmp] == 0) {
            q.push({cur_min, tmp});
            continue;
        }
        if (cur_min >= N)
            cur_min = mnid[tmp];
        else {
            if (mxid[tmp] > cur_min) {
                r = tmp;
                break;
            } else {
                cur_min = min(cur_min, mnid[tmp]);
            }
        }
        q.push({cur_min, tmp});
    }
    //cout << r << endl;
    left_max = 0;
    for (int l = 1; l <= m; l++) {
        while (q.size() > 0 && (r < l || left_max >= q.top().first)) {
            q.pop();
            r++;
        }
        //cout << l << " " << r << endl;
        ans += m - r + 1;
        if (left_max < mnid[l]) {
            left_max = max(left_max, mxid[l]);
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}