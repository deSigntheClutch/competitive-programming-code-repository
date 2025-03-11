#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;

const int N = 2e5 + 4;
const ll INF = 1e18 + 1;

int n;
int T;
ll a[N], resi[N], resii[N], ans;

bool check(ll x) {
      for (int i = n; i >= 1; i--) resi[i] = 0;

      ll res = 0;
      queue<int> q;
      for (int i = n; i >= 1; i--) {
            if (a[i] >= x) {
                  res += a[i] - x;
            } else {
                  q.push(a[i]);
            }

            //if (x <= 3) cout << res << " " << i << " " << x << " " << q.size() << endl;

            while(res > 0 && !q.empty() && q.front() < x) {
                  int y = q.front();
                  //if (x <= 3) cout << "!! bk = " << y << endl;
                  q.pop();
                  if (res >= x - y) {
                        res -= (x - y);
                  } else {
                        q.push(y + res);
                        res = 0;
                  }
            }

            if (res > 0) {
                  resi[i] = res;
                  res = 0;
            }
      }

      if (!q.empty()) return false;

      else {
            return true;
      }
}


bool check0(ll x, ll base) {

      for (int i = n; i >= 1; i--) resii[i] = 0;

      ll res = 0;
      queue<int> q;
      for (int i = n; i >= 1; i--) {
            if (resi[i] + base < x) {
                  q.push(resi[i] + base);
            } else {
                  res += resi[i] + base - x;
            }
            //if (x <= 3) cout << res << " " << i << " " << x << " " << q.size() << endl;

            while(res > 0 && !q.empty() && q.front() < x) {
                  int y = q.front();
                  q.pop();
                 // if (x <= 3) cout << "!! bk = " << y << endl;

                  if (res >= x - y) {
                        res -= (x - y);
                  } else {
                        q.push(y + res);
                        res = 0;
                  }
            }

            if (res > 0) {
                  resii[i] = res;
                  res = 0;
            }
      }

      bool flag = true;
      for (int i = n; i >= 1; i--) {
            //if (x == 2) cout << resii[i] << " ";
            if (resii[i]) {
                  if (resii[i] > 0) {
                        flag = false;
                  }
            }
      }
      return flag;
}


int main() {
      cin >> T;
      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
            }

            ll l = 1, r = 1e12 + 1, md;
            for (int cs = 0; cs < 50; cs++) {
                  md = (l + r) >> 1;
                  if (check(md)) l = md + 1;
                  else r = md;
            }

            if (!check(l)) {
                  if (check(l - 1)) {

                        //cout << l - 1 << " minimum" << endl;
//                        for (int i = 1; i <= n; i++) {
//                              cout << resi[i] << " ";
//                        }
//                        cout << endl;
                        ll base = l - 1;
                        l = base, r = 1e12 + 1;
                        for (int cs = 0; cs < 50; cs++) {
                              md = (l + r) >> 1;
                              if (check0(md, base)) r = md;
                              else l = md + 1;
                        }

                        cout << l << " " << check0(l - 1, base) << " +++ " << check0(l, base) << endl;
                        cout << l - base << endl;
                  }
            }
      }
      return 0;
}
/*
 *
 1
 4
 4 1 2 3
 */