#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[123];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (m == 0) {
            if (sum == 0)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
            continue;
        }
        if (sum == m)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
