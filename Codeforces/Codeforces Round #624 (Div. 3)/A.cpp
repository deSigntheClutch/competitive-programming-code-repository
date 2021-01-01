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

const int N = 1e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (a == b) cout << 0 << endl;
        else if ((a < b && a % 2 != b % 2) || (a > b && a % 2 == b % 2)) cout << 1 << endl;
        else if ((a < b && a % 2 == b % 2) || (a > b && a % 2 != b % 2)) cout << 2 << endl;
        else cout << 3 << endl;
    }
    return 0;
}