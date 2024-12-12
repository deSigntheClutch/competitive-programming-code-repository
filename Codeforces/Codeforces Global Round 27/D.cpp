#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <stack>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n;
int a[N], f[N], num2[N];
long long pre_without_2[N];
int pw[N];

int pow_mod(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) res = (long long) res * u % MOD;
    v >>= 1;
    u = (long long) u * u % MOD;
  }
  return res;
}

bool compareBig(pair<int, int> p, pair<int, int> q) {
	int x = p.first, y = p.second;
  int xx = q.first, yy = q.second;

	if (xx >= 31) return true;

  if (yy > y)
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
      pw[i] = pw[i - 1] * 2 % MOD;
  }

  int T;
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
      pre_without_2[i] = pre_without_2[i - 1] + tmp;
    }

    f[1] = a[1];
    stack<pair<int, int>> s;
    s.push(make_pair(num2[1], 1));

    long long ans = 0;
    for (int i = 2; i <= n; i++) {
      int cur2 = num2[i];
			while (s.size() > 0 && compareBig(s.top(), make_pair(cur2, i))) {
        cur2 += s.top().first;
        s.pop();
			}
      f[i] = ans pre_without_2[i - 1] - pre_without_2[(s.size() == 0)? 0 : s.top().second - 1] + pow_mod(2, cur2);
      cout << f[i] << " ";
      s.push(make_pair(cur2, a[i]));
    }

    for (int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << endl;
  }
  return 0;
}
