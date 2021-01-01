#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 4;

int n, k;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int ans = n;
        for (auto val : s) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                b[i] = a[i];
            }
            for (int i = 1; i <= n; i++) {
                if (b[i] != val) {
                    i = i + k - 1;
                    cnt += 1;
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
