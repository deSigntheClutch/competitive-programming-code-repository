#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

map<int, int> mp;
int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] += 1;
        ans += a[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        long long tmp_s = (long long)u * mp[u];
        int tmp = mp[u];
        mp[u] = 0;
        mp[v] += tmp;
        long long tmp_t = (long long)tmp * v;
        cout << ans - tmp_s + tmp_t << endl;
        ans = ans - tmp_s + tmp_t;
    }
    return 0;
}