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

using namespace std;

const int N = 1e5 + 5;

int n;

int main() {
    ios::sync_with_stdio(false);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a - b <= 1 && a - b >= 0) cout << x << endl;
    else if (a - b > 1) {
        cout << min(x + (a - b - 1) * y, (a - b - 1) * 2 * x + x) << endl;
    }
    else {
        cout << min((b - a) * y + x, (b - a) * 2 * x + x) << endl;
    }
}