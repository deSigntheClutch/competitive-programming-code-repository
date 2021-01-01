#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug0(x) printf("! %d\n", x);
#define debug1(x, a, b) for(int (ii)=(a);(ii)<(b);(ii++)) printf("%d: %d\n", ii, x[ii]);
#define nono(x, ite) for(__typeof((x).begin()) (ite)=(x).begin();(ite)!=(x).end();(ite++))

typedef long long ll;

const int N = 50 + 10;

int n, l;
int a[N], b[N], c[N], d[N];

int main() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if(n == 1) {
    if(a[0] == b[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
  }
  int t1 = a[0], t2 = b[0];
  for (int i = 0; i < n; i++) {
    a[i] -= t1;
    b[i] -= t2;
  }
  for(int i = 0; i < n; i++) {
    if(i == 0){
      c[i] = l - a[n - 1];
      d[i] = l - b[n - 1];
      continue;
    }
    c[i] = a[i] - a[i - 1];
    d[i] = b[i] - b[i - 1];
  }
  bool flag = false;
  for(int i = 0; i < n; i++) {
    bool f = true;
    for(int j = 0; j < n; j++) {
      if(c[j] != d[(i + j) % n]) {
        f = false;
      }
    }
    if(f) flag = true;
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

