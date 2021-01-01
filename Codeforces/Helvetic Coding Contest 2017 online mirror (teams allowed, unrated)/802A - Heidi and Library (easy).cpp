#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;

int n, k;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
	cin >> a[i];
  }
  set<int> s;
  for (int i = 1; i <= n; i++) {
	if (s.size() < k) {
      s.insert(a[i]);
	  continue;   
	}

  }
  return 0;
}
