#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right

const int N = 1e5 + 4;

int n, m;
int fwt[N * 4];
int x[N], y[N], z[N], w[N];

void add(int x, int v) {
    while (x <= m) {
        fwt[x] += v;
        x += x & -x;
    }
}

int get(int x) {
    int res = 0;
    while (x) {
        res += fwt[x];
        x -= x & -x;
    }
    return res;
}

struct Event {
    int type;
    int t;
    int l, r;
    bool operator < (struct Event e) const {
        if (t == e.t) return type < e.type;
        return t < e.t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> val;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        val.push_back(y[i]);
        val.push_back(w[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    vector<Event> events;
    for (int i = 1; i <= n; i++) {
        y[i] = lower_bound(val.begin(), val.end(), y[i]) - val.begin() + 1;
        w[i] = lower_bound(val.begin(), val.end(), w[i]) - val.begin() + 1;
        events.push_back({-1, x[i], y[i], w[i]});
        events.push_back({1, z[i], y[i], w[i]});
    }
    sort(events.begin(), events.end());
    m = (int)val.size();
    bool flag = false;
    for (auto e : events) {
        //cout << e.type << " " << e.l << " " << e.r << endl;
        if (e.type == -1) {
            int va = get(e.r) - get(e.l - 1);
            if (va != 0) flag = true;
            add(e.r, 1);
            add(e.l, 1);
        } else {
            int va_r = get(e.r) - get(e.r - 1);
            int va_l = get(e.l) - get(e.l - 1);
            int va;
            if (e.r - 1 < e.l) va = 0;
            else va = get(e.r - 1) - get(e.l);
            if (!(va_r == 1 && va_l == 1 && va == 0)) flag = true;
            add(e.r, -1);
            add(e.l, -1);
        }
        //cout << va << endl << endl;
    }
    if (!flag) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}