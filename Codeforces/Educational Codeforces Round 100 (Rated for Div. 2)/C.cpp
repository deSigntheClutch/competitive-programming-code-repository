#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

#define int long long

using namespace std;

const int N = 1e5 + 5;

int t[N], x[N];
int n;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t[i] >> x[i];
        }
        t[n] = 1e10;
        x[n] = 0;
        int ans = 0;
        int start = 0, end = -1;
        int task = -1;
        int est = -1;
        int dir = 0;

        for (int i = 0; i < n; i++) {
            if (task != -1) {
                if (t[i] - t[task] >= est) {
                    task = -1;
                    start = end;
                }
            }

            if (task == -1) {
                task = i;
                est = abs(start - x[i]);
                end = x[i];
                if (start > x[task])
                    dir = -1;
                else
                    dir = 1;
            }

            if (dir == 1) {
                int start_x = start + dir * (t[i] - t[task]);
                int end_x = start + dir * min(est, t[i + 1] - t[task]);
               // cout << start_x << " 00 " << end_x << " " << x[i] << endl;
                if (start_x <= x[i] && end_x >= x[i]) {
                  //  cout << " i " << endl;
                    ans += 1;
                }
            } else {
                int start_x = start + dir * (t[i] - t[task]);
                int end_x = start + dir * min(est, t[i + 1] - t[task]);
               // cout << start_x << " " << end_x << endl;
                if (start_x >= x[i] && end_x <= x[i]) {
               //     cout << " i1 " << endl;
                    ans += 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
1
3
1 5
2 4
10 -5
 */