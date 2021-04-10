#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int T;
int n, k;

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> ans;
        for (int i = 1; 2 * i <= k; i++) {
            ans.push_back(k - i);
        }
        for (int i = k + 1; i <= n; i++) {
            ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (int x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}