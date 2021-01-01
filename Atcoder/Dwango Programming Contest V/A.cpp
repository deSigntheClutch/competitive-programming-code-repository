#include<bits/stdc++.h>
using namespace std;

int a[111], n;

int main() {
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= n;
        sum += a[i];
    }
    sum /= n;
    int ans = -1;
    int different = 1e9;
    for (int i = 0; i < n; i++) {
        if (different > abs(a[i] - sum)) {
            different = abs(a[i] - sum);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}