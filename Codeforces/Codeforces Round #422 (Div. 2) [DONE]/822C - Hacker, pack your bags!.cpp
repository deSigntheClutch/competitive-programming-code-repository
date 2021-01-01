#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 10;
const int INF = 2e9 + 10;

struct interval {
    int l, r, v;
    bool operator < (struct interval s) const {
        return l < s.l;
    }
};

vector<interval> vec;
vector<pair<int, int>> event[N];
int opt[N], n, x, ans = INF;

void update(int u) {
    for (pair<int, int> t : event[u]) {
        opt[t.se] = min(opt[t.se], t.fi);
    }
}

int main() {
    scanf("%d%d", &n, &x);
    fill(opt, opt + 1 + x, INF);
    for (int i = 0; i < n; i++) {
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        vec.pb((interval) {
            l, r, v
        });
    }
    sort(vec.begin(), vec.end());
    int bound = 0;
    for (interval v : vec) {
        while (bound < v.l) update(bound++);
        int cur = x - (v.r - v.l + 1);
        if (cur >= 1 && opt[cur] != INF) {
            ans = min(ans, v.v + opt[cur]);
        }
        event[v.r].pb(mp(v.v, v.r + 1 - v.l));
    }
    if(ans >= INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}
