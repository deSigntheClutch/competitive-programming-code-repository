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

char t[4] = {'R', 'Y', 'B', 'G'};
int vis[300];
string s;
int cnt[300];
char pos[400];

int main() {
  cin >> s;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] != '!') {
      vis[s[i]] = (i % 4 + 1);
      pos[i % 4 + 1] = s[i];
    }
  }
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '!') {
      cnt[pos[i % 4 + 1]]++;
    }
  }
  printf("%d %d %d %d\n", cnt['R'], cnt['B'], cnt['Y'], cnt['G']);
  return 0;
}
