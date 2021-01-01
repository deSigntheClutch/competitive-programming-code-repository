#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int N = 1e5 + 5;

int T;
int n, s;
int a[N];

int sum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int cal(int x, int limit) {
    if (sum(x) <= limit) return 0;
    for (int bit = 1; bit <= (int)1e18; bit *= 10) {
        int dsum = sum(x);
        int rem = x % bit;
        int cur = dsum - sum(rem) + 1;
        if (cur <= s) {
            int target = (bit - rem) % bit;
            return target;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        cout << cal(n, s) << endl;
    }
    return 0;
}
