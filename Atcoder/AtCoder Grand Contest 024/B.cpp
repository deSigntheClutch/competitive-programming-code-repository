#include <bits/stdc++.h>
using namespace std;

int n;
int a[234567];
int pos[234567];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int cnt = 0;
    int maxx = -1;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i] > cur) {
            cur = pos[i];
            cnt++;
        } else {
            cur = pos[i];
            cnt = 1;
        }
        maxx = max(maxx, cnt);
    }
    cout << n - maxx << endl;
    return 0;
}