#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
const long long INF = 1e15;

struct edge {
    int from;
    int to;
    int cost;
};

struct status {
    int to;
    bool umax;
    bool umin;
    long long cost;

    bool operator<(struct status s) const { return cost > s.cost; }
};

int n, m;
long long dp[N][2][2];
vector<edge> G[N];
bool used[N][2][2];

int main() {
    scanf("%d %d", &n, &m);
    for (int u, v, c, i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back({u, v, c});
        G[v].push_back({v, u, c});
    }

    for (int i = 1; i <= n; i++) {
        for (int umin = 0; umin < 2; umin++) {
            for (int umax = 0; umax < 2; umax++) {
                dp[i][umax][umin] = INF;
            }
        }
    }
    dp[1][0][0] = 0;
    priority_queue<status> heap;
    heap.push({1, 0, 0, 0});

    while (!heap.empty()) {
        auto s = heap.top();
        heap.pop();
        if (used[s.to][s.umax][s.umin]) continue;
        used[s.to][s.umax][s.umin] = true;
        for (edge e : G[s.to]) {
            if (s.umax == false && s.umin == false) {
                if (dp[e.to][1][1] > dp[s.to][s.umax][s.umin] + e.cost) {
                    dp[e.to][1][1] = dp[s.to][s.umax][s.umin] + e.cost;
                    heap.push({e.to, 1, 1, dp[e.to][1][1]});
                }
            }
            if (s.umax == false) {
                if (dp[e.to][1][s.umin] > dp[s.to][s.umax][s.umin]) {
                    dp[e.to][1][s.umin] = dp[s.to][s.umax][s.umin];
                    heap.push({e.to, 1, s.umin, dp[e.to][1][s.umin]});
                }
            }
            if (s.umin == false) {
                if (dp[e.to][s.umax][1] > dp[s.to][s.umax][s.umin] + e.cost + e.cost) {
                    dp[e.to][s.umax][1] = dp[s.to][s.umax][s.umin] + e.cost + e.cost;
                    heap.push({e.to, s.umax, 1, dp[e.to][s.umax][1]});
                }
            }
            if (dp[e.to][s.umax][s.umin] > dp[s.to][s.umax][s.umin] + e.cost) {
                dp[e.to][s.umax][s.umin] = dp[s.to][s.umax][s.umin] + e.cost;
                heap.push({e.to, s.umax, s.umin, dp[e.to][s.umax][s.umin]});
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dp[i][1][1]);
    }
    printf("\n");
    return 0;
}