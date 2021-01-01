#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

int n, m;
char a[N][N], b[N][N];
bool vis_row[N];
bool vis_col[N];

int main() {
    ios::sync_with_stdio(false); 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", b[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == 'X') cnt += 1;
        }
        if (cnt >= 2)  vis_row[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (b[j][i] == 'X') cnt += 1;
        }
        if (cnt >= 2)  vis_col[i] = 1;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!vis_row[i]) continue;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != b[i][j]) 
                flag = false;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!vis_col[i]) continue;
        for (int j = 1; j <= n; j++) {
            if (a[j][i] != b[j][i]) 
                flag = false;
        }
    }
    if (flag) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}