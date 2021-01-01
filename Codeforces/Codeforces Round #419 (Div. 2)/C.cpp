#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1  1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int N = 1e2 + 10;
const int INF = 2e9 + 10;

int n, m;
int a[N][N];
int col[N], row[N];
int ans = INF, ans1[N], ans2[N];

bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (col[j] < 0 || row[i] < 0 || col[j] + row[i] != a[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int add = 0; add <= a[1][1]; add++) {
        memset(row, -1, sizeof row);
        memset(col, -1, sizeof col);
        int sum = add;
        row[1] = add;
        for (int i = 1; i <= m; i++) {
            col[i] = a[1][i] - add;
            sum += col[i];
        }
        for (int i = 2; i <= n; i++) {
            row[i] = a[i][1] - col[1];
            sum += row[i];
        }
        if (check()) {
            if (ans > sum) {
                ans = sum;
                for (int i = 1; i <= n; i++) {
                    ans1[i] = row[i];
                }
                for (int i = 1; i <= m; i++) {
                    ans2[i] = col[i];
                }
            }
        }
    }
    if (ans == INF) printf("-1\n");
    else {
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++) {
            while (ans1[i]--) printf("row %d\n", i);
        }
        for (int i = 1; i <= m; i++) {
            while (ans2[i]--) printf("col %d\n", i);
        }
    }
    return 0;
}

