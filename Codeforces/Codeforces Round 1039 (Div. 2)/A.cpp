#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n, c;
int a[N];

int main() {
    int T; cin >> T;

    while (T--) {
        cin >> n >> c;
        set<int> x;
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > c) x.insert(i), ans += 1;
        }

        for (int i = 1; i <= n; i++) {
            int tmp = -1;
            int id = -1;
            for (int j = 1; j <= n; j++) {
                if (a[j] <= c && x.find(j) == x.end()) {
                    if (tmp < a[j]) {
                        tmp = a[j];
                        id = j;
                    }
                }
            }
            if (id != -1) {
                x.insert(id);
            } else {
                break;
            }

            for (int j = 1; j <= n; j++) {
                if (x.find(j) == x.end()) {
                    a[j] *= 2;
                    if (a[j] > c) {
                        x.insert(j);
                        ans += 1;
                    }
                }
            }
         }

        cout << ans << endl;
    }
    return 0;
}