#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, k;
int T;
int arr[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            bool flag = true;

            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    if (abs(arr[j] - arr[i]) % k == 0) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                cout << "YES" << endl;
                cout << i << endl;
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            cout << "NO" << endl;
        }
    }
    return 0;
}