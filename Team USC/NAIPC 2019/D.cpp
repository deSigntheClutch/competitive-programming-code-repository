#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, q, p;

ll gcd(ll x, ll y) {
    return (y == 0) ? x : gcd(y, x % y);
} 

ll solve(ll x, ll y, ll m) {
    long long res = 0;
    // x > y -> x < y
    res += m * (m + 1) / 2 * (x / y);
    ll r = x % y;
    if (r == 0) return res;
    // calculate f(m) which is how many 'i's get p*i/q no less than m
    // f(m) = n - ceil(p * m / q) = n - (floor() + (p * m % q != 0) )
    res += m * ((r * m) / y) - solve(y, r, (r * m) / y);
    return res;
}

int main() {
    int N = 30;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < N; i++) {
        sum1 += floor(3.0 * i / 5);
        sum2 += ceil(3.0 * i / 5);
    }
    cout << sum1 << " " << sum2 << " " << N - N / 5 << endl;
    int T;
    cin >> T;
    while (T--) {
        cin >> p >> q >> n;
        ll _gcd = gcd(p, q);
        cout << n * (n + 1) / 2 * p - q * solve(p / _gcd, q / _gcd, n) << endl;
    }
}