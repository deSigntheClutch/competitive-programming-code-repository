#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

map<int, int> pos;
int n, t[N << 2], lazy[N << 2];

void pushup(int rt) { t[rt] = (t[rt << 1] + t[rt << 1 | 1]) % MOD; }

void pushdown(int rt, int l) {
    if (lazy[rt]) {
        lazy[rt << 1] = (lazy[rt << 1] + lazy[rt]) % MOD;
        lazy[rt << 1 | 1] = (lazy[rt << 1 | 1] + lazy[rt]) % MOD;
        t[rt << 1] = (t[rt << 1] + lazy[rt] * ((l + 1) / 2)) % MOD;
        t[rt << 1 | 1] = (t[rt << 1 | 1] + lazy[rt] * (l - (l + 1) / 2)) % MOD;
        lazy[rt] = 0;
    }
}

int query(int rt, int left, int right, int l, int r) {
    if (l > r) return 0;
    if (left == l && r == right) return t[rt];
    pushdown(rt, right - left + 1);
    if (mid >= r)
        return query(lson, l, r);
    else if (mid < l)
        return query(rson, l, r);
    else
        return (query(lson, l, mid) + query(rson, mid + 1, r)) % MOD;
}

void add(int rt, int left, int right, int l, int r) {
    if (left == l && r == right) {
        lazy[rt] = (lazy[rt] + 1) % MOD;
        t[rt] = (t[rt] + r - l + 1) % MOD;
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

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> ord;
    for (int t, i = 1; i <= n; i++) {
        cin >> t;
        pos[t] = i;
        ord.push_back(t);
    }
    sort(ord.begin(), ord.end());
    int ans = 0;
    for (int x : ord) {
        int p = pos[x];
        int sum0 = p * (n - p + 1) % MOD;
        int sum1 = p * ((query(1, 1, n, 1, n) - query(1, 1, n, 1, p - 1) + MOD) % MOD) % MOD;
        int sum2 = (MOD - ((n - p + 1) * query(1, 1, n, 1, p - 1) % MOD)) % MOD;
        ans = (ans + (sum0 + sum1 + sum2) % MOD * x % MOD) % MOD;
        add(1, 1, n, p, n);
    }
    cout << ans << endl;
    return 0;
}