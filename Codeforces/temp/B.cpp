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

        cout << min(a[0] + a[0], a[0] + a[1]) << endl;
    }
    return 0;
}