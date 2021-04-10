#include <bits/stdc++.h>
using namespace std;

int ans[3] = {2, 16, 32};
int n;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n >= 4)
            cout << 4 << endl;
        else
            cout << ans[n - 1] << endl;
    }
    return 0;
}