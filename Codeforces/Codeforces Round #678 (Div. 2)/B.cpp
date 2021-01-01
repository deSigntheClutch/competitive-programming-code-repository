#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[123][123];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++) {
            a[i][i] = 4;
            a[(i + 1) % n][i] = 9;
        }
        for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               cout << a[i][j] << " ";
           }
           cout << endl;
        }
    }
    return 0;
}
