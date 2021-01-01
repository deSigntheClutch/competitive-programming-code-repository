#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> G[2004];
int a[2004];
int cnt[2004];
int sz[2004];
int result[2004];

bool flag = true;

void dfs(int u) {
    sz[u] = 1;
    for (int x : G[u]) {
        dfs(x);
        sz[u] += sz[x];
    }
    if (sz[u] - 1 < cnt[u]) flag = false;
}

vector<int> dfs2(int u) {
    vector<int> a;
    for (int x : G[u]) {
       vector<int> b = dfs2(x);
       for (int y : b) {
           a.push_back(y);
       }
    }
    vector<int> res;
    for (int i = 0; i < cnt[u]; i++) {
        res.push_back(a[i]);
    }
    res.push_back(u);
    for (int i = cnt[u]; i < a.size();i++) {
        res.push_back(a[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i++) {
        int p, c;
        cin >> p >> c;
        if (p != 0) G[p].push_back(i);
        else root = i;
        cnt[i] = c;
    }      
    dfs(root);
    if (flag == false) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> ans = dfs2(root);
    for (int i = 0; i < ans.size(); i++) {
        result[ans[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}