#include <bits/stdc++.h>
using namespace std;

int n, p, q;
int mx = 0;

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a = i, b = n - i;
        if (a >= b) break;
        int g = __gcd(a, b);
        if(g >= 2) continue;
        p = a, q = b;
    }
    cout << p << " " << q << endl;
    return 0;
}
