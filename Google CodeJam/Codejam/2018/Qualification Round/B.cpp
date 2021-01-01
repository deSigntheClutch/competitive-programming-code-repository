#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int n;
int a[N];
vector<int> V[2];

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> n;
    V[0].clear(), V[1].clear();
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      V[i % 2].push_back(tmp);
    }
    sort(V[0].begin(), V[0].end());
    sort(V[1].begin(), V[1].end());
    bool flag = true;
    for(int i = 0; i < n; i++) {
      a[i] = V[i%2][i/2];
      if(a[i] < a[i - 1]){
        cout << i - 1 << endl;
        flag = false;
        break;
      }
    }
    if(flag) cout << "OK" << endl;
  }
  return 0;
}
