#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int M = 2e5 + 4;

int sum[M], perm[N], tmp[N];
int n, q;
bool used[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
