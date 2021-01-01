#include <bits/stdc++.h>
using namespace std;

string f(string s) {
    string ans = "";
    int index = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') break;
        index = i;
    }
    if (index == -1) return s;
    else return s.substr(index + 1, max(1, (int)s.length() - index));
}

int main() {
    string a;
    int n;
    cin >> n;
    for (int cs = 1; cs <= n; cs++) {
        cout << "Case #" << cs << ": ";
        cin >> a;
        
        string ans1 = "";
        string ans2 = "";
        
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '4') {
                ans1 += '2';
                ans2 += '2';
            } else {
                ans1 += "0";
                ans2 += a[i];
            }
        }
        cout << f(ans1) << " " << f(ans2) << endl;
    }
    return 0;
}