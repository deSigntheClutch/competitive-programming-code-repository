#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!flag && a[i] > a[j]) {
                    flag = true;
                    cout << "YES" << endl;
                    cout << 2 << endl;
                    cout << a[i] << " " << a[j] << endl;
                }
            }
        }

        if (!flag) {
            cout << "NO" << endl;
        }
    }
    return 0;
}