#include <bits/stdc++.h>
using namespace std;
#define int long long

int d;
int prime[423456];
int len;
bool isn[423456];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    for (int i = 2; i < 423456; i++) {
        if (!isn[i]) {
            prime[len++] = i;
            for (int j = 2 * i; j < 423456; j += i) {
                isn[j] = true;
            }
        }
    }
    cin >> T;
    while (T--) {
        cin >> d;
        int p1 = 0, p2 = 0;
        for (;; p1++) {
            if (prime[p1] - 1 >= d) {
                p2 = p1;
                p1 = prime[p1];
                break;
            }
        }
        for (;; p2++) {
            if (prime[p2] - p1 >= d) {
                p2 = prime[p2];
                break;
            }
        }
        cout << (long long)p1 * p2 << endl;
    }

    return 0;
}