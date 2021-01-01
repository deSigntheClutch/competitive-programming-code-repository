#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <memory>
#include <stack>

#define int long long

using namespace std;

const int N = 2e5 + 5;
const int INF = -100000000000000000;

int n, m;
int a[N], b[N];

int _gcd(int x, int y) {
    return x ? _gcd(y % x, x) : y;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int minm = -INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int gcd = INF;
    for (int i = 1; i < n; i++) {
        a[i] = a[i] - a[0];
        if (i == 1) gcd = a[i];
        else gcd = _gcd(gcd, a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (gcd == INF) {
            cout << b[i] + a[0] << " ";
        }
        else {
            cout << __gcd(b[i] + a[0], gcd) << " ";
        }
    }
    cout << endl;
    return 0;
}