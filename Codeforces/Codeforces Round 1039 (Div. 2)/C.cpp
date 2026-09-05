#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN];


int main() {
    int T; cin >> T;

    while (T--) {

        int minx = 1e9 + 1;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {

            if (a[i] >= 2 * minx) {
                flag = false;
            }

            if (a[i] < minx) {
                minx = a[i];
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}