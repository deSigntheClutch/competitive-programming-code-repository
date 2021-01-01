#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;

int n, m, total, vv;
int pa[N], gid[N];
int val[N];
int dp[N], degin[N];
char ch[N][N];
vector<int> G[N];

int find(int x) {
    if (pa[x] != x) return pa[x] = find(pa[x]);
    return pa[x];
}

void init() {
    for (int i = 1; i <= total; i++) {
        pa[i] = i;
    }
}

bool topo() {
    int cnt = 0;
    queue<int> Q;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= vv; i++) {
        if (degin[i] == 0) {
            Q.push(i);
            dp[i] = 0;
        }
    }
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cnt += 1;
        for (int x : G[cur]) {
            degin[x] -= 1;
            if (degin[x] == 0) {
                dp[x] = dp[cur] + 1;
                Q.push(x);
            }
        }
    }
    return vv == cnt;
}

int main() {
    scanf("%d%d", &n, &m);
    total = n + m;
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ch[i][j] == '=') {
                int x = find(i);
                int y = find(n + j);
                if (x != y) {
                    pa[x] = y;
                }
            }
        }
    }
    vector<int> ssh;
    for (int i = 1; i <= total; i++) {
        ssh.push_back(find(i));
    }
    sort(ssh.begin(), ssh.end());
    ssh.erase(unique(ssh.begin(), ssh.end()), ssh.end());
    for (int i = 0; i < ssh.size(); i++) {
        gid[ssh[i]] = i + 1;
    }
    vv = ssh.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ch[i][j] == '>') {
                int x = find(i);
                int y = find(n + j);
                degin[gid[y]] += 1;
                G[gid[x]].push_back(gid[y]);
            }
            if (ch[i][j] == '<') {
                int x = find(i);
                int y = find(n + j);
                G[gid[y]].push_back(gid[x]);
                degin[gid[x]] += 1;
            }
        }
    }
    bool has_cyc = topo();
    if (has_cyc == false) {
        printf("No\n");
        return 0;   
    }
    int max_val = *max_element(dp, dp + vv + 1);
    for (int i = 1; i <= total; i++) {
        val[i] = max_val - dp[gid[find(i)]];
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", val[i]);
    } 
    printf("\n");
    for (int j = 1 ;j <= m; j++) {
        printf("%d ", val[j + n]);
    }
    printf("\n");
    return 0;
}