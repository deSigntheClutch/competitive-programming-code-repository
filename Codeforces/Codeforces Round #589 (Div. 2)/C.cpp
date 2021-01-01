#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

bool pr[N];
vector<int> prime;
vector<int> x_list;

int x;
long long n;

int pow_mod(int x, long long t) {
    int res = 1;
    while(t) {
        if (t & 1) res = (long long)res * x % MOD;
        t >>= 1;
        x = (long long) x * x % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> x >> n;

    for (int i = 2; i < N; i++) {
        if (pr[i] == true) continue;
        prime.push_back(i);
        for (int j = 2 * i; j < N; j += i) {
            pr[j] = true;
        }
    }

    for (int i = 0; pr[i] * pr[i] <= x; i++) {
        if (x % pr[i] == 0) {
            x_list.push_back(pr[i]);
        }
        while (x % pr[i] == 0) {
            x /= pr[i];
        }
    }
    if (x != 1) x_list.push_back(x);
    int ans = 1;

    for (int v : x_list) {
        long long tmp = 1;
        while (n / tmp >= v) tmp *= v;
        while(tmp != 1) {
            ans = ((long long)ans * pow_mod(tmp, n / tmp)) % MOD;
            tmp /= v;
        }
    }

    return 0;
}