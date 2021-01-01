#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 4e5 + 5;

int sum[N], total_sum[N];
int x;
int d[N];
int n;

bool check(int v) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += max(0ll, d[i] - v + 1);
    }
    return cnt > x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> x;
    int max_day = 1;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    n = n * 2 - 1;
    
    sum[n + 1] = 1e18;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        // one
        int l = i, r = n + 1, md;
        for (int cs = 0; cs < 22; cs++) {
            md = (l + r) >> 1;
            if (sum[md] - sum[l] > x) r = md;
            else l = md + 1;
        }
        l--;
        int cur = d[i];
        cur += total_sum[l] - total_sum[i];
        if (l < n) {
            if (x - (sum[l] - sum[i] + 1) > 0) {
                int len = x - (sum[l] - sum[i] + 1);
                cur += (len + 1) * len / 2;
            }
            if (d[i] == 1) continue;
        }
        // two
    }
    // sort(d + 1, d + 1 + n);
    // int l = 1, r = max_day + 1, md;
    // for (int i = 0; i < 60; i++) {
    //     md = (l + r) >> 1;
    //     if (check(md) == true) l = md + 1;
    //     else r = md;
    // }
    // cout << l << endl;
    // int cnt = 0;
    // for (int i = 1; i <= n; i++) {
    //     cnt += max(0ll, (l + d[i]) * (d[i] - l + 1) / 2); 
    //     x -= (d[i] - l + 1);
    // }
    // cout << cnt + x * (l - 1) << endl;
    return 0;
}
