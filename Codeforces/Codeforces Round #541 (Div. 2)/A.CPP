#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << x1 + y1 + y1 + x2 + y2 + y2 + 4 + max(0, x1 - x2) << endl;
    return 0;
}