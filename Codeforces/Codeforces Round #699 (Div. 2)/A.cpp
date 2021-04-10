#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string s;
        int x, y;
        cin >> x >> y >> s;
        int a = 0, b = 0, c = 0, d = 0;
        for (char h : s) {
            if (h == 'U') a++;
            if (h == 'D') b++;
            if (h == 'L') c++;
            if (h == 'R') d++;
        }
        //cout  << a << " " << b << ' ' <<c << " " << d << endl;
        if ((y >= -b && y <= a) && (x >= -c && x <= d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}