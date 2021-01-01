#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;

long long a, b;
vector<int> v;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        long long tmp = b - a;
        long long t = 1;
        v.push_back(1);
        for (long long s = 1, t = 2; s < 1e10 + 10; t++) {
            v.push_back(s + t);
            s += t;
        }
        if (tmp == 0) {
            cout << 0 << endl;
            continue;
        }
        if (tmp % 2 == 0) {
            for (int ans = 0;;ans++) {
                if (v[ans] >= tmp && (v[ans] % 2 == 0)) {
                    cout << ans + 1 << endl;
                    break;
                }
            }
        } else {
            for (int ans = 0;;ans++) {
                if (v[ans] >= tmp && (v[ans] % 2 == 1)) {
                    cout << ans + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}