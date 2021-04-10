#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
const int M = 123;

int fib[N];
int used[N];

vector<int> G[N];
int n;
bool vis[N];
int sz[N];

void dfs(int x, int f, vector<pair<int, int>>& cand, int id) {
    sz[x] = 1;
    for (int y : G[x]) {
        if (f == y || vis[y]) continue;
        dfs(y, x, cand, id);
        sz[x] += sz[y];
    }
    if (fib[id - 2] == sz[x])
        cand.push_back({x, f});
    else if (fib[id - 1] == sz[x])
        cand.push_back({-x, f});
}

bool check(int x, int id) {
    if (id == 0) return false;
    if (id <= 3) return true;

    vector<pair<int, int>> cand;
    dfs(x, -1, cand, id);
    for (auto p : cand) {
        //cout << x << " " << id << " " << p.second << " " << p.first << endl;
        if (p.first < 0) {
            vis[p.second] = true;
            bool flag = check(-p.first, id - 1);
            vis[p.second] = false;
            //cout << x << " " << id << "-> " << flag << endl;
            if (flag == false) {
                continue;
            }
            vis[-p.first] = true;
            flag &= check(p.second, id - 2);
            vis[-p.first] = false;
            //cout << x << " " << id << "-> " << flag << endl;
            if (flag == true) return true;
        } else {
            vis[p.second] = true;
            bool flag = check(p.first, id - 2);
            vis[p.second] = false;
            //cout << x << " " << id << "-> " << flag << endl;
            if (flag == false) {
                continue;
            }
            vis[p.first] = true;
            flag &= check(p.second, id - 1);
            vis[p.first] = false;
            //cout << x << " " << id << "-> " << flag << endl;
            if (flag == true) return true;
        }
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);

    fib[0] = fib[1] = 1;
    used[1] = 1;
    for (int i = 2; i < 40; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] >= N) break;
        used[fib[i]] = i;
    }

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (n <= 3) {
        cout << "YES" << endl;
        return 0;
    }
    int id = used[n];
    bool flag = check(1, id);
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}

/*

13
1 2
1 3
2 4
2 5
4 7
4 8
3 6
6 9
9 10
9 11
10 12
10 13

*/
