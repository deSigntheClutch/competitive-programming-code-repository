#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

int a, b, c, d;
bool n_prime[N];
bool is_bad[N];
bool parity[N];

long long solve(int l, int r) {
    long long res = 0;
    for (int i = 2; i < 1e7 + 1; i++) {
        if (is_bad[i] == true) continue;
        int sig = 2 * (parity[i] == 1) - 1;
        res += sig * (long long) (l / i) * (r / i);
    }
    return (long long) l * r - res;
}

void sieve() {
    for (int i = 2; i < 1e7 + 1; i++) {
        if (n_prime[i]) continue;
        parity[i] ^= 1;
        for (int j = 2 * i; j < 1e7 + 1; j += i) {
            n_prime[j] = true;
            parity[j] ^= 1;
        }
        if ((long long)i * i >= (long long)1e7 + 1) continue;
        for (int j = i * i; j < 1e7 + 1; j += (i * i)) {
            is_bad[j] = true;
        }
    }
}

int main() {
    sieve();
    cin >> a >> b >> c >> d;
    cout << solve(b, d) - solve(b, c - 1) - solve(a - 1, d) + solve(a - 1, c - 1) << endl;
    return 0;
}