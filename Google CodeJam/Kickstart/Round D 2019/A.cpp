#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cin >> n >> q;
        set<int> odd;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (__builtin_popcount(a[i]) & 1) odd.insert(i);
        }
        cout << "Case #" << cs << ":";
        for (int i = 0; i < q; i++) {
            int u, t;
            cin >> u >> t;
            if (__builtin_popcount(t) & 1) {
                odd.insert(u);
            } else if (__builtin_popcount(t) ^ 1) {
                odd.erase(u);
            }
            a[u] = t;
            if ((int)odd.size() & 1) {
                cout << " " << max(n - 1 - *odd.begin(), *odd.rbegin());
            } else {
                cout << " " << n;
            }
        }
        cout << endl;
    }
    return 0;
}
