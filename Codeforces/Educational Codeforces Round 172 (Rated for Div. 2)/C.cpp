#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
const int INF = 1e9 + 1;

int T, n;
ll k;
string s;




int main() {
      cin >> T;
      while (T--) {
            cin >> n >> k >> s;

            priority_queue<int> Q;

            int sum = 0;
            for (int i = 0; i < n; i++) {
                  sum += (s[i] == '0') ? -1 : 1;
                  Q.push(sum);
            }

            int ans = 1;
            while (!Q.empty() && Q.top() > 0) {
                  k -= Q.top();
                  Q.pop();
                  if (k <= 0) {
                        break;
                  }
            }
            cout << (k > 0) ? an<< endl;
      }
}
