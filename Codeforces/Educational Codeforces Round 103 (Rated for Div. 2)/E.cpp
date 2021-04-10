#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
const int MX = 1e6 + 5;

int n, m, k;

string a[N], b[N];
int fst[N];

int to[MX][27];
int val[MX], deg[N];
int total = 1;
vector<int> G[N];

void insert(string &s, int id) {
    int cur = 1;
    for (int i = 0; i < k; i++) {
        int nxt = s[i] - 'a';
        if (s[i] == '_') nxt = 26;
        if (to[cur][nxt] == -1) {
            to[cur][nxt] = ++total;
        }
        cur = to[cur][nxt];
    }
    val[cur] = id;
}

void query(int dep, int cur, string &s, vector<int>& ans, bool &flag, int target) {
    if (cur == -1) return;
    if (dep == k) {
        ans.push_back(val[cur]);
        if (val[cur] == target) flag = true;
        return ;
    }
    int nxt = s[dep] - 'a';
    query(dep + 1, to[cur][nxt], s, ans, flag, target);
    query(dep + 1, to[cur][26], s, ans, flag, target);
}

signed main() {
    ios::sync_with_stdio(false);
    memset(to, -1, sizeof to);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(a[i], i);
    }

    bool flag = true;
    for (int i = 1; i <= m; i++) {
        cin >> b[i] >> fst[i];
        vector<int> res;
        bool find_ans = false;
        query(0, 1, b[i], res, find_ans, fst[i]);

        if (find_ans == false) {
            flag = false;
        } else {
            //cout << i << ": " << b[i] << " -> ";
            for (auto x : res) {
                //cout << x << " ";
                if (x != fst[i]) {
                    G[fst[i]].push_back(x);
                    deg[x] += 1;
                }
            }
            //cout << endl;
        }
    }

    if (!flag) cout << "NO" << endl;
    else {
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for (auto y : G[x]) {
                deg[y] -= 1;
                if (deg[y] == 0) {
                    q.push(y);
                }
            }
        }

        if (ans.size() != n) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int x : ans) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}