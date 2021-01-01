#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const  ld eps= 1e-9;

long long k, d, t;

int main() {
    ios::sync_with_stdio(false);

    cin >> k >> d >> t;
    ld process = 1.0 / t * k + 0.5 / t * ((d - k % d) % d);
    long long ti = k + (d - k % d) % d;

    ld cal = floor(1.0 / process) - 1;
    if ((cal + 1) * process < 1) cal += 1;
    else if ((cal + 2) * process < 1) cal += 2;

    ld chi_left = (1 - cal * process);
    ld left;
    if ((1.0 / t) * k > chi_left) left = chi_left * t;
    else left = k + (chi_left - (1.0 / t) * k) * 2 * t;
    cout << fixed << setprecision(14) << 1.0 * ti * cal + left << endl;
    return 0;
}