#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, m;
int fa[N];
int cnt[N];

int find (int x) {
    if (fa[x] != x) return fa[x] = find(fa[x]);
    return fa[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        fa[x] = y;
        cnt[y] += cnt[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cnt[i] = 1;
    }
    for (int t,i = 1; i <= m; i++) {
        cin >> t;
        int prev = -1;
        for(int x, j = 1; j <= t; j++) {
            cin >> x;
            if (j >= 2) {
                unite(x, prev);
            }
            prev = x;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[find(i)] << " ";
    }
    cout << endl;
    return 0;
}