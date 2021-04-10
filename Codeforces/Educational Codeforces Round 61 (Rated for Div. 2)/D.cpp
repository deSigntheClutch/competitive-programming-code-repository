#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N], b[N];
int vol[N];

bool check(int charge) {
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        vol[i] = a[i];
        q.push({-(a[i] / b[i] + 1), i});
    }
    for (int i = 1; i <= k - 1; i++) {
        auto x = q.top();
        q.pop();
        int t = -x.first;
        int id = x.second;
        if (t < i) return false;
        vol[id] += charge;
        q.push({-(vol[id] / b[id] + 1), id});
    }
    auto x = q.top();
    q.pop();
    int t = -x.first;
    int id = x.second;
    if (t < k) return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    int l = 0, r = 2e12 + 10, md;
    for (int cs = 0; cs < 42; cs++) {
        md = (l + r) >> 1;
        if (check(md))
            r = md;
        else
            l = md + 1;
    }
    if (md >= (int)2e12 + 9)
        cout << -1 << endl;
    else
        cout << md << endl;
    return 0;
}