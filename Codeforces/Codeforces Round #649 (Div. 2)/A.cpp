#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;


int n, x;
int a[N];
int sum[N];
int smallest_id_not_equal_to[N];
vector<int> val[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 0; i < x; i++) val[i].clear();
        val[0].push_back(0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] %= x;
            sum[i] = (sum[i - 1] + a[i]) % x;
           // cout << sum[i] << endl;
            val[sum[i]].push_back(i);
        }
        for (int i = 0; i < x; i++) {
            int cur = 0;
            int ans = -1;
            for (int y : val[i]) {
                //cout << y << " ! ";
                if (y == cur) {
                    cur += 1;
                } else {
                    ans = cur;
                    break;
                }
            }
            //cout << i << " : " << smallest_id_not_equal_to[i] << " " << cur << " " << ans << endl;
            smallest_id_not_equal_to[i] = ans;
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            int value = sum[i];
            //cout << smallest_id_not_equal_to[value] << endl;
            if (smallest_id_not_equal_to[value] == -1) continue;
            ans = max(ans, i - smallest_id_not_equal_to[value]);
        }
        cout << ans << endl;
    }
    return 0;
}