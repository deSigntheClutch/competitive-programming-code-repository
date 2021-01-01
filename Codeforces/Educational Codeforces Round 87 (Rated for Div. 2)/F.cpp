#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

int L[N], R[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (b & 1) {
            if (a & 1) {
                long long sum = (long long)(1 + 1 + 2 * (b - 1)) * b / 2;
                if (a < sum) cout << "no" << endl;
                else cout << "yes" << endl;
            }
            else cout << "no" << endl;
        } else {
            if (a & 1) cout << "no" << endl;
            else {
                long long sum = (long long)(1 + 1 + 2 * (b - 1)) * b / 2;
                if (a < sum) cout << "no" << endl;
                else cout << "yes" << endl;
            }
        }
    }
    return 0;
}
