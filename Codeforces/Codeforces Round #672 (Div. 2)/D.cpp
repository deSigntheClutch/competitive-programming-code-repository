#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;
const int INF = 1e15;

int n, q;
int a[N];
int to[N], shape[N];  // 0 up, 1 down
bool top[N], bottom[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            top[i] = bottom[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            if (i == 1 && a[i] > a[i + 1]) top[i] = true;
            if (i == 1 && a[i] < a[i + 1]) bottom[i] = true;
            if (i == n && a[i - 1] > a[i]) bottom[i] = true;
            if (i == n && a[i - 1] < a[i]) top[i] = true;

            if (i > 1 && i < n) {
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) top[i] = true;
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) top[i] = true;
                if (a[i] < a[i - 1] && a[i] < a[i + 1]) bottom[i] = true;
            }
        }

        int res = 0;
        int match_top = true;
        queue<int> que;
        for (int i = 1; i <= n; i++) {
            if (match_top) {
                if (top[i]) {
                    res += a[i];
                    while (!que.empty()) {
                        to[que.front()] = i;
                        que.pop();
                    }
                } else {
                    que.push(i);
                }
            } else {
                if (bottom[i]) {
                    res -= a[i];
                    while (!que.empty()) {
                        to[que.front()] = i;
                        que.pop();
                    }
                } else {
                    que.push(i);
                }
            }
        }
        cout << res << endl;
        for (int x, y, i = 1; i <= q; i++) {
            cin >> x >> y;
            swap(a[x], a[y]);
        }
    }
    return 0;
}