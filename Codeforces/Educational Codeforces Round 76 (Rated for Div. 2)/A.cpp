#include <bits/stdc++.h>
using namespace std;

int n, x, a, b;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> x >> a >> b;
        if (a > b) swap(a, b);
        if (a - 1 + n - b >= x) cout << abs(a - b) + x << endl; 
        else cout << n - 1 << endl;
    }
    return 0;
}