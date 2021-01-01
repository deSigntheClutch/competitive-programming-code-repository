/*


0
10
4
-1 1
1 1
0 0
0 1

*/

//  g++ -std=c++14 E.cpp -o e && ./e
#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right

const int N = 2e5 + 2;
const int INF = 1e9 + 10;

pair<int, int> intv[N];
int n, m;
int pa[N], pref[N], suff[N], most_left[N];
int dp[N], t[N << 2];

int get(int x) {
    if (pa[x] != x) return pa[x] = get(pa[x]);
    else return pa[x];
}

void init() {
    for (int i = 1; i <= n; i++) pa[i] = i;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a > b;
}

void pushup(int rt) {
  t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
}

int query(int rt, int left, int right, int l, int r) {
  if (r < l) return INF;
  if (left == l && r == right) return t[rt];
  if (mid >= r) return query(lson, l, r);
  else if (mid < l) return query(rson, l, r);
  else return min(query(lson, l, mid), query(rson, mid + 1, r));
}

void update(int rt, int left, int right, int id, int v) {
  if (left == right && id == right) {
    t[rt] = v;
    return ;
  }
  if (mid >= id) update(lson, id, v);
  else update(rson, id, v);
  pushup(rt);
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> val;
        for (int i = 1; i <= n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            intv[i] = {t2, t1};
            val.push_back(t1);
            val.push_back(t2);
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        for (int i = 1; i <= n; i++) {
            intv[i].first = lower_bound(val.begin(), val.end(), intv[i].first) - val.begin() + 1;
            intv[i].second = lower_bound(val.begin(), val.end(), intv[i].second) - val.begin() + 1;
        }
        sort(intv + 1, intv + n + 1);
        int val_n = (int)val.size();
        int cnt = 0;
        init();
        for (int i = 1; i <= n; i++) {
            int id = upper_bound(intv + 1, intv + i, make_pair(intv[i].second - 1, INF)) - intv;
            int u = get(id), v = get(i);
            if (u != v) pa[u] = v;
            else cnt += 1;
            pref[i] = cnt;
        }
        for (int i = n; i >= 1; i--) {
            most_left[i] = upper_bound(intv + 1, intv + i + 1, make_pair(intv[i].second - 1, INF)) - intv;
            if (i < n) most_left[i] = min(most_left[i], most_left[i + 1]);
        }
        init(), cnt = 0;
        sort(intv + 1, intv + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            int id = upper_bound(intv + 1, intv + i + 1, make_pair(intv[i].second - 1, INF)) - intv;
            int u = get(id), v = get(i);
            if (u != v) pa[u] = v;
            else cnt += 1;
            suff[n + 1 - i] = cnt;
        }
        sort(intv + 1, intv + n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = INF;
            for (int j = 0; j <= 4 * val_n; j++) {
                t[j] = INF;
            }
        }
        dp[1] = 1;
        update(1, 1, n, intv[1].first, 1);
        for (int i = 2; i <= n; i++) {
            int id = upper_bound(intv + 1, intv + i + 1, make_pair(intv[i].second - 1, INF)) - intv;
            dp[i] = min(i, query(1, 1, val_n, intv[i].second, intv[i].first));
            update(1, 1, val_n, intv[i].first, dp[i]);
        }
        int ans = 1;
        deque<int> Q;
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                ans = max(ans, pref[i - 1]);
                continue;
            }
            int cur = suff[i + 1];
            while(!Q.empty() && intv[Q.front()].first < most_left[i + 1]) Q.pop_front();
            int left_bound = i - 1;
            if (!Q.empty()) left_bound = min(left_bound, intv[Q.front()].first - 1);
            //cout << left_bound << endl;
            ans = max(ans, cur + pref[left_bound]);
            while (!Q.empty() && dp[i] >= dp[Q.front()]) Q.pop_back();
            Q.push_back(i);
        }
        cout << ans << endl;
        for (int i = 0; i <= n + 1; i++) {
            suff[i] = 0;
            pref[i] = 0;
            most_left[i] = 0;
        }
    }
    return 0;
}

/*0
10
4
-1 1
1 1
0 0
0 1

*/