#include <bits/stdc++.h>
using namespace std;

const int M = 3e6 + 10;

int sz[M];
int n, m;
int per;

int query(int u) {
    int cur = 1;
    int ans = 0;
    for (int i = 18; i >= 0; i--) {
        ans <<= 1;
        if (u & (1 << i)) {
            if (sz[cur * 2 + 1] == (1 << i)) {
                cur = 2 * cur;
                ans |= 1;
            } else {
                cur = 2 * cur + 1;
            }
        } else {
            if (sz[cur * 2] == (1 << i)) {
                cur = 2 * cur + 1;
                ans |= 1;
            } else {
                cur = 2 * cur;
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        int cur = 1;
        for (int j = 18; j >= 0; j--) {
            int u = (a & (1 << j));
            if (u) cur = 2 * cur + 1;
            else cur = 2 * cur;
        }
        sz[cur] = 1;
        while (cur != 0) {
            int v = cur / 2;
            sz[v] = sz[2 * v] + sz[2 * v + 1];
            cur /= 2;
        }
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        per ^= x;
        printf("%d\n", query(per));
    }
    return 0;
}
/*

2 4
0 0
0
1
1
0





*/
