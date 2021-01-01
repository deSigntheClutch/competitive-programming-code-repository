#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 1E4 + 10;

struct Node {
    int l, r;
} t[2][N << 2];

int n;
int x[N], y[N];
pair<int, int> p[2][N];
vector<int> vs, G[N << 3], rG[N << 3];
bool used[N << 3];
int tot, V, component_id[N << 3];

int left_bound[2][N][2], right_bound[2][N][2];
long long D;

void add_edge(int from, int to) { G[from].push_back(to), rG[to].push_back(from); }

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    component_id[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

int scc() {
    memset(used, 0, sizeof used);
    vs.clear();
    for (int i = 0; i < V; i++)
        if (!used[i]) dfs(i);
    memset(used, 0, sizeof used);
    int k = 1;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
}

pair<int, int> cal(int tar, int id, int left, int right) {
    int l = (left_bound[id][left][tar] == n + 1) ? -1 : left_bound[id][left][tar];
    int r = (right_bound[id][right][tar] == 0) ? -1 : right_bound[id][right][tar];
    return {l, r};
}

void proc(int id, int src, int ix, int rt, int left, int right, int l, int r) {
    if (l == -1 || r == -1 || l > r) return;
    if (left == l && r == right) {
        cout << id << " " << src << " -> " << ix << " " << rt << " _ " << l << " " << r << endl;
        add_edge(id * tot + src, ix * tot + rt);
        return;
    }
    if (mid >= r) {
        proc(id, src, ix, lson, l, r);
    } else if (mid < l) {
        proc(id, src, ix, rson, l, r);
    } else {
        proc(id, src, ix, lson, l, mid);
        proc(id, src, ix, rson, mid + 1, r);
    }
}

void build_tree(int id, int rt, int left, int right) {
    pair<int, int> rangeX = cal(0, id, left, right);
    pair<int, int> rangeY = cal(1, id, left, right);
    if (id == 1) {
        proc(id, rt, 1, 1, 1, n, rangeY.first, left - 1);
        proc(id, rt, 1, 1, 1, n, right + 1, rangeY.second);
        proc(id, rt, 0, 1, 1, n, rangeX.first, rangeX.second);
    } else {
        proc(id, rt, 1, 1, 1, n, rangeY.first, rangeY.second);
        proc(id, rt, 0, 1, 1, n, rangeX.first, left - 1);
        proc(id, rt, 0, 1, 1, n, right + 1, rangeX.second);
    }
    if (left == right) return;
    build_tree(id, lson), build_tree(id, rson);
}

void traverse(int id, int rt, int left, int right) {
    t[id][rt] = {left, right};
    if (left == right) return;
    traverse(id, lson), traverse(id, rson);
}

long long dis(int id1, int x, int id2, int y) {
    if (id1 == id2)
        return (long long)(p[id1][x].first - p[id2][y].first) * (p[id1][x].first - p[id2][y].first);
    else
        return (long long)p[id1][x].first * p[id1][x].first + (long long)p[id2][y].first * p[id2][y].first;
}

bool check() {
    tot = 2 * n - 1;
    for (int i = 1; i <= tot * 2; i++) {
        G[i].clear();
        rG[i].clear();
    }
    memset(left_bound, 0, sizeof left_bound);
    memset(right_bound, 0, sizeof right_bound);
    int ptr;
    for (int id = 0; id < 2; id++) {
        for (int tar_id = 0; tar_id < 2; tar_id++) {
            ptr = 1;
            for (int i = 1; i <= n; i++) {
                while (dis(id, i, tar_id, ptr) > D * D && ptr <= n) ptr += 1;
                left_bound[id][i][tar_id] = ptr;
            }
        }
    }
    for (int id = 0; id < 2; id++) {
        for (int tar_id = 0; tar_id < 2; tar_id++) {
            ptr = 1;
            for (int i = 1; i <= n; i++) {
                while (dis(id, i, tar_id, ptr) <= D * D && ptr <= n) ptr++;
                if (dis(id, i, tar_id, ptr - 1) > D * D) continue;
                right_bound[id][i][tar_id] = ptr - 1;
            }
        }
    }
    // for (int id = 0; id < 2; id++) {
    //     for (int tar_id = 0; tar_id < 2; tar_id++) {
    //         for (int i = 1; i <= n; i++) {
    //             cout << id << " " << tar_id << " " << i << ": " <<
    //             left_bound[id][i][tar_id] << " " << right_bound[id][i][tar_id]
    //             << endl;
    //         }
    //     }
    // }
    traverse(0, 1, 1, n), traverse(1, 1, 1, n);
    build_tree(0, 1, 1, n);
    build_tree(1, 1, 1, n);

    scc();
    for (int i = 1; i <= tot; i++) {
        if (component_id[i] == component_id[i + tot] && component_id[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        p[0][i] = {x[i], i};
        p[1][i] = {y[i], i};
    }
    sort(p[0] + 1, p[0] + n + 1);
    sort(p[1] + 1, p[1] + n + 1);
    // long long l = 1, r = 2e9 + 10;
    long long l = 4, r = 4;
    for (int i = 0; i < 1; i++) {
        D = (l + r) >> 1;
        if (check())
            l = D + 1;
        else
            r = D;
    }
    cout << D + 1 << endl;
    return 0;
}
