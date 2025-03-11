#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n, T;
int a[N], a_odd[N], f[N], num2[N];

int pow_mod(int u, int v) {
      int res = 1;
      while (v) {
            if (v & 1) res = (long long) res * u % MOD;
            v >>= 1;
            u = (long long) u * u % MOD;
      }
      return res;
}

// (new, stack top)
bool compareBig(int u, int v) {
      if (num2[u] >= 31) return true;
      return (long long)a_odd[u] * pow_mod(2ll, num2[u]) >= a_odd[v];
}

int main() {
      cin >> T;
      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  int tmp = a[i], cnt = 0;
                  while(tmp % 2 == 0) {
                        tmp /= 2;
                        cnt += 1;
                  }
                  num2[i] = cnt;
                  a_odd[i] = tmp;
            }

            f[1] = a[1];
            stack<int> s;
            s.push(1);

            int ans = a[1];
            for (int i = 2; i <= n; i++) {
                  while (!s.empty() && compareBig(i, s.top())) {
                        int topNum2 = num2[s.top()];
                        num2[i] += topNum2;

                        ans = (ans - (long long)a_odd[s.top()] * pow_mod(2, topNum2) % MOD + MOD) % MOD;
                        ans = (ans + a_odd[s.top()]) % MOD;
                        num2[s.top()] = 0;
                        s.pop();
                  }
                  s.push(i);
                  ans = (ans + (long long)a_odd[i] * pow_mod(2, num2[i]) % MOD + MOD) % MOD;
                  f[i] = ans;
            }

            for (int i = 1; i <= n; i++)
                  cout << f[i] << " ";
            cout << endl;
  }
  return 0;
}

/*
 *

1
10
2 1 10 1 5 5 1 9 2 4
2 3 22 23 28 33 34 55 57 61

1 1 5 1 1 ,5 5,  ,9 1, 32
 57 - 2 + 9
 */