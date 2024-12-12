#include "bits/stdc++.h"
using namespace std;

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 1e5 + 2;

int n, m;
int t[N << 2];
int a[N], L[N], R[N];
bool lazy[N << 2];

void pushup(int rt) {
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}

void pushdown(int rt, int len) {
    if (lazy[rt] == true) {
        lazy[rt << 1] = true, lazy[rt << 1 | 1] = true, lazy[rt] = false;
        int val = t[rt] / len;
        t[rt << 1] = val * (len - len / 2), t[rt << 1 | 1] = val * (len / 2);
    }
}

void init(int rt, int left, int right) {
    t[rt] = 0, lazy[rt] = false;
    if (left == right) return ;
    init(lson), init(rson);
}

int query(int rt, int left, int right, int l, int r) {
    if (l > r) return -1;
    if (l == left && r == right) {
        return t[rt];
    }
    pushdown(rt, right - left + 1);
    if (mid >= r) return query(lson, l, r);
    else if (mid < l) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid + 1, r);
}

void print() {
    for (int i = 1; i <= n; i++) {
        cout << query(1, 1, n, i, i) << " ";
    }
    cout << endl;
}

void update(int rt, int left, int right, int l, int r, int val) {
    if (l > r) return;
    if (left == l && r == right) {
        t[rt] = (right - left + 1) * val;
        lazy[rt] = true;
        return ;
    }
    pushdown(rt, right - left + 1);
    if (mid >= r) update(lson, l, r, val);
    else if (mid < l) update(rson, l, r, val);
    else update(lson, l, mid, val), update(rson, mid + 1, r, val);
    pushup(rt);
}

bool check(int x) {
    if (x > n) return false;
    init(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x) update(1, 1, n, i, i, 1);
        else update(1, 1, n, i, i, 0);
    }
    for (int i = 1; i <= m; i++) {
        int l = L[i], r = R[i];
        if (l > r) swap(l, r);
        int val = query(1, 1, n, l, r);
        if (L[i] > R[i]) {
            update(1, 1, n, l, l + val - 1, 1);
            update(1, 1, n, l + val, r, 0);
        } else {
            update(1, 1, n, l, r - val, 0);
            update(1, 1, n, r - val + 1, r, 1);
        }
    }
    return query(1, 1, n, (n + 1) / 2, (n + 1) / 2) == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int l = 1, r = n + 1, md;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> L[i] >> R[i];
    }
    for (int i = 0; i < 20; i++) {
        md = (l + r) >> 1;
        if (check(md)) l = md + 1;
        else r = md;
    }
    cout << md - 1 << endl;
    return 0;
}