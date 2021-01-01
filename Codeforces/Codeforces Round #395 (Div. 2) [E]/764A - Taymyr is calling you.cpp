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

const int N = 1e4 + 10;

int n, m, z, cnt;
int vis[N];

int main() {
  cin >> n >> m >> z;
  for (int i = 1; i * n <= z; i++) {
    vis[i * n] = 1;
  }
  for (int i = 1; i * m <= z; i++) {
    if(vis[i * m] == 1) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

