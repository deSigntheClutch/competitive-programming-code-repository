#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    if (c <= a + b) cout << c + b << endl;
    else if (c >= a + b + 1) cout << a + b + b + 1 << endl;
    else cout << a + b + b << endl;
    return 0;
}