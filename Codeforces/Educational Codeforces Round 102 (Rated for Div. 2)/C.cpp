#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 3;
const int INF = 1e15;

int n, k;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (n == k) {
            for (int i = 1; i <= n; i++) 
            cout << i << " ";
            cout << endl;
            continue;
        }
        int cnt = n - (1 + 2 * (n - k));
        int pt = 1;
        for (int i = 0; i < cnt; i++) {
            cout << pt++ << " ";
        }

        int bound = pt;
        pt = k;
        for (int i = cnt;; i++) {
            cout << pt-- << " ";
            if (pt < bound) break;
        }
        cout << endl;
    }
    return 0;
}