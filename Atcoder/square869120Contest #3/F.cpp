#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right

typedef long long ll;
const int N = 1e5 + 5;

ll lazy[N << 2], t[N << 2];
int n, q;

void push_up(int rt) {
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}

void push_down(int rt, int len) {
    if (lazy[rt]) {
        lazy[rt << 1] = lazy[rt];
        lazy[rt << 1 | 1] = lazy[rt];
        t[rt << 1] = (ll) lazy[rt] * (len - len / 2);
        t[rt << 1 | 1] = (ll) lazy[rt] * (len / 2);
        lazy[rt] = 0;
    }
}

void update(int rt, int left, int right, int l, int r, ll v) {
    if (l == left && r == right) {
        t[rt] = v * (right - left + 1);
        lazy[rt] = v;
        return;
    }
    push_down(rt, right - left + 1);
    if (mid >= r) update(lson, l, r, v);
    else if (mid < l) update(rson, l, r, v);
    else update(lson, l, mid, v), update(rson, mid + 1, r, v);
    push_up(rt);
}

void add(int rt, int left, int right, int l, int r) {
    if (l == left && r == right) {
        t[rt] += (right - left + 1);
        lazy[rt] += 1;
        return;
    }
    push_down(rt, right - left + 1);
    if (mid >= r) add(lson, l, r);
    else if (mid < l) add(rson, l, r);
    else add(lson, l, mid), add(rson, mid + 1, r);
    push_up(rt);
}

ll query(int rt, int left, int right, int l, int r) {
    if (l == left && r == right) {
        return t[rt];
    }
    push_down(rt, right - left + 1);
    if (mid >= r) return query(lson, l, r);
    else if (mid < l) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid + 1, r);
}

pair<ll, int> left_bound(int rt, int left, int right, int r, ll sum, ll water) {
    if (right <= 1) return {(water + sum)/ r, 1};
    if (left >= r) return {water + query(1, 1, n, r, r), r};
    if (mid >= r) return left_bound(lson, r, sum, water);

    int len = r - mid;
    ll orginal_sum = query(1, 1, n, mid + 1, r); // OPT1: carry sum while turning right 
    ll filling_height_ceil = ((water + orginal_sum) + (len - 1ll)) / len;
    ll filling_height_floor = (water + orginal_sum) / len;
    ll val_mid = query(1, 1, n, mid, mid), val_mid_1 = query(1, 1, n, mid + 1, mid + 1);

    if (filling_height_ceil > val_mid) {
        return left_bound(lson, r, sum, water);
    } else if (filling_height_floor < val_mid_1) {
        return left_bound(rson, r, sum, water);
    } else return {filling_height_floor, mid + 1};
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    while (q--) {
        int a;
        ll b;

        cin >> a >> b;

        ll cur_sum = query(1, 1, n, 1, a);
        auto res = left_bound(1, 1, n, a, cur_sum, b);
        ll original_sum = query(1, 1, n, res.second, a);

        update(1, 1, n, res.second, a, res.first);
        b -= res.first * (a - res.second + 1) - original_sum;

        if (b == 0) continue;
        
        add(1, 1, n, res.second, res.second + b - 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << query(1, 1, n, i, i) << endl;
    }
    return 0;
}