#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

vector<int> G[N];
int cur = 1, n;
int L[N], R[N];

void dfs(int x, int f, int left) {
    int children = G[x].size() - (x != 1);
    L[x] = left;
    R[x] = cur + children + 1;
    int child_left_pos = R[x] - 1;
    cur = max(cur, R[x]);
    for (int u : G[x]) {
        if (u == f) continue;
        dfs(u, x, child_left_pos--);
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1, 1);
    for (int i = 1; i <= n; i++) {
        cout << L[i] << " " << R[i] << endl;
    }
    return 0;
}