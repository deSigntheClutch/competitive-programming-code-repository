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

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int now = n;
  priority_queue<int> heap;
  for (int i = 0; i < n; i++) {
    if (a[i] == now) {
      printf("%d", a[i]);
      now--;
      while (!heap.empty() && now == heap.top()) {
        printf(" %d", heap.top());
        heap.pop();
        now--;
      }
    } else {
      heap.push(a[i]);
    }
    printf("\n");
  }
  return 0;
}

