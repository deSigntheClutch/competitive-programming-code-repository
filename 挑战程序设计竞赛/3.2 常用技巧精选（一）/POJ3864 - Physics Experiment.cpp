#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 100 + 10;
const int eps = 1e-7;

int sgn(double u) {
  if(u > eps) return 1;
  else if(u < -eps) return -1;
  else return 0;
}

int n;
double res[N], h, r, t;

double cal(int ti) {
  if(ti < 0) return h;
  double T = sqrt(h / 5);
  int k = (int)(ti / T);
  if(k % 2 == 0) {
    double d = ti - k * T;
    return h - 5 * d * d;
  } else {
    double d = k * T + T - ti;
    return h - 5 * d * d;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> h >> r >> t;
    for(int i = 0; i < n; i++) {
      res[i] = cal(t - i);
    }
    sort(res, res + n);
    for(int i = 0; i < n; i++) {
      printf("%.2f%c", res[i] + 2 * r * i / 100, i == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
