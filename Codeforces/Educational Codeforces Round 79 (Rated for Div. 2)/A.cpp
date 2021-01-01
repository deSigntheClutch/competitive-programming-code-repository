//g++ -std=c++14 B.cpp -o b && ./b
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
long long a, b, c;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (c > a + b + 1 || b > c + a + 1 || a > c + b + 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}