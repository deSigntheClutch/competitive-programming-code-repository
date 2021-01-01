#include <bits/stdc++.h>
using namespace std;
#define maxi(x, y) ((x > y) ? (x) : (y))
const int N = 2e5 + 2;

vector<int> G[N];
vector<int> factor[N];

int n;
int a[N];
int ans[N];

bool isp[N];

void init() {
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            factor[j].push_back(i);
        }
    }
}

void dfs1(int u, int f, int val, int key) {
    if (a[u] % val != 0) {
        return ;
    }
    ans[u] = maxi(ans[u], val);
    for (int x : G[u]) {
        if (x == f) continue;
        dfs1(x, u, val, key);
    }
}

void dfs2(int u, int f, int val, int cnt) {
    if (a[u] % val != 0) {
        cnt++;
    }
    if (cnt == 2) return;
    ans[u] = maxi(ans[u], val);
    for (int x : G[u]) {
        if (x == f) continue;
        dfs2(x, u, val, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = 1;
    }
    ans[1] = a[1];
    // zero - 1
    for (int i = 0; i < G[1].size(); i++) {
        int u = G[1][i];
        for (int j = (int)factor[a[u]].size() - 1; j >= 0; j--) {
            int val = factor[a[u]][j];
            dfs1(u, 1, val, u);
        }
    }
    // nonzero - 1
    for (int j = (int)factor[a[1]].size() - 1; j >= 0; j--) {
        int val = factor[a[1]][j];
        dfs2(1, -1, val, 0);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}

