//g++ -std=c++14 B.cpp -o b && ./b
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
long long t;
long long a, b;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        a += t - t / 2;
        b += t / 2;
        swap(a, b);
    }
    cout << min(a, b) << endl;
    return 0;
}