#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 3;
const int INF = 1e15;

int n, k;
int l[N];
int sum[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            if (l[i] > k) flag = true;
        }
        if (!flag) {
            cout << "YES" << endl;
            continue;
        }
        bool find = false;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (l[i] + l[j] <= k) {
                    find = true;
                }
            }
        }
        if (find) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}