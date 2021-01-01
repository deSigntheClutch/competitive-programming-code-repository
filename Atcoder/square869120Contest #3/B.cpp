#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 200 + 5;

typedef vector<vector<int>> maze;
int n, m, k;
int ans = 0, cur;
int pw2[N];
bool no_vanish;

void vanish(maze& a, int stage) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            int ptr = j;
            while (a[i][j] == a[i][ptr] && ptr < m) ptr += 1;
            if (ptr - j >= k) {
                for(int u = j; u < ptr; u++) {
                    cnt += a[i][u];
                    a[i][u] = 0;
                }
            }
            j = ptr - 1;
        }
    }
    if (cnt > 0) no_vanish = false;
    cur += pw2[stage] * cnt;
}

void reshape(maze& a) {
    for (int j = 0; j < m; j++) {
        vector<int> x;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == 0) continue;
            x.push_back(a[i][j]);
        }
        int ptr = n - 1;
        for (int y : x) {
            a[ptr--][j] = y;
        }
        for (int i = 0; i <= ptr; i++) {
            a[i][j] = 0;
        }
    }
}

void proc(int x, int y, maze a) {
    a[x][y] = 0;
    int stage = 0;
    while(true) {
        no_vanish = true;
        reshape(a);
        vanish(a, stage++);
        if (no_vanish == true) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    pw2[0] = 1;
    for (int i = 1; i < 29; i++) {
        pw2[i] = pw2[i - 1] * 2;
    }
    maze ini = maze(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            ini[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cur = 0;
            proc(i, j, ini);
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}
