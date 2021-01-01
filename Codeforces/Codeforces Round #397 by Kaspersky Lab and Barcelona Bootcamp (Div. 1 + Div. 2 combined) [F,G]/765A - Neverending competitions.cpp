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

map<string, int> m, q;
int n;
string str;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  cin >> str;
  for (int i = 1; i <= n; i++) {
    string s, t = "";
    cin >> s;
    for (int j = 0; j < 3; j++) {
      t += s[j];
    }
    if (t == str) m[str]++;
    t = "";
    for (int j = 5; j < 8; j++) {
      t += s[j];
    }
    if (str == t) q[str]++;
  }
  if(q[str] == m[str]) {
    cout << "home" << endl;
  }
  else {
    cout << "contest" << endl;
  }
  return 0;
}

