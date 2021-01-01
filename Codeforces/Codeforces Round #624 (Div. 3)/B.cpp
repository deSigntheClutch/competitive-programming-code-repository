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

const int N = 1e3 + 5;

int n, m;
int a[N], p[N];
int pa[N], val[N];
vector<int> group[N];
bool used[N];

int find(int u) {
    if (pa[u] != u) return pa[u] = find(pa[u]);
    return pa[u];
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            val[i] = a[i];
            pa[i] = i;
            group[i].clear();
            used[i] = false;
        }
        sort(val + 1, val + 1 + n);
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= m; i++) {
            int x = find(p[i]);
            int y = find(p[i] + 1);
            if (x != y) {
                if (x > y) {
                    pa[x] = y;
                } else {
                    pa[y] = x;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            group[find(i)].push_back(a[i]);
        }
        int start = 1;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            sort(group[i].begin(), group[i].end());
        }
        for (int i = 1; i <= n; i++) {
            int y = find(i);
            if (used[y]) continue;
            used[y] = true;
            for (int x : group[y]) {
                //cout << x << " " << val[start] << "| ";
                if (val[start] == x) {
                    start += 1;
                } else {
                    flag = true;
                }
            }
            //cout << endl;
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}