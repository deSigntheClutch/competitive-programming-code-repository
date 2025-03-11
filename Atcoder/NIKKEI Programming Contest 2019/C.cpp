#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

int A[N], B[N];
pair<int, int> p[N];
int n;

int main() {
      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> A[i] >> B[i];
            p[i] = make_pair(A[i] + B[i], i);
      }
      sort(p + 1, p + 1 + n);

      long long sum = 0;

      for (int i = n; i >= 1; i--) {
            if ((n - i) % 2 == 0) {
                  //cout << A[p[i].second] << endl;
                  sum += A[p[i].second];
            } else {
                  //cout << B[p[i].second] << endl;
                  sum -= B[p[i].second];
            }
      }
      cout << sum << endl;
      return 0;
}