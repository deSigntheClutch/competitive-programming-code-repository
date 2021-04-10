#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;
const int INF = 1e9 + 10;

int n;
int a[N];
bool hill[N];
bool valley[N];
int sum[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            hill[i] = valley[i] = false;
            sum[i] = 0;
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (i >= 2 && i < n) {
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) hill[i] = true, sum[i] += 1;
                if (a[i] < a[i - 1] && a[i] < a[i + 1]) valley[i] = true, sum[i] += 1;
            }
            //cout << sum[i] << " ";
            sum[i] += sum[i - 1];
        }
        //cout << endl;
        if (n <= 2) {
            cout << 0 << endl;
            continue;
        }
        int ans = INF;
        // cout << sum[n] << endl;
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                if (hill[2] || valley[2]) {
                    ans = min(ans, sum[n] - 1);
                }
            } else if (i == n) {
                if (hill[n - 1] || valley[n - 1]) {
                    ans = min(ans, sum[n] - 1);
                }
            } else {
                int tmp[2] = {a[i - 1], a[i + 1]};
                int xx = a[i];
                int origin = valley[i] + valley[i + 1] + valley[i - 1] + hill[i] + hill[i + 1] + hill[i - 1];
                for (int x = 0; x < 2; x++) {
                    int cnt = 0;
                    a[i] = tmp[x];
                    for (int j = i - 1; j <= i + 1; j++) {
                        if (j - 1 <= 0 || j + 1 > n) continue;
                        if (a[j] > a[j + 1] && a[j] > a[j - 1]) cnt += 1;
                        if (a[j] < a[j + 1] && a[j] < a[j - 1]) cnt += 1;
                    }
                    //cout << i << " " << tmp[x] << " " << origin << cnt << " " << sum[n] << endl;
                    ans = min(ans, sum[n] - origin + cnt);
                }
                a[i] = xx;
            }
        }
        cout << ans << endl;
    }
    return 0;
}