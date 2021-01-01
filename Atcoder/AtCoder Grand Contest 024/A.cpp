#include <bits/stdc++.h>
using namespace std;

long long a, b, c, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cin >> k;
    cout << ((k & 1) ? (b - a) : (a - b)) << endl;
    return 0;
}