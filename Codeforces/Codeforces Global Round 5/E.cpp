#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e6 + 5;

int n;
bool possible_num[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    possible_num[1] = possible_num[2] = true;
    int a = 1, b = 2;
    for (int x, y; a < N; ) {
        x = a + b + 1;
        y = b + b + 1;
        if (x & 1) a = x, b = y;
        else a = y, b = x;
        possible_num[a] = true;
        possible_num[b] = true;
    }
    if (possible_num[n] == true) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}