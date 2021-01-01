#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];
int n, col[N];

void dfs(int u, int f, int c) {
    col[u] = c;
    for (int v : G[u]) {
        if (v != f) dfs(v, u, c * -1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1, -1);
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) a++;
        else b++;
    }
    cout << (long long) a * b - n + 1 << endl;
    return 0;
}
