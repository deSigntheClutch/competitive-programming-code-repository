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
        if (a * b % 2 == 0) {
            cout << a * b / 2 << endl;
        } else {
            cout << a * b / 2 + 1 << endl;
        }
    }
    return 0;
}
