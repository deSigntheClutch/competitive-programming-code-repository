#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

bool dp[N][2];
bool end_point[N];
int n, m, s;
int father[N][2];
int deg_in[N];
vector<int> G[N];
set<int> visited;

void dfs(int u, int parity, int from) {
    visited.insert(u);
    dp[u][parity] = true;
    father[u][parity] = from;
    for (int v : G[u]) {
        if (dp[v][parity ^ 1] == false) 
            dfs(v, parity ^ 1, u);
        deg_in[v] += 1;
    }
    if (G[u].size() == 0) {
        end_point[u] = true;
    }
} 

void print(int end) {
    int par = 1;
    vector<int> path;
    while (end != s || par == 1) {
        path.push_back(end);
        end = father[end][par];
        par ^= 1;
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    for (int u :path) {
        cout << u << " ";
    }
    cout << endl;
}

bool check_cycle() {
    queue<int> Q;
    set<int> S;
    if (deg_in[s] == 0) Q.push(s), S.insert(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int x : G[v]) {
            deg_in[x] -= 1;
            if (deg_in[x] == 0) {
                Q.push(x);
                S.insert(x);
            }
        }
    }
    return S.size() != visited.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            G[i].push_back(v);
        }
    }
    cin >> s;
    dfs(s, 0, -1);
    for (int i = 1; i <= n; i++) {
        if (end_point[i] && dp[i][1] == true) {
            cout << "Win" << endl;
            print(i);
            return 0;
        }
    }
    cout << endl;
    if (check_cycle()) {
        cout << "Draw" << endl;
        return 0;
    }
    cout << "Lose" << endl;
    return 0;
}