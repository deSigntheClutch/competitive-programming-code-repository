#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int N = 2e6 + 10;

int n;
char ans[N], tmp[N];
int f[N];

void init() {
    for (int i = 1; i <= N; i++) {
        f[i] = i;
    }
}

int find(int u) {
    if (f[u] != u) return f[u] = find(f[u]);
    else return f[u];
}

int main() {
    int xlen = 1;
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%s", tmp + 1);
        int len = strlen(tmp + 1);
        scanf("%d", &k);
        int v;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            int pos = find(v);
            xlen = max(xlen, v + len - 1);
            int pt = 1;
            while (pos < v + len) {
                ans[pos] = tmp[1 + pos - v];
                f[pos] = pos + 1;
                pos = find(pos);
            }
        }
    }
    for (int i = 1; i <= xlen; i++) {
        printf("%c", ans[i] == 0 ? 'a' : ans[i]);
    }
    puts("");
    return 0;
}

