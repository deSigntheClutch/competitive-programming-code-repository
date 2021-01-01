#include <bits/stdc++.h>
using namespace std;

long long a, b;

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    cout << "YES" << endl;
    for (long long i = a; i <= b; i += 2) {
        cout << i << " " << i + 1 << endl; 
    }
    return 0;
}
