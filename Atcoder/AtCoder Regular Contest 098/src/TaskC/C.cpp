#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 3;

int n, k, q;
int a[N];
bool used[N];
int section[N], tot;

int cal(int val) {
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; i++)
        if (a[i] < val)
            used[i] = true;
    memset(section, 0, sizeof section);
    tot = 0;
    multiset<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        int ptr = i;
        while (ptr <= n && used[ptr] == false) ptr++;
        for (int j = i; j < ptr; j++) {
            s.insert({a[j], tot});
        }
        section[tot++] = ptr - i;
        i = ptr - 1;
    }
    int cnt = 0;
    int mx = 0;
    for (auto x : s) {
        if (section[x.second] >= k) {
            section[x.second] -= 1;
            cnt += 1;
            mx = max(mx, x.first);
        }
        if (cnt == q) break;
    }
    if (cnt < q) return 1e9 + 1;
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> q;
    set<int> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int ans = 1e9 + 1;
    for (int minimum : s) {
        if (cal(minimum) > 1e9) continue;
        ans = min(ans, cal(minimum) - minimum);
    }
    cout << ans << endl;
    return 0;
}