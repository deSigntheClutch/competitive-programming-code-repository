#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n & 1) cout << "yes" << endl;
        else {
            while (n % 2 == 0) n /= 2;
            if (n != 1) cout << "yes" << endl;
            else cout << "no" << endl;
        }    
    }
    return 0;
}