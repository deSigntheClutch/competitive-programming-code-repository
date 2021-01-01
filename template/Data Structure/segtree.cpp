#include <bits/stdc++.h>
using namespace std;

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 5E4 + 10;

int t[N << 2], lazy[N << 2];

void pushup(int rt) { t[rt] = t[rt << 1] + t[rt << 1 | 1]; }

void pushdown(int rt, int l) {
    if (lazy[rt]) {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        t[rt << 1] += lazy[rt] * ((l + 1) / 2);
        t[rt << 1 | 1] += lazy[rt] * (l - (l + 1) / 2);
        lazy[rt] = 0;
    }
}

void build(int rt, int left, int right) {
    if (left == right) {
        t[rt] = 0;
        return;
    }
    build(lson), build(rson);
    pushup(rt);
}

int query(int rt, int left, int right, int l, int r) {
    if (left == l && r == right) return t[rt];
    pushdown(rt, right - left + 1);
    if (mid >= r)
        return query(lson, l, r);
    else if (mid < l)
        return query(rson, l, r);
    else
        return query(lson, l, mid) + query(rson, mid + 1, r);
}

void add(int rt, int left, int right, int l, int r) {
    if (left == l && r == right) {
        lazy[rt]++;
        t[rt] += r - l + 1;
        return;
    }
    pushdown(rt, right - left + 1);
    if (mid >= r)
        add(lson, l, r);
    else if (mid < l)
        add(rson, l, r);
    else
        add(lson, l, mid), add(rson, mid + 1, r);
    pushup(rt);
}
