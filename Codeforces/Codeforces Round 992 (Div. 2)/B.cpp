#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;


int n, k;
int T;
long long f[N];

int main() {
    f[1] = 1;
    f[2] = 4;
    f[3] = 10;
    for (int i = 4; i < N; i++) {
        f[i] = 2ll * (f[i - 1] + 1);
        if (f[i] > 1e10) break;
    }

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; ; i++) {
            if (f[i] >= n) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}