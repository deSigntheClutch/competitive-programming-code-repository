//g++ -std=c++14 D.cpp -o d && ./d
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const long long MOD = 998244353;

int n;
vector<int> g[N], p[N];

long long pow_mod(long long u, long long v) {
    long long res = 1;
    while (v) {
        if (v & 1) res = res * u % MOD;
        v >>= 1;
        u = u * u % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            g[i].push_back(id);
            p[id].push_back(i);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 1e6 + 1; i++) {
        if (p[i].size() == 0) continue;
        long long cur = (long long)p[i].size() * pow_mod((long long)n, MOD - 2) % MOD;
        long long sum = 0;
        for (int x : p[i]) {
            sum = (sum + pow_mod((long long)g[x].size(), MOD - 2)) % MOD;
        }
        cur = cur * sum % MOD;
        cur = cur * pow_mod((long long)n, MOD - 2) % MOD;
        ans = (ans + cur) % MOD;
    }
    cout << ans << endl;
    return 0;
}