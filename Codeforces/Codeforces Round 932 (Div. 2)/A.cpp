#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

int INF = 1e9 + 1;
const int N = 3e5 + 19;
const int M = 1e7 + 2;

int T;
int n;
string s;


int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s;

    string rs = s;

    reverse(rs.begin(), rs.end());

    if (rs < s) {
      if (n & 1) {
        cout << rs << endl;
      } else {
        cout << rs + s << endl;
      }
    } else {
      if (n & 1) {
        cout << s + rs << endl;
      } else {
        cout << s << endl;
      }
    }
  }
  return 0;
}
