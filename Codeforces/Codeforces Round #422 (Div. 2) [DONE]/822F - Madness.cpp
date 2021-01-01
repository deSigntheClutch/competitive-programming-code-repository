#include <bits/stdc++.h>
using namespace std;

const int eps = 1e-9;
const int N = 1e2 + 10;

struct edge {
    int to, id;
};

int n;
vector<edge> G[N];

void dfs(int u, int f, double diff) {
    double pace = 2.0 / (int)G[u].size();
    for (edge x : G[u]) {
        int v = x.to, id = x.id + 1;
        if (v == f) continue;
        diff += pace;
        if (diff - 2.0 > -eps) diff -= 2.0;
        if (diff < 1.0) {
            printf("1 %d %d %d %.10f\n", id, v, u, 1.0 - diff);
            dfs(x.to, u, diff + 1);
        } else {
            printf("1 %d %d %d %.10f\n", id, u, v, 2.0 - diff);
            dfs(x.to, u, diff - 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back((edge) {
            v, i
        });
        G[v].push_back((edge) {
            u, i
        });
    }
    printf("%d\n", n - 1);
    dfs(1, -1, 0);
    return 0;
}

/*

4
2 1
3 4
3 2

*/
