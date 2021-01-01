#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int a[N], b[N];
int n;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        int mn = a[1];
        bool flag = true;
        b[1] = a[1];
        for (int i = 2; i <= n; i++) {
            b[i] = min(mn, a[i] - (a[i - 1] - b[i - 1]));
            if (b[i] < 0) flag = false;
            mn = min(mn, b[i]);
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

/*

6
4
1 1 1 1
4
8 9 9 1
3
1 2 1
5
11 7 9 6 8
5
1 3 1 3 1
4
5 2 1 10

5
5
3 2 4 2 3
6
3 2 4 2 5 3
7
5 7 6 7 6 7 5
*/
