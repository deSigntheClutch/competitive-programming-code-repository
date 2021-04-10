#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            } else {
                if (s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
        }
        cout << s << endl;
    }
}