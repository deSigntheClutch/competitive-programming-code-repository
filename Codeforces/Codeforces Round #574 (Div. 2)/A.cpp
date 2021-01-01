#include <bits/stdc++.h>
using namespace std;


int n, m;
int ans[1234];

int main() {
    cin >> n >> m;
    ans[0] = 1;
    int cnt = 1;
    for (int i = 1; i <= n / 2; i++) {
        ans[i] = cnt++;
    }
    cnt--;
    bool parity = n & 1;
    for (int i = n / 2 + (parity); i <= n; i++) {
        ans[i] = cnt--;
    }
    cout << ans[m] << endl;
    return 0;
}