#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 4;

int m, n;
int rem[N];
signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    int a = 1, b = 1, per = 10 % m;
    for (int i = 0; i < n; i++) {
        rem[i] = a - b / m
    }
    return 0;
}