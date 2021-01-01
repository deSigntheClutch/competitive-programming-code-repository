#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int group[N];
int s[2];
bool border[N];
int sb[2];
vector<int> G[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> group[i];
        s[group[i]] += 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (group[a] != group[b]) {
            G[a].push_back(b);
            G[b].push_back(a);
            border[a] = 1;
            border[b] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (border[i] == 1) {
            sb[group[i]] += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int res = s[group[i]] - 1;
        int cnt = 0;
        if (border[i] == 1) {
            for (int v : G[i]) {
                res++;
                cnt += 1;
            }
            res += (s[group[i] ^ 1] - cnt) * 2;
        } else {
            res += sb[group[i] ^ 1] * 2;
            res += (s[group[i] ^ 1] - sb[group[i] ^ 1]) * 3;
        }
        cout << res << " ";
    }
    cout << endl;
    return 0;
}