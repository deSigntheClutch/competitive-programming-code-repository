#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long total;
long long k, n;
map<long long, long long> m;

void dfs(long long u, long long num) {
  if(u <= 0) return ;
  m[u] += num;
  total += num;
  long long a = (u - 1) / 2, b = u - 1 - (u - 1) / 2;
  if(a == b) {
    dfs(a, num * 2);
  } else {
    dfs(b, num);
    dfs(a, num);
  }
}

int main() {
  freopen("C-small-2-attempt0.in", "r", stdin);
  freopen("C-small-2-attempt0.out", "w", stdout);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int cs = 1; cs <= T; cs++) {
    cin >> n >> k;
    m.clear();
    total = 0;
    dfs(n, (long long)1);
    long long sum = 0;
    long long ans = 0;
    for(map<long long, long long>:: iterator it = m.begin(); it != m.end(); it++) {
      total -= it->second;
      if(total < k) {
        long long u = it->first;
        cout << "Case #" << cs << ": " << u - 1 - (u - 1) / 2 << " " << (u - 1) / 2<< endl;
        break;
      }
    }
  }
  return 0;
}

