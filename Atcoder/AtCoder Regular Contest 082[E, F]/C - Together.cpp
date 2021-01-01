#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }
    int ans = 1;
    for (int X = 0; X <= N; X++) {
        int res = 0;
        for (int i = -1; i <= 1; i++) {
            if (X + i >= 0 && X + i <= N) {
                res += cnt[X + i];
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}

