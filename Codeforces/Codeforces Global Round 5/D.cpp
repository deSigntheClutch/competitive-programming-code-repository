#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <memory>
#include <set>
#include <utility>
#include <vector>

using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int INF = 1e9 + 9;
const int N = 3e5 + 5;

int T;
int n;
int a[N];
int dp[N];
set<int> s;

int t[N << 2];

void push_up(int rt) { t[rt] = min(t[rt << 1], t[rt << 1 | 1]); }

int query(int rt, int left, int right, int l, int r) {
    if (l == left && r == right) {
        return t[rt];
    }
    if (mid >= r) {
        return query(lson, l, r);
    } else if (mid < l) {
        return query(rson, l, r);
    } else {
        return min(query(lson, l, mid), query(rson, mid + 1, r));
    }
}

void update(int rt, int left, int right, int id, int val) {
    if (id == left && left == right) {
        t[rt] = val;
        return;
    }
    if (mid >= id)
        update(lson, id, val);
    else
        update(rson, id, val);
    push_up(rt);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector<pair<int, int>> event, change;
    memset(t, 0x3f, sizeof t);
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_value = max(max_value, a[i]);
        a[n + i] = a[i];
        a[2 * n + i] = a[i];
    }
    n = 3 * n;
    for (int i = 0; i < n; i++) {
        if (2 * a[i] < max_value) {
            change.push_back({-a[i], i});
            s.insert(i);
        }
        event.push_back({-a[i], i});
    }
    sort(event.begin(), event.end());
    sort(change.begin(), change.end());
    int ptr = 0;
    for (int i = 0; i < event.size(); i++) {
        int val = -event[i].first;
        int pos = event[i].second;
        while (ptr < change.size() && -2 * change[ptr].first >= val) {
            s.erase(change[ptr].second);
            ptr += 1;
        }
        if (s.lower_bound(pos) == s.end())
            dp[pos] = INF;
        else
            dp[pos] = *s.lower_bound(pos);
    }
    for (int i = n - 2; i >= 0; i--) {
        int bound = dp[i];
        if (dp[i] == INF) bound = n;

        int min_dp = query(1, 1, n, i + 1, bound);
        dp[i] = min(dp[i], min_dp);
        update(1, 1, n, i + 1, dp[i]);
    }
    for (int i = 0; i < n / 3; i++) {
        if (dp[i] == INF)
            cout << -1 << " ";
        else
            cout << dp[i] - i << " ";
    }
    cout << endl;
    return 0;
}