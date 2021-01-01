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

const int N = 1e5 + 10;
const int B = 320 + 10;

int n, m, total;
int a[N];
vector<int> bar[B];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    bar[i / B].pb(a[i]);
  }
  total = (n - 1) / B;
  for (int i = 0; i <= total; i++) {
    sort(bar[i].begin(), bar[i].end());
  }
  return 0;
}

