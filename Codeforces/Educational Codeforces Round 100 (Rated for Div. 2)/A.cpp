#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <set>
#include <memory>

#define int long long

using namespace std;

const int N = 1e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        int k;
        cin >> a >> b >> c;
        int min_7 = min(a - 1, min(b - 1, c - 1));
        int left = a + b + c - 3;
        int l = 1, r = 1e9, md;
        for (int cs = 0; cs < 32; cs++) {
            md = (l + r) >> 1;
            if (md + (md / 7) * 2 > left) r = md;
            else l = md + 1;
        }
        md--;
        if (md % 7 == 6 && min_7 >= md / 7 && md + 2 * (md / 7) == left) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}