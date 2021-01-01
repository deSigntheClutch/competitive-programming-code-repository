#include <bits/stdc++.h>
using namespace std;

int n;
int a[234567];
int pos[234567];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int father = -1;
    long long cnt = 0;
    for (int i = n; i >= 1; i--) {
        father -= 1;
        if (father == a[i]) {
            continue;
        } else if (father > a[i]) {
            cout << -1 << endl;
            return 0;
        } 
        if (i <= a[i]) {
            cout << -1 << endl;
            return 0;
        }
        cnt += a[i];
        father = a[i];
    }
    cout << cnt << endl;
    return 0;
}