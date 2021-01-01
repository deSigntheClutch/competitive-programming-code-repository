#include <bits/stdc++.h>

using namespace std;

const long long INF = 7e18 + 10;

long long n, m;

bool check(long long t) {
  long long res = 0;
  if(INF / t < t - 1) return true;
  res = t * (t - 1) / 2 + t + m;
  return res >= n;
}

int main() {
  cin >> n >> m;
  if(m >= n) {
    cout << n << endl;
    return 0;
  }
  long long l = 1, r = 1e18, md;
  for (int cs = 0; cs < 100; cs++) {
    md = (l + r) >> 1;
    if(check(md)) r = md;
    else l = md + 1;
  }
  cout << md + m << endl;
  return 0;
}
