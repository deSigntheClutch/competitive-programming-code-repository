#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 5;

int dp_left[2][N];  // 0 LR, 1 RL
int dp_right[2][N];

int n;
string s;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        for (int i = 0; i <= n + 1; i++) {
            dp_left[0][i] = dp_left[1][i] = 0;
            dp_right[0][i] = dp_right[1][i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            if (i > 0) {
                dp_left[0][i] = (s[i - 1] == 'L');  // LR
                dp_left[1][i] = (s[i - 1] == 'R');  /// RL
                if (dp_left[0][i] == 1) dp_left[0][i] = dp_left[1][i - 1] + dp_left[0][i];
                if (dp_left[1][i] == 1) dp_left[1][i] = dp_left[0][i - 1] + dp_left[1][i];
            }
        }

        for (int i = n; i >= 0; i--) {
            if (i < n) {
                dp_right[0][i] = (s[i] == 'L');  // LR
                dp_right[1][i] = (s[i] == 'R');  /// RL
                if (dp_right[0][i] == 1) dp_right[0][i] = dp_right[1][i + 1] + dp_right[0][i];
                if (dp_right[1][i] == 1) dp_right[1][i] = dp_right[0][i + 1] + dp_right[1][i];
            }
        }

        for (int i = 0; i <= n; i++) {
            cout << dp_left[0][i] + dp_right[1][i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}