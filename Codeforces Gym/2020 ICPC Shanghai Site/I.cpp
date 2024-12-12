#include "bits/stdc++.h"
using namespace std;

const double pi = acos(-1.0);

double ans;
int n, m;

int main() {
    cin >> n >> m;
    ans = (m == 1) ? 0 : (2 * m + 2 * m * n) * n / 2;
    for (int i = 1; i <= n; i++) {
        double theta = pi * i / m;
        for (int j = i; j <= n; j++) {
            double res = 0;
            for (int p = 1; p <= m - 1; p++) {
                double l1 = theta * p + (j - i);
                double l2 = i + j;
                res += min(l1, l2) * 2;
            }
            res += 2 * j;
            if (j == i)
                ans += res * m;
            else
                ans += res * 2 * m;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}