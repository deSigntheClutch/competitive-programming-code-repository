#include <bits/stdc++.h>
using namespace std;

#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right

const int N = 2e5 + 5;
const int MAX = 1e9 + 7;

int n, k;
int a[N];
int t[N << 2], idx[N << 2];
set<int> app[N];
set<int> pos;

void push_up(int rt) {
      t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
      if (t[rt << 1] <= t[rt << 1 | 1]) {
            idx[rt] = idx[rt << 1];
      } else {
            idx[rt] = idx[rt << 1 | 1];
      }
}

pair<int, int> query(int rt, int left, int right, int l, int r) {
      if (l == left && r == right) {
            return {t[rt], idx[rt] };
      }
      if (mid >= r) {
            return query(lson, l, r);
      } else if (mid < l) {
            return query(rson, l, r);
      } else {
            return min(query(lson, l, mid), query(rson, mid + 1, r));
      }
}

void update(int rt, int left, int right, int id, int val) {
      if (id == left && left == right) {
            t[rt] = val;
            idx[rt] = id;
            return;
      }
      if (mid >= id)
            update(lson, id, val);
      else
            update(rson, id, val);
      push_up(rt);
}

int main() {
      cin >> n >> k;
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            app[a[i]].insert(i);
      }

      for (int i = 1; i <= k; i++) {
            pos.insert(*app[i].rbegin());
      }

      for (int i = 1; i <= n; i++) {
            update(1, 1, n, i, a[i]);
      }

      vector<int> ans;

      int lb = 1;
      for (int i = 1; i < k; i++) {
            auto l_item = *pos.begin();
            cout << lb << " x " << l_item << endl;
            auto [x, y] = query(1, 1, n, lb, l_item);

            cout << x << " ? " << y << endl;
            for (auto z : app[x]) {
                  pos.erase(z);
            }
            ans.push_back(x);
            lb = min(l_item + 1, *app[x].rbegin() + 1);
      }
      ans.push_back(a[*pos.begin()]);
      for (auto x : ans) cout << x << " ";
      cout << endl;
      return 0;
}