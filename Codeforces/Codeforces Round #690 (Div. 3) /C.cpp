#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define int long long

using namespace std;

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = INF;
        for (int i = 0; i < (1 << 10); i++) {
            vector<int> digit;
            int cur = 0;
            for (int j = 0; j < 10; j++) {
                if (i >> j & 1) {
                    digit.push_back(j);
                    cur += j;
                }
            }
            if (cur != n) continue;
            if (digit.size() >= 2 && digit[0] == 0) {
                swap(digit[1], digit[0]);
            }
            long long sb = 0;
            for (auto d : digit) {
                sb = sb * 10;
                sb += d;
            }
            ans = min(ans, sb);
        }
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}