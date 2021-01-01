#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
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

const int N = 2e4 + 5;

int a, b, c;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        int ax, ay, az;
        int res = 1000000;
        for (int i = 1; i <= 20000; i++) {
            int min_cost_a = 100000;
            int min_cost_c = 100000;
            int tx, ty, tz;
            for (int base = 1; base * base <= i; base++) {
                if (i % base) continue;
                if (min_cost_a > abs(base - a)) {
                    min_cost_a = abs(base - a);
                    tx = base;
                }
                if (min_cost_a > abs(i / base - a)) {
                    min_cost_a = abs(i / base - a);
                    tx = i / base;
                }
            }
            for (int j = i; j <= 20000; j += i) {
                if (min_cost_c > abs(j - c)) {
                    min_cost_c = abs(j - c);
                    tz = j;
                }
            }
            ty = i;
            if (res > min_cost_a + min_cost_c + abs(b - i)) {
                ax = tx;
                ay = ty;
                az = tz;
                res = min_cost_a + min_cost_c + abs(b - i);
            }
        }
        cout << res << endl;
        cout << ax << " " << ay << " " << az << endl;
    }
    return 0;
}