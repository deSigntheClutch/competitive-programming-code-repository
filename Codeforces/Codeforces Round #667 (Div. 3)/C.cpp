#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 1e5 + 5;
const int INF = 1e9 + 5;

int T;
int n, m;
int a[N];
int x, y;

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        int max_an = INF, kgap = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                a[i] = x;
                a[j] = y;
                if ((y - x) % (j - i)) continue;
                int gap = (y - x) / (j - i);
                a[1] = x - gap * (i - 1);
                if (a[1] <= 0) continue;
                //cout << a[1] << " ";
                for (int k = 2; k <= n; k++) {
                    a[k] = a[1] + gap * (k - 1);
                    //cout << a[k] << " ";
                }
                if (a[n] > 1000000000) continue;
                if (max_an > a[n]) {
                    max_an = a[n];
                    kgap = gap;
                }
            }
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(max_an);
            max_an -= kgap;
        }
        reverse(v.begin(), v.end());
        for (int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}
