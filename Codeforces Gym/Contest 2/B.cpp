#include "bits/stdc++.h"
using namespace std;

string type;
int n, k;
int a[2234];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    sort(a, a + n);
    for (int i = 0; i < k; i++) {
        ans  += a[n - 1 - i];
    }
    cout << ans << endl;
    return 0;
}