#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s;
        int first = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '8') {
                first = i;
                break;
            }
        }
        if (first != -1 && n - first >= 11) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}