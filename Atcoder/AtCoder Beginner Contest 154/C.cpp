#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n;
int a[N];
map<int, bool> used;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (used[a[i]] == true) x = 1;
        used[a[i]] = true;
    }
    if (x == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}