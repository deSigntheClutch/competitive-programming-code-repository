#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char a[N][N];
int n, m, vis[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char al[4] = {'D', 'R', 'U', 'L'};
string route;

void dfs(int x, int y, string s) {
    vis[x][y] = true;
    if (a[x][y] == 'F') {
        route = s;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (vis[tx][ty] == false && tx >= 1 && tx <= n && ty >= 1 && ty <= m &&a[tx][ty] != '*') {
            dfs(tx, ty, s + (char)al[i]);
        }
    }
}

bool safeUD(int x, int y) {
    if (a[x + 1][y] == '*' || a[x - 1][y] == '*')return false;
    return true;
}

bool safeLR(int x, int y) {
    if (a[x][y - 1] == '*' || a[x][y + 1] == '*')return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    dfs(1, 1, "");
    int swapLR = -1, swapUD = -1;
    int x = 1, y = 1, p, q;
    for (int i = 0; i < route.length(); i++) {
        if (swapLR == -1 && route[i] == 'R') {
            printf("L\n");
            fflush(stdout);
            scanf("%d%d", &p, &q);
            if (p == x && q == y) swapLR = 0, i--;
            else swapLR = 1;
        } else if (swapUD == -1 && route[i] == 'D') {
            printf("U\n");
            fflush(stdout);
            scanf("%d%d", &p, &q);
            if (p == x && q == y) swapUD = 0, i--;
            else swapUD = 1;
        } else {
            if (route[i] == 'L') {
                if (swapLR) printf("R\n");
                else printf("L\n");
            }
            if (route[i] == 'R') {
                if (swapLR) printf("L\n");
                else printf("R\n");
            }
            if (route[i] == 'U') {
                if (swapUD) printf("D\n");
                else printf("U\n");
            }
            if (route[i] == 'D') {
                if (swapUD) printf("U\n");
                else printf("D\n");
            }
            fflush(stdout);
            scanf("%d%d", &p, &q);
        }
        x = p, y = q;
    }
    printf("D\n");
    fflush(stdout);
    return 0;
}
