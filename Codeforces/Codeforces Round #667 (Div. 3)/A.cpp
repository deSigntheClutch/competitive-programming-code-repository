#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 1e5 + 5;

int T;
int n, m;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cout << (int) ceil(1.0 * abs(n - m) / 10) << endl;     
    }
    return 0;
}
