#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const double pi = acos(-1.0);
const int INF = 1e9 + 1;
const int N = 1e5 + 5;

int a[N], n;
int sum[N], rsum[N];
int t[2][N << 2];

void push_up(int id, int rt) {
    t[id][rt] = max(t[id][rt << 1 | 1], t[id][rt << 1]);
}

void update(int id, int rt, int left, int right, int x, int val) {
    if (left == right && left == x) {
        t[id][rt] = val;
        return;
    }
    if (mid >= x) update(id, lson, x, val);
    else update(id, rson, x, val);
    push_up(id, rt);
}

int query(int id, int rt, int left, int right, int l, int r) {
    if (l > r) return -1e9;
    if (l == left && r == right) {
        return t[id][rt];
    }
    if (mid >= r) return query(id, lson, l, r);
    else if (mid < l) return query(id, rson, l, r);
    else return max(query(id, lson, l, mid),query(id, rson, mid+1, r));
}


void init1() {
    for (int i = 1; i <= n; i++) {
        update(0, 1, 1, n, i, sum[i]);
        update(1, 1, 1, n, i, rsum[i]);
    }
}
int l[N], r[N];
map<int, vector<int>> pos;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        rsum[i] = rsum[i + 1] + a[i];
    }
    init1();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = n + 1;
        for (int x = a[i] + 1; x <= 30; x++) {
            int id = lower_bound(pos[x].begin(), pos[x].end(), i) - pos[x].begin() - 1;
            if (id >= 0 && id < pos[x].size()) {
                l = max(l, pos[x][id]);
            }
        }
        for (int x = a[i] + 1; x <= 30; x++) {
            int id = lower_bound(pos[x].begin(), pos[x].end(), i) - pos[x].begin();
            if (id >= 0 && id < pos[x].size()) {
                r = min(r, pos[x][id]);
            }
        }
        //cout << l << " " << r << endl;
        //cout << query(0, 1, 1, n, i + 1, r - 1) - sum[i] << " " << query(1, 1, 1, n, l + 1, i - 1) - rsum[i] << endl;
        ans = max(ans, max(0, query(0, 1, 1, n, i + 1, r - 1) - sum[i]) + max(0, query(1, 1, 1, n, l + 1, i - 1) - rsum[i]));
    }
    cout << ans << endl;
    return 0;
}
