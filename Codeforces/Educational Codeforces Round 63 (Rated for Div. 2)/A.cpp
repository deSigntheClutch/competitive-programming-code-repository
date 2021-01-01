#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            cout << "YES" << endl;
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
