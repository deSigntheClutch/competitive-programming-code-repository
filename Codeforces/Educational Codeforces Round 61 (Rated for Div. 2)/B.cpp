#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;

int n, m;
int a[N];
int q[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> q[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; i++) {
        cout << sum - a[n + 1 - q[i]] << endl;
    }
    return 0;
}
