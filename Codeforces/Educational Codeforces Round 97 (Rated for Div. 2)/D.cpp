#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int cur_layer = 1;
        int next_layer = 1;
        int ans = 0;
        int depth = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i < 2) {
                continue;
            }
            if (a[i] > a[i - 1]) {
                next_layer += 1;
            }
            else {
                cur_layer -= 1;
                if (cur_layer == 0) {
                    cur_layer = next_layer;
                    next_layer = 1;
                    depth += 1;
                } else {
                    next_layer += 1;
                }
            }
        }
        cout << depth << endl;
    }
    return 0;
}
