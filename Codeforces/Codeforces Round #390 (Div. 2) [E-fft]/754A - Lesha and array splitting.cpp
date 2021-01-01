#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const int N = 100 + 10;

int a[N], n;
int sum[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = a[i];
    sum[i] += sum[i - 1];
  }
  if (sum[n] != 0) {
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << 1 << " " << n << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (sum[i] != 0) {
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << 1 << " " << i << endl;
      cout << i + 1 << " " << n << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
