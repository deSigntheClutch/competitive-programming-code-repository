#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 1e5 + 5;

int n, m;

int f(int x) {
    if (x == 0) return 0;
    vector<int> digit;
    int mod = x + 1;
    while (x) {
        digit.push_back(x % 10);
        x /= 10;
    }
    int res = 0, base = 1;
    int ans = 1;
    for (int t : digit) {
        res += t * base;
        base *= 10;
        ans = ans * res % mod;
    }
    return ans;
}

int mem[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < m && i < N; i++) {
            mem[i] = f(n);
            n = f(n);
            ans += mem[i];
        }
        cout << ans + max(0ll, m - N) * mem[N - 1] << endl;
    }
    return 0;
}