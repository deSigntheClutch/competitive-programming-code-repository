#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int a[N], b[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[1] != a[i]) ans = max(ans, i - 1);
        if (a[i] != a[n]) ans = max(ans, n - i);
    }
    cout << ans << endl;
    return 0;
}