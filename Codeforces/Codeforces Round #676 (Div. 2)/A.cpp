#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
       int a, b;
       cin >> a >> b;
       cout << (a ^ b) << endl;
    }
    return 0;
}
