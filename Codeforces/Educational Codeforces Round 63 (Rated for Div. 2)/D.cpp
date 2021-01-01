#include <bits/stdc++.h>
using namespace std;
#define int long long

const double pi = acos(-1.0);
const int N = 3e5 + 5;

int n, x;
int a[N];
int sum_left[N];
int sum_right[N];
int max_left[N];
int max_right[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> x;
    // solution 1
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    return 0;
    // solution 2
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum_left[i] = sum_left[i - 1] + a[i];
    }
    int cur_min = 0;
    for (int i = 1; i <= n; i++) {
        max_left[i] = max(0ll, sum_left[i] - cur_min);
        cur_min = min(cur_min, sum_left[i]);
    }
    cur_min = 0;
    for (int i = n; i >= 1; i--) {
        sum_right[i] = sum_right[i + 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        max_right[i] = max(0ll, sum_right[i] - cur_min);
        cur_min = min(cur_min, sum_right[i]);
    }
    int ans = 0;
    int cur_max = 0;
    for (int end = 1; end <= n; end++) {
        cur_max = max(cur_max, max_left[end] - x * sum_left[end]);
        int cur = x * sum_left[end] + max_right[end + 1];
        ans = max(ans, cur + cur_max);
    }
    cout << ans << endl;
    return 0;
}
