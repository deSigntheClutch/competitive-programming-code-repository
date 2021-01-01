#include <bits/stdc++.h>
using namespace std;

int n, k;
string str;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> str;
        bool flag = false;
        for (int i = 0; i < str.length(); i++) {
            if (i + k < str.length()) {
                flag |= (str[i] != '?' && str[i + k] != '?' && str[i] != str[i + k]);
            }
        }
        if (flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}