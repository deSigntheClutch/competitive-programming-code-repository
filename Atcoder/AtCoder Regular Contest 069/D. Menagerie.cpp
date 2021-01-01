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

int n, nom[N];
char str[N];

bool check(int u) {
  if (str[u] == 'o') {
    if (nom[u] == 1) {
      return nom[(u + 1) % n] == nom[(u - 1 + n) % n];
    } else {
      return nom[(u + 1) % n] != nom[(u - 1 + n) % n];
    }
  } else {
    if (nom[u] == 0) {
      return nom[(u + 1) % n] == nom[(u - 1 + n) % n];
    } else {
      return nom[(u + 1) % n] != nom[(u - 1 + n) % n];
    }
  }
}

int main() {
  scanf("%d%s", &n, str);
  for (int t1 = 0; t1 < 2; t1++) {
    for (int t2 = 0; t2 < 2; t2++) {
      memset(nom, -1, sizeof nom);
      nom[0] = t1, nom[1] = t2;
      for (int j = 1; j < n - 1; j++) {
        if (str[j] == 'o') {
          if (nom[j] == 0) {
            nom[j + 1] = nom[j - 1] ^ 1;
          } else {
            nom[j + 1] = nom[j - 1];
          }
        } else {
          if (nom[j] == 1) {
            nom[j + 1] = nom[j - 1] ^ 1;
          } else {
            nom[j + 1] = nom[j - 1];
          }
        }
      }
      if (check(n - 1) && check(0)) {
        for (int i = 0; i < n; i++) {
          printf("%c", (nom[i] == 1 ? 'S' : 'W'));
        }
        puts("");
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}

