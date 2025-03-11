#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 11092019;
typedef long long ll;

int n;
int sum = 0;
map<char, int> m;
int f[N];
string s;

int main() {
      cin >> s;

      n = s.length();
      long long ans = 0;
      for (int i = 0; i < n; i++) {

            f[i] = 1;
            for (int j = 'a'; j <= 'z'; j++) {
                  if (j == s[i]) continue;
                  f[i] = (ll)(m[j] + 1) * f[i] % MOD;
            }

            m[s[i]] += 1;
            sum += 1;
            ans = (ans + f[i]) % MOD;
      }

      cout << (ans + 1) % MOD << endl;
      return 0;
}
