#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
string s, t;
int vis[N];

int cal(int pre) {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
        if ((pre ^ (s[i] - '0')) == i % 2) {
            vis[i] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) continue;
        int pt = i;
        while (pt < n && vis[pt] == 1) pt += 1;
        i = pt - 1;
        cnt += 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        int ans = 99999999;
        ans = min(ans, cal(0));
        ans = min(ans, cal(1));
        cout << ans << endl;
    }
    return 0;
}
