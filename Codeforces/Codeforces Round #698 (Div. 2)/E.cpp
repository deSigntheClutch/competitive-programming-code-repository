#include <bits/stdc++.h>
using namespace std;
#define int long long

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 2e5 + 10;

int t[N << 2], lazy[N << 2];
int all[N << 2];

void pushup(int rt) { t[rt] = t[rt << 1] + t[rt << 1 | 1]; }

void pushdown(int rt, int l) {
    if (!lazy[rt]) return;
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    t[rt << 1] += lazy[rt] * ((l + 1) / 2);
    t[rt << 1 | 1] += lazy[rt] * (l - (l + 1) / 2);
    lazy[rt] = 0;
}

void pushdown2(int rt, int l) {
    if (all[rt] == -1) return;
    lazy[rt] = 0;
    all[rt << 1] = all[rt];
    all[rt << 1 | 1] = all[rt];
    t[rt << 1] = all[rt] * ((l + 1) / 2);
    t[rt << 1 | 1] = all[rt] * (l - (l + 1) / 2);
    all[rt] = -1;
}

int query(int rt, int left, int right, int l, int r) {
    if (left == l && r == right) return t[rt];
    pushdown(rt, right - left + 1);
    pushdown2(rt, right - left + 1);
    if (mid >= r)
        return query(lson, l, r);
    else if (mid < l)
        return query(rson, l, r);
    else
        return query(lson, l, mid) + query(rson, mid + 1, r);
}

void add(int rt, int left, int right, int l, int r, int v) {
    if (left == l && r == right) {
        lazy[rt] += v;
        t[rt] += v * (r - l + 1);
        return;
    }
    pushdown(rt, right - left + 1);
        pushdown2(rt, right - left + 1);
    if (mid >= r)
        add(lson, l, r, v);
    else if (mid < l)
        add(rson, l, r, v);
    else
        add(lson, l, mid, v), add(rson, mid + 1, r, v);
    pushup(rt);
}

void filled(int rt, int left, int right, int l, int r, int v) {
    if (left == l && r == right) {
        lazy[rt] = 0;
        all[rt] = v;
        t[rt] = v * (r - l + 1);
        return;
    }
    pushdown(rt, right - left + 1);
    pushdown2(rt, right - left + 1);
    if (mid >= r)
        filled(lson, l, r, v);
    else if (mid < l)
        filled(rson, l, r, v);
    else
        filled(lson, l, mid, v), filled(rson, mid + 1, r, v);
    pushup(rt);
}

string s, f;
int n, q;
int qx[N], qy[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        bool flag = true;
        cin >> n >> q >> s >> f;
        for (int i = 0; i <= 4 * n; i++) {
            lazy[i] = t[i] = 0;
            all[i] = -1;
        }
        for (int i = 0; i < q; i++) {
            cin >> qx[i] >> qy[i];
        }
        for (int i = 1; i <= n; i++) {
            add(1, 1, n, i, i, f[i - 1] - '0');
        }
        for (int i = q - 1; i >= 0; i--) {
            int val = query(1, 1, n, qx[i], qy[i]);
            if (val * 2 == qy[i] - qx[i] + 1) flag = false;
            else {
                if (val * 2 < qy[i] - qx[i] + 1) {
                    filled(1, 1, n, qx[i], qy[i], 0);
                } else {
                    filled(1, 1, n, qx[i], qy[i], 1);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int val = query(1, 1, n, i, i);
            if (val != s[i - 1] - '0') flag = false;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}