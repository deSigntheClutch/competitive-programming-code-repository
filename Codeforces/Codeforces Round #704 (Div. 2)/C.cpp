#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;

int T;
int n, m;
string s, t;
int from_left[N], from_right[N];
int sum_left[N], sum_right[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s >> t;

    int pt = 0;
    for (int i = 0; i < n; i++)  {
        if  (t[pt] == s[i]) {
            from_left[pt++] = i;
        }
    }

    pt = m - 1;
    for (int i = n - 1; i >= 0; i--)  {
        if  (t[pt] == s[i]) {
            from_right[pt--] = i;
        }
    }

    int ans = 1;

    for (int i = 1; i < m; i++) {
        sum_left[i] = max(sum_left[i - 1], from_left[i] - from_left[i - 1]);
    }
    ans = max(ans, sum_left[m - 1]);

    for (int i = m - 2; i >= 0; i--) {
        sum_right[i] = max(sum_right[i + 1], from_right[i] - from_right[i + 1]);
    }
    ans = max(ans, sum_right[0]);

    //cout << ans << endl;
    for (int i = 1; i < m; i++) {
        //cout << from_right[i] << " " << from_left[i - 1] << endl;
        ans = max(ans, max(from_right[i] - from_left[i - 1], max(sum_left[i - 1], sum_right[i])));
    }
    cout << ans << endl;
}