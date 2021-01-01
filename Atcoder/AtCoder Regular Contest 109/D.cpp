#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <set>
#define int long long
using namespace std;

int x[3], y[3];

struct Box {
    int x, int y;
    int crit[2];
    Box(int a, int b, int c, int d, int e, int f) {
        if (a == c) crit[0] = a;
        else if (a == e) crit[0] = a;
        else if (c == e) crit[0] = c;

        if (b == d) crit[1] = b;
        else if (b == f) crit[1] = b;
        else if (d == f) crit[1] = d;
        x = min(min(a, c), e);
        y = min(min(b, d), f);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; i++) {
            cin >> x[i] >> y[i];
        }
        Box end = Box(x[0], y[0], x[1], y[1], x[2], y[2]);
        Box start = Box(0, 0, 1, 0, 0, 1);
        // except (+, +) ans += 1
        // (x, x) => x + x
    }
    return 0;
}