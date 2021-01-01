#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    if (n == k || k == 0) cout << "0 ";
    else cout << "1 ";
    int block = n / 3, sz = n % 3;
    int used = block + (sz > 0);
    if(k >= used) {
        int vacant = n - used;
        cout << vacant - (k - used) << endl;
    }
    else {
        if(k <= block) {
            cout << k * 2 << endl;
        } else {
            cout << block * 2 + max(0, sz - 1) << endl;
        }
    }
    return 0;
}
