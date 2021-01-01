#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 4;
const double eps = 1e-9;
const double INF = 1e60;

int n, k;
int s[N], p[N];
vector<int> G[N];
double val[N];
double dp[N][N];
int cnt = 0;
int L[N], R[N], ord[N];

void dfs(int u, int f) {
    L[u] = ++cnt;
    ord[cnt] = u;
    for (int v : G[u]) {
        if (u == f) continue;
        dfs(v, u);
    }
    R[u] = cnt;
}

double cal(double D) {
    for (int i = 2; i <= n; i++) {
        val[i] = p[i] - D * s[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] <= -INF) continue;
            if (j + 1 <= k) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + val[ord[i + 1]]);
            }
            dp[R[ord[i + 1]]][j] = max(dp[i][j], dp[R[ord[i + 1]]][j]);
        }
    }
    return dp[n][k]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> k >> n;
    for (int i = 2; i <= n + 1; i++) {
        int c;
        cin >> s[i] >> p[i] >> c;
        c += 1;
        G[c].push_back(i);
    }
    n += 1;
    dfs(1, -1);
    double l = 0, r = 1e5 + 2, md;
    for (int i = 0; i < 44; i++) {
        md = .5 * (l + r);
        if (cal(md) > -eps) l = md;
        else r = md;
    }
    cout << fixed << setprecision(3) << md << endl;
    return 0;
}