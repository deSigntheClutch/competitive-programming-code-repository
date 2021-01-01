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

ll n;
string s;

ll cal(string t) {
  ll l = t.length();
  ll res = 0, base = 1;
  for (int i = 0; i < l; i++) {
    res += base * (ll)(t[i] - '0');
    base *= 10ll;
  }
  return res;
}

int main() {
  cin >> n;
  cin >> s;
  if(s.length() == 1 && s[0] == '0'){
    cout << 0 << endl;
    return 0;
  }
  reverse(s.begin(), s.end());
  int l = s.length();
  ll base = 1;
  ll ans = 0;
  for (int i = 0; i < l; i++) {
    string str = "";
    str += s[i];
    int pt = i;
    while (cal(str) < n && pt < l - 1 && pt - i + 1 <= 18) { // Overflow ll act len < log10(n)
      pt++;
      str += s[pt];
    }
    string tmp;
    if (cal(str) >= n) {
      tmp = "";
      for (int ii = 0; ii < str.length() - 1; ii++) {
        tmp += str[ii];
      }
    } else {
      tmp = str;
    }
    ans += cal(tmp) * base;
    base *= n;
    if(cal(str) >= n){
      pt--;
      while(s[pt] == '0') pt--;
    }
    else{
      while(s[pt] == '0') pt--;
    }
    i = max(i, pt);
  }
  cout << ans << endl;
  return 0;
}
