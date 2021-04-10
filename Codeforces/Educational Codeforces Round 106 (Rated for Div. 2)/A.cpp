#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 5;

int dp_left[2][N];  // 0 LR, 1 RL
int dp_right[2][N];

int n;
int k1, k2;
int w, b;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k1 >> k2;
        cin >> w >> b;

        int sumw = k1 + k2;
        int sumb = 2 * n - sumw;
        if (sumw & 1) sumw -= 1;
        if (sumb & 1) sumb -= 1;
        if (sumw >= w * 2 && sumb >= b * 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}