#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;

int n;
int b[N];
pair<int, int> a[N];

int cal() {
  for (int i = 1; i <= 2 * n; i += 2) {
    b[i] = a[i / 2 + 1].first;
    b[i + 1] = a[i / 2 + 1].second;
  }

  int cnt = 0;
  for (int i = 1; i <= n * 2; i++) {
    for (int j = i + 1; j <= n * 2; j++) {
      cnt += (b[i] > b[j]);
    }
  }
  return cnt;
}


bool cmp(pair<int, int> u, pair<int, int> v) {
  return (u.second + u.first) < (v.first + v.second);
}


int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + 1 + n, cmp);
    //cout << cal() << endl;
    for (int i = 1; i <= n; i++) {
      cout << a[i].first << " " << a[i].second << " ";
    }
    cout << endl;
  }
  return 0;
}
