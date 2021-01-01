#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 2e5 + 5;

int n, a[N];
int t[N * 4];
int ans[N], pre[N];

void push_up(int rt) {
    t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
}

void update(int rt, int left, int right, int id, int val) {
    if (left == right) {
        t[rt] = val;
        return;
    }
    if (mid >= id)
        update(lson, id, val);
    else
        update(rson, id, val);
    push_up(rt);
}

int query(int rt, int left, int right, int r) {
    if (left == right && r == right) {
        return t[rt];
    }
    if (mid >= r)
        return query(lson, r);
    else
        return min(t[rt << 1], query(rson, r));
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) ans[1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] - 1 != 0) {
            int minimum = query(1, 1, n, a[i] - 1);
            if (minimum > pre[a[i]]) {
                ans[a[i]] = 1;
            }
        }
        pre[a[i]] = i;
        update(1, 1, n, a[i], i);
    }
    for (int i = 2; i <= n + 1; i++) {
        int minimum = query(1, 1, n, i - 1);
        if (minimum > pre[i]) {
            ans[i] = 1;
        }
    }
    for (int i = 1; i <= n + 2; i++) {
        if (!ans[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}