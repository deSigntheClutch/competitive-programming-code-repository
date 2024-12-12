#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

int INF = 1e9 + 1;
const int N = 3e5 + 19;
const int M = 1e7 + 2;

int T;
int n;
long long c;
string s;
int a[N];

long long cal() {
  int sum0 = 0, sum1 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] & 1) sum1 += 1;
    else sum0 += 1;
  }

  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    int t = a[i] & 1;
    if (t) {
      cnt += sum1;
      sum1 -= 1;
    } else {
      cnt += sum0;
      sum0 -= 1;
    }
  }

  return cnt;
}

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    long long sum = (c * c + 3ll * c + 2ll) / 2;
    for (int i = 1; i <= n; i++) {
      sum -= (a[i] / 2 + 1);
    }

    for (int i = 1; i <= n; i++) {
      sum -= (c - a[i] + 1);
    }

    cout << sum + cal() << endl;
  }
  return 0;
}
