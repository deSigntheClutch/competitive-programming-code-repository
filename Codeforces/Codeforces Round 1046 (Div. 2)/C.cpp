#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n;
int a[N];
int f[N];
vector<int> pos[N];

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            f[i] = -1;
            pos[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int v = a[i];
            int ps = lower_bound(pos[v].begin(), pos[v].end(), i) - pos[v].begin();
            if (ps + v - 1 < pos[v].size()) {
                int nxt = pos[v][ps + v - 1];
                f[nxt] = max(f[nxt], f[i - 1] + v);
            }
            f[i] = max(f[i], f[i - 1]);
        }
        cout << f[n] << endl;
    }
    return 0;
}
