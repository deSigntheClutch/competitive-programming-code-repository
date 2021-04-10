#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 4e5 + 5;

bool flag;
int n, cnt;
vector<int> G[N];
bool vis[N];

void dfs(int x, int f) {
    vis[x] = true;
    cnt += 1;
    for (int v : G[x]) {
        if (v == f) continue;
        if (vis[v] == false) {
            dfs(v, x);
        } else {
            flag = true;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;for (int a,b,i = 0; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int res = 0;
    for (int i = 1; i <= 400000; i++) {
        if (vis[i]) continue;

        flag = false, cnt = 0;
        dfs(i, -1);
        res += cnt;
        if (flag == false) res -= 1;
    }
    cout << res << endl;
    return 0;
}