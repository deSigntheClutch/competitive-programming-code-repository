#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;
const int MOD = 998244353;

int n, k;
int g[2 * N], len;
int l[N], r[N];
int cnt[2 * N];
int f[N], inv[N], finv[N];
int sum[2 * N];

int C(int x, int y) {
    if (y < 0 || y > x) return 0;
    return f[x] * finv[y] % MOD * finv[x - y] % MOD;
}

void initInv() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i < N; i++) {
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

signed main() {
    initInv();

    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        g[len++] = l[i];
        g[len++] = r[i];
    }
    sort(g, g + len);
    vector<pair<int, int>> events;
    len = unique(g, g + len) - g;
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(g, g + len, l[i]) - g + 1;
        r[i] = lower_bound(g, g + len, r[i]) - g + 1;
        // sum[l[i]] += 1;
        // sum[r[i] + 1] -= 1;
        events.push_back({l[i], i});
        events.push_back({r[i] + 1, -i});
    }
    sort(events.begin(), events.end());
    set<int> s;
    int ans = 0;
    for (int i = 0; i < events.size(); i++) {
        int pt = i;
        while (pt < events.size() && events[pt].first == events[i].first) pt += 1;
        for (int j = i; j < pt; j++) {
            auto e = events[j];
            if (e.second < 0) {
                s.erase(abs(e.second));
            } else {
                s.insert(e.second);
                if (s.size() >= k) {
                    ans = (ans + C(s.size() - 1, k - 1)) % MOD;
                } 
            }
        }
        i = pt - 1;
    }
    cout << ans << endl;
    // bool bigger_k = false;
    // int prev = 0;
    // int ans = 0;
    // for (int i = 1; i <= len; i++) {
    //     sum[i] += sum[i - 1];
    //     if (sum[i] >= k) {
    //         if (!bigger_k) {
    //             ans = (ans + C(sum[i], k)) % MOD;
    //         } else {
    //             if (prev >=) }
    //         bigger_k = true;
    //         prev = sum[i];
    //     } else {
    //         if (bigger_k) {
    //             bigger_k = false;
    //         }
    //     }
    // }
    return 0;
}