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

string s;
int pos[1234];

int main() {
  memset(pos, 0x3f, sizeof pos);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if(pos[s[i]] > 10000) pos[s[i]] = i + 1;
  }
  for(int i = 'b'; i <= 'z'; i++) {
    if(pos[i - 1] > pos[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}

