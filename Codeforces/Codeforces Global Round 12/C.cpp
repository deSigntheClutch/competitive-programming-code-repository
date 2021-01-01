#include <bits/stdc++.h>
using namespace std;

const int M = 323;

int n;
string s[M];
int cnt[3];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            for (int j = 0; j < n; j++) {
                cnt[(i + j) % 3] += ('X' == s[i][j]);
            }
        }
        pair<int, int> ans = {1e9, -1};
        for (int i = 0; i < 3; i++) {
            ans = min(ans, {cnt[i], i});
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 3 == ans.second && s[i][j] == 'X') {
                    cout << 'O';
                } else {
                    cout << s[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
