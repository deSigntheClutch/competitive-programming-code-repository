#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a > b) {
        if (a & 1) a += 1;
        else a /= 2;
        cnt += 1;
    }
    cout << cnt + b - a << endl;
    return 0;
}