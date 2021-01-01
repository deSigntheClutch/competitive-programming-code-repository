#include <bits/stdc++.h>
using namespace std;

int n;
int a[123];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool flag = false;
    if((a[0] & 1) && (a[n - 1] & 1) && (n & 1)) flag = true;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
