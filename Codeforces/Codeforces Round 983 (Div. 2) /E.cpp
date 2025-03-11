#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 1e10 + 1;

int T, n, q;
long long a[N];
long long opeAdd[N], opeMinus[N], ans[N];
long long preAdd[N][2], preMinus[N][2];
vector<long long> v;

bool checkr() {
      for (int i = 0; i < n; i++) {
            v[i] += ans[i] * 2;
            v[(i + 1) % n] += ans[i];
            v[(i + n - 1) % n] += ans[i];
      }

      bool flag = false;
      for (int i = 0; i < n - 1; i++) {
            if (v[i] != v[i + 1]) {
                  flag = true;
            }
      }

      cout << "res-> ";
      for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
      }
      cout << endl;

      return !flag;
}

void test() {

      vector<int> vv;

      for (int i = 0; i < n; i++) vv.push_back(v[i]);
      for (int i = 0; i < n; i++) {
            // opeAdd
            vv[i] += 3*opeAdd[i];
            vv[(i+1)%n] += 3*opeAdd[i];
            for (int j = 0; j < n; j++) {
                  if ((i+1)%n != j && i != j) {
                        vv[j] += 2*opeAdd[i];
                  }
            }

            vv[i] += 1*opeMinus[i];
            vv[(i+1)%n] += 1*opeMinus[i];
            for (int j = 0; j < n; j++) {
                  if ((i+1)%n != j && i != j) {
                        vv[j] += 2*opeMinus[i];
                  }
            }
      }
      cout << "0---=-=";
      for (int i = 0; i < n; i++) {
            cout << vv[i] << " ";
      }
      cout << endl;
}

void print() {
      cout << " A: ";
      for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
      }
      cout << endl;
}

int main() {
      cin >> T;
      while (T--) {
            cin >> n;

            v.clear();
            for (int i = 0; i < n; i++) {
                  ans[i] = 0, opeAdd[i] = 0, opeMinus[i] = 0;
                  preMinus[i][0] = preMinus[i][1] = 0;
                  preAdd[i][0] = preAdd[i][1] = 0;
                  cin >> a[i];
                  v.push_back(a[i]);
            }

            if (n == 1) {
                  cout << 0 << endl;
                  continue;
            }

            for (int i = 0; i < n; i++) {
                  int cur = i;
                  int nxt = (i + 1) % n;

                  if (INF >= a[cur]) {
                        opeAdd[cur] += INF - a[cur];
                        a[nxt] += INF - a[cur];
                        a[cur] = INF;
                  } else {
                        opeMinus[cur] += a[cur] - INF;
                        a[nxt] += INF - a[cur];
                        a[cur] = INF;
                  }

                  // print();
            }

            if (a[0] < INF) {
                  opeAdd[0] += INF - a[0];
                  a[1] += INF - a[0];
                  a[0] = INF;
            }

            int sq = a[1] > a[0] ? 1 : 0;

            for (int i = 0; i < n / 2; i++) {
                  int u = (sq + 1 + 2 * i) % n;
                  int vv = (sq + 2 + 2 * i) % n;
                  opeAdd[u] += a[sq] - a[u];
                  a[u] = a[sq];
                  a[vv] = a[sq];
            }

//            for (int i = 0; i < n; i++) {
//                  cout << opeAdd[i] << " " << opeMinus[i] << endl;
//            }

            for (int i = 0; i < n; i++) {
                  if (i > 0) {
                        preAdd[i][1] += preAdd[i - 1][1], preAdd[i][0] += preAdd[i - 1][0];
                        preMinus[i][1] += preMinus[i - 1][1], preMinus[i][0] += preMinus[i - 1][0];
                  }

                  if (i & 1) {
                        preAdd[i][1] += opeAdd[i];
                        preMinus[i][1] += opeMinus[i];
                  } else {
                        preAdd[i][0] += opeAdd[i];
                        preMinus[i][0] += opeMinus[i];
                  }
            }
            for (int i = 0; i < n; i++) {
                  if (i & 1) {
                        ans[i] = opeAdd[i] + preAdd[i][0] + preAdd[n - 1][1] - preAdd[i][1] +
                                 (i - 1 >= 0 ? preMinus[i - 1][1] : 0) + preMinus[n - 1][0] - preMinus[i][0];
                  } else {
                        ans[i] = opeAdd[i] + preAdd[i][1] + preAdd[n - 1][0] - preAdd[i][0] +
                                 (i - 1 >= 0 ? preMinus[i - 1][0] : 0) + preMinus[n - 1][1] - preMinus[i][1];
                  }
                  cout << ans[i] << " ";
            }
            cout << endl;

            //cout << checkr() << endl;
      }
}
// 8 8 7 -> 8 8 0 -> 8 16 8 -> 15 16 15


//0 1 2 3 4 0 1 2 3 4
//xox o xoxox = left_x + self + right_o | left_o_minus + right_x_minus