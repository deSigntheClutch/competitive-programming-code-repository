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

int n;
const int INF = 3e18;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int l = 1, r = 1e18 + 5, md;
    for (int cs = 0; cs < 65; cs++) {
        md = (l + r) >> 1;
        if (INF / (md + 1) <= md) r = md;
        else {
            if (md * (md + 1) <= 2 * (n + 1))
                l = md + 1;
            else
                r = md;
        }
        //cout << md << " " << md * md << endl;
    }
    cout << n - md + 2 << endl;
    return 0;
}