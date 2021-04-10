#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

string s;
int dp[N], n;
int to[N][27];
int pre[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();

    int mask = 0;
    fill(pre, pre + 100, n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 'a'; j <= 'z'; j++) {
            to[i][j - 'a'] = pre[j - 'a'];
        }
        mask |= (1 << (s[i] - 'a'));
        dp[i] = dp[i + 1];
        if (mask == (1 << 26) - 1) {
            mask = 0;
            dp[i] += 1;
        }
        pre[s[i] - 'a'] = i;
    }
    cout << dp[0] << endl; // a
    int len = dp[0];
    int pt = 0;
    while (pt < n && dp[pt] == dp[0]) pt += 1;
    if (pt == n) pt += 1;
    cout << pt << endl;
    for (int i = 'a'; i <= 'z'; i++) {
        bool flag = false;
        for (int j = 0; j < pt - 1; j++) {
            if (s[j] == i) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << (char)i;
            for (int i = 0; i < len; i++) {
                cout << 'a';
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}

