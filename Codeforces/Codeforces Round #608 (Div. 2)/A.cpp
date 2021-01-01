#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    int a, b, c, d , e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (min(b, c) + a <= d) {
        cout << e * (a) + f * min(b, c) << endl;
    } else {
        if (e > f) {
            if (d >= a) {
                cout << (d-a)*f + a * e << endl;
            } else {
                cout << d * e << endl;
            }
        } else {
            if (d >= min(b, c)) {
                cout << (d-min(b, c))*e + min(b, c) * f << endl;
            } else {
                cout << d * f << endl;
            }
        }
    }
    return 0;
}