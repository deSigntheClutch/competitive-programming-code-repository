#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
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

const int N = 4e5 + 5;

int n, k;
int p[N], deg[N];
set<int> G[N];
int prioritized[N];
bool used[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == 0) continue;
        G[i].insert(p[i]);
        deg[p[i]] += 1;
    }

    bool flag = true;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if (G[y].find(x) == G[y].end()) {
            G[y].insert(x);
            deg[x] += 1;
        }
        if (prioritized[y] != 0) {
            cout << "0" << endl;
            return 0;
        }
        prioritized[y] = x;
    }

    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i]) continue;
        q.push_back(i);
    }

    int cnt = 0;
    vector<int> order;
    while (!q.empty()) {
        int x = q.front();
        cnt += 1;
        q.pop_front();
        order.push_back(x);
        used[x] = 1;

        for (auto y : G[x]) {
            if (used[y]) continue;
            if (y == prioritized[x]) {
                deg[y] -= 1;
                if (deg[y] == 0)
                    q.push_front(y);
                else
                    flag = false;
                continue;
            }
            deg[y] -= 1;
            if (deg[y] == 0) {
                q.push_back(y);
            }
        }
    }
    cout << cnt << endl;
    for (auto x : order) {
        cout << x << " ";
    }
    cout << endl;
    if (!flag || cnt != n)
        cout << 0 << endl;
    else {
        reverse(order.begin(), order.end());
        for (auto x : order) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}