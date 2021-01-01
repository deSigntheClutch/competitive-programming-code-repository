#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define int long long

using namespace std;

const int N = 3e5 + 5;

pair<int, int> p[N], a[N];
int n;
int fwt[N], cntf[N];
int len;

void add(int *b, int x, int v) {
    while (x <= len) {
        b[x] += v;
        x += x & -x;
    }
}

int get(int *b, int x) {
    int res = 0;
    while (x) {
        res += b[x];
        x -= x & -x;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> velo_neg, velo_pos;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
    }
    sort(p, p + n);

    // come with neg velo
    vector<int> velo;
    for (int i = 0; i < n; i++) {
        velo.push_back(p[i].second);
    }
    
    sort(velo.begin(), velo.end());
    velo.erase(unique(velo.begin(), velo.end()), velo.end());
    len = velo.size();

    int ans = 0;
    int sumx = 0;

    for (int i = 0; i < n; i++) {
        a[i] = p[i];
        a[i].second = lower_bound(velo.begin(), velo.end(), p[i].second) - velo.begin() + 1;
        ans += i * p[i].first - sumx;
        sumx += p[i].first;
    }

    for (int i = 0; i < n; i++) {
        if (p[i].second < 0) {
            ans -= (get(cntf, len) - get(cntf, a[i].second)) * p[i].first - (get(fwt, len) - get(fwt, a[i].second));
        }
        add(fwt, a[i].second, p[i].first);
        add(cntf, a[i].second, 1);
       // cout << ans << " " << get(cntf, len) - get(cntf, a[i].second) << " " << (get(fwt, len) - get(fwt, a[i].second)) << endl;
    }
    //cout << endl;
    memset(cntf, 0, sizeof cntf);
    memset(fwt, 0, sizeof fwt);

    for (int i = n - 1; i >= 0; i--) {
        if (p[i].second > 0) {
            ans -= get(fwt, a[i].second - 1) - get(cntf, a[i].second - 1) * p[i].first;
        }
        if (p[i].second >= 0) {
            add(fwt, a[i].second, p[i].first);
            add(cntf, a[i].second, 1);
        }
        //cout << ans << " " << get(fwt, a[i].second - 1) << " " << get(cntf, a[i].second - 1) << endl;
    }
    cout << ans << endl;
    return 0;
}