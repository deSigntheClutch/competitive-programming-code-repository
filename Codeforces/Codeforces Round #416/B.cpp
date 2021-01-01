#include <bits/stdc++.h>
using namespace std;

int n, m, p[12345];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
    }
    for (int i = 1; i <= m; i++) {
        int l, r, x, cnt = 0;
        scanf("%d%d%d", &l, &r, &x);
        for (int j = l; j <= r; j++) {
            if (p[j] < p[x])cnt++;
        }
        if (l + cnt == x) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
