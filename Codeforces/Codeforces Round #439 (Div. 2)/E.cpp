#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1))
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid+1, right

const int N = 3e3 + 10;
int n, m, q;
int t[N << 2][N << 2];

void pushupY(int rt) {

}

void buildY(int u, int rt, int left, int right) {
    if (left == right) {
        t[u][rt] = 0;
        return;
    }
    buildX(lson);
    buildX(rson);
    pushupY(rt);
}

void buildX(int rt, int left, int right) {
    if (left == right) {
        buildY(rt, 1, 1, n);
        return
    }
    buildX(lson);
    buildX(rson);
    pushup(rt);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    build(0, 1, 1, n);
    while (q--) {
        int op, r1, c2, c1, r2;
        cin >> op;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);
    }
    return 0;
}
