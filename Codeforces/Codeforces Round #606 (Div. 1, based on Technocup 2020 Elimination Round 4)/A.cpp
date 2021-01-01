#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

string str;
int main() {
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> str;
        vector<int> ans;
        for (int i = 0; i < str.length(); i++) {
            if (i >= 2 && i + 2 < str.length() && str[i - 2] == 't' && str[i - 1] == 'w' && str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e') {
                ans.push_back(i);
                continue;
            } 
            if (i >= 2 && str[i - 2] == 't' && str[i - 1] == 'w' && str[i] == 'o') {
                ans.push_back(i - 1);
            }
            if (i + 2 < str.length() && str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e') {
                ans.push_back(i + 1);
            }
        }
        cout << (int)ans.size() << endl;
        for (auto x : ans) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
1
onetwonetwooneooonetwooo
*/