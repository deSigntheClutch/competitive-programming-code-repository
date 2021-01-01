#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int LOG_N = 19;
const int INF = 1e9 + 10;

int n, m, ans[N];
int fa[LOG_N][N], depth[N];
vector<int> G[N];

void dfs(int u, int f, int dep) {
    fa[0][u] = f, depth[u] = dep;
    for (int e : G[u]) {
        if (e == f) continue;
        dfs(e, u, dep + 1);
    }
}

void initLCA() {
    for (int i = 0; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i][j] = -1;
        }
    }
    dfs(1, -1, 0);
    for (int i = 1; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            if (fa[i - 1][j] != -1) {
                fa[i][j] = fa[i - 1][fa[i - 1][j]];
            }
        }
    }
}

int query(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int w = depth[b] - depth[a], cnt = 0;
    while (w) {
        if (w & 1) b = fa[cnt][b];
        w >>= 1, cnt++;
    }
    if (a == b) return a;
    for (int i = LOG_N - 1; i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            a = fa[i][a], b = fa[i][b];
        }
    }
    return fa[0][a];
}

vector<int> divisor[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    initLCA();
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            divisor[j].push_back(i);
        }
    }
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        for (int x : divisor[i]) {
            
            int cur = 0;
            int lca = query(x, i);
            if(lca == x){  
                cur = depth[i] - depth[x] + 1;
            }else if(lca == i){
                cur = depth[x] - depth[i] + 1;
            }else{
                cur = depth[x] + depth[i] - 2 * depth[lca] + 1;
            }
            sum += cur;
           // cout << x << " " << i << " " << cur << " "<<lca<<endl;
            
        }
    }
    cout << sum << endl;
    return 0;
}
