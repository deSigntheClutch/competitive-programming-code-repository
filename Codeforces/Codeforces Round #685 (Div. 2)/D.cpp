#include <bits/stdc++.h>
using namespace std;
#define int long long 

int d, k;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int d, k;
        cin >> d >> k;
        auto limit = [=]() {
            int pt = 0;
            while (2 * pt * pt * k * k <= d * d) pt++;
            return pt - 1;
        }();
        bool flag = ((limit * limit + (limit + 1) * (limit + 1)) * k * k) <= d * d;
        if (flag) cout << "Ashish" << endl;
        else cout << "Utkarsh" << endl;
    }
    return 0;
}
