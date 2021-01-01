#include <bits/stdc++.h>
using namespace std;

char s[123][123];
int f[123][123];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i][j] == 'B') cnt++;
        }
    }
     for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + ((s[i][j] == 'B') ? 1 : 0);
        }
    }
    int mn = min(n, m);
    int ans = 12345678;
    for(int len = 1; len <= mn; len++) {
        for(int x = 1; x + len - 1 <= n; x++) {
            for(int y = 1; y + len - 1 <= m; y++) {
                int total = 0;
                total = f[x + len - 1][y + len - 1] - f[x - 1][y + len - 1] - f[x + len - 1][y - 1] + f[x - 1][y-1];
                if(total != cnt) continue;
                ans = min(ans, len * len - cnt);
            }
        }
    }
    if(ans == 12345678) ans = -1;
    printf("%d\n", ans);
    return 0;
}
