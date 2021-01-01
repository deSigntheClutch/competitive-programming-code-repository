#include <bits/stdc++.h>
using namespace std;

string a, b, c;

bool related (string a, string b) {
    if (a[1] == b[1] && abs(a[0] - b[0]) <= 2) return true;
    return false;
}

bool related3 (string a, string b, string c) {
    if (a == b && b == c) return true;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (a[0] + 1 == b[0] && b[0] + 1 == c[0] && a[1] == b[1] && a[1] == c[1]) return true;
    return false;
}

int main() {
    cin >> a >> b >> c;
    if (related3(a, b, c)) cout << 0 << endl;
    else if (related(a, b) || related(b, c) || related(a, c)) cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}