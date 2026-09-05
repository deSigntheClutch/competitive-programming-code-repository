#include <bits/stdc++.h>
using namespace std;

unsigned easy_random() {
    static unsigned long long x = time(0);
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x;
}

const int N = 200000;

int n;
int a[N];


int main() {
    int T; cin >> T;

    while (T--) {
        srand(time(0));
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string ans = "L";

        int l = 1, r = n - 1;
        int last = a[0];

        for (int i = 1; i < n; i++) {
            if (l != r) {
                if (a[l] > a[r]) {
                    if (last > a[l]) {
                        ans += "RL";
                        last = a[l];
                    } else {
                        ans += "LR";
                        last = a[r];
                    }
                } else {
                    if (last > a[r]) {
                        ans += "LR";
                        last = a[r];
                    } else {
                        ans += "RL";
                        last = a[l];
                    }
                }
                l++, r--;
            }
            if (l >= r) break;
        }
        if (l == r) ans += "L";
        cout << ans << endl;
    }
    return 0;
}