#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 7;

struct edge {
    int to;
    int cost;
};

int n, d, a1, a2;
vector<edge> G[N];
int dis[2][N][N];
bool vis[N][N];
int angle_to[N][N];
int angle_arrive[N][N];

struct state {
    int from;
    int cur;
    int cost;
    bool operator < (struct state s) const {
        return cost > s.cost;
    }
};

bool in(int l, int r, int alpha) {
    if (l < 0) {
        l = 360 + l;
        return (l <= alpha && alpha <= 360) || (0 <= alpha && alpha <= r);
    }
    if (r >= 360) {
        r -= 360;
        return (l <= alpha && alpha <= 360) || (0 <= alpha && alpha <= r);
    }
    return l <= alpha && alpha <= r;
}

bool chek(int from, int cur, int to) {
    if (from == 0) return true;
    int cur_angle = angle_arrive[from][cur];
    int switch_angle = angle_to[cur][to];
    //cout << from << " " << cur << " => " << to << " " << " " << cur_angle << " " << switch_angle << endl;
   // cout << cur_angle << " " << switch_angle << " ==> ";
    return in(cur_angle, cur_angle + a1, switch_angle) || in(cur_angle - a2, cur_angle, switch_angle);
}

void dijkstra() {

    memset(vis, 0, sizeof vis);
    dis[0][0][1] = 0;
    // <-distance, id>
    priority_queue<state> Q;
    Q.push({0, 1, 0});

    while (!Q.empty()) {
        auto x = Q.top();
        Q.pop();
        if (vis[x.from][x.cur]) continue;
        vis[x.from][x.cur] = true;
        for (auto y : G[x.cur]) {
            if (chek(x.from, x.cur, y.to) == false) continue;
            //cout << dis[0][x.from][x.cur] + y.cost << " + " << dis[0][x.cur][y.to] << endl;
            if (dis[0][x.cur][y.to] > dis[0][x.from][x.cur] + y.cost) {
                dis[0][x.cur][y.to] = dis[0][x.from][x.cur] + y.cost;
                Q.push({x.cur, y.to, dis[0][x.cur][y.to]});
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[0][i][j] == INF) continue;
           // cout << i << " " << j << " " << dis[0][i][j] << endl;
        }
    }

    memset(vis, 0, sizeof vis);
    for (int i = 0; i <= n; i++) {
        if (dis[0][i][d] != INF) {
            dis[1][i][d] = dis[0][i][d];
            Q.push({i, d, dis[0][i][d]});
        }
    }

    while (!Q.empty()) {
        auto x = Q.top();
        Q.pop();
        if (vis[x.from][x.cur]) continue;
        vis[x.from][x.cur] = true;
        for (auto y : G[x.cur]) {
            if (chek(x.from, x.cur, y.to) == false) continue;
           // cout << dis[0][x.from][x.cur] + y.cost << " + " << dis[0][x.cur][y.to] << endl;
            if (dis[1][x.cur][y.to] > dis[1][x.from][x.cur] + y.cost) {
                dis[1][x.cur][y.to] = dis[1][x.from][x.cur] + y.cost;
                Q.push({x.cur, y.to, dis[1][x.cur][y.to]});
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (dis[1][i][j] == INF) continue;
    //         cout << i << " " << j << " " << dis[1][i][j] << endl;
    //     }
    // }
    int ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dis[1][i][1]);
    }
    if (ans >= INF) cout << "impossible" << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> d >> a1 >> a2;
    for (int i = 0; i <= n; i++) for (int j = 0; j <=n; j++) dis[0][i][j] = INF, dis[1][i][j] = INF;

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int dx, tx, ax;
            cin >> dx >> tx >> ax;
            if (ax >= 360) ax %= 360;
            G[i].push_back({dx, tx});
            angle_arrive[dx][i] = (ax + 180) % 360;
            angle_to[i][dx] = ax;
        }
    }
    dijkstra();
    return 0;
}