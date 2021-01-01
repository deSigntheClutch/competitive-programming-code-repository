#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

int x[N], y[N];
int a,b,c,d;
int p, q, n;
// up down left, right
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        if (y[i] >= q + 1) {
            a += 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (y[i] <= q - 1) {
            b += 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (x[i] <= p - 1) {
            c += 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (x[i] >= p + 1) {
            d += 1;
        }
    }
    cout << max(a, max(b, max(c, d))) << endl;
    if (a == max(a, max(b, max(c, d)))) cout << p << " " << q + 1 << endl;
    else if (b == max(a, max(b, max(c, d)))) cout << p << " " << q - 1 << endl;
    else if (c == max(a, max(b, max(c, d)))) cout << p - 1 << " " << q << endl;
    else cout << p + 1 << " " << q << endl;
    return 0;
}