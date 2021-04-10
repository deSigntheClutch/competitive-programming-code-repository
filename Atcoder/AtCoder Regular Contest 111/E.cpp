#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int x, n;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; i++) {
            q.push({a[i], 1});
            sum += a[i];
        }

        while (!q.empty()) {
            auto t = q.front();
            //cout << t.first << endl;
            q.pop();
            if (t.first % x == 0) {
                q.push({t.first / x, x * t.second});
                sum += t.first * t.second;
            } else {
                break;
            }
        }

        cout << sum << endl;
    }
    return 0;
}