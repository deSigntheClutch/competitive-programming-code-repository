#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    long long num = 1;
    long long sum = 0;

    while (n > 1) {
        sum += num;
        num *= 2;
        n /= 2;
    }
    cout << sum + num << endl;
    return 0;
}
