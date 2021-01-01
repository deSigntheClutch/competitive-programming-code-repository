#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const int N = 1e2 + 5;

int n, m, x, y;
char ss[N][N * 10];

int main() {
    ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        for (int i = 1; i <= n; i++) {
            scanf("%s", ss[i] + 1);
        }
        int ans = 0;
        if (2 * x <= y) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (ss[i][j] == '.') ans += x;
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (ss[i][j] == '*') continue;
                    int ptr = j;
                    while (ss[i][ptr] == ss[i][j] && ptr <= m) ptr += 1;
                    int len = ptr - j;
                    ans += y * (len / 2);
                    if (len & 1) ans += x;
                    j = ptr - 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
