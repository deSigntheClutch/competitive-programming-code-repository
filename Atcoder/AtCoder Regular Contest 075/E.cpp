#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a[223456];
int sum[223456];
int fwt[223456];

void add(int x, int v) {
    while (x <= (n+2)) {
        fwt[x] += v;
        x += x & -x;
    }
}

int get(int x) {
    int res = 0;
    while (x) {
        res += fwt[x];
        x -= x & -x;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<pair<int, int>> val;
    val.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
        val.push_back({sum[i] - k * i, i});
    }
    sort(val.begin(), val.end());

    int res = 0;
    int pt = 0;

    for (auto p : val) {
        //cout << p.first << " " << p.second << endl;
        int v = p.first;
        int x = p.second;
        while (pt < n + 1 && v >= val[pt].first) {
            //cout << "add: " << val[pt].second << endl;
            add(val[pt].second + 1, 1);
            pt += 1;
        }
        if (x >= 1)
            res += get(x);
    }
    cout << res << endl;
    return 0;
}