#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 2;

int n, a[N], k;
int pattern[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<int> ss;
        for (int i = 0; i < n; i++) {
            ss.insert(a[i]);
        }
        if (ss.size() > k) {
            cout << -1 << endl;
            continue;
        }
        cout << k * n << endl;
        for (int i = 0; i < n; i++) {
            int y;
            for (int x : ss) {
                cout << x << " ";
                y = x;
            }
            for (int j = 0; j < k - ss.size(); j++) {
                cout << y << " ";
            }
        }
        cout << endl;
    }
    return 0;
}