#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;

vector<int> v;
int a[N];
int b[N];
int sumb[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
             cin >> a[i];
            if (a[i] == 2) a[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] == 2) b[i] = -1;
            sumb[i] = sumb[i - 1] + b[i];
        }
        map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += a[i];
            mp[cnt] = i + 1;
        }
        int ans = -1;
        for (int i = 0; i <= n; i++) {
            int left = sumb[n] - sumb[i];
            int max_right = mp[-left];
            if (max_right == 0) continue;
            //cout << max_right << " " << left << " " << i << endl;
            ans = max(ans, max_right - 1 + n - i);
        }
        cout << 2 * n - ans << endl;
    }
    return 0;
}