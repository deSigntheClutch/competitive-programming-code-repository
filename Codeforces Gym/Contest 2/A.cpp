#include "bits/stdc++.h"
using namespace std;

string type;
int n;
string s;

int main() {
    cin >> type;
    cin >> n;
    cin >> s;
    if (type == "E") {
        for (int i = 0; i < s.length(); i++) {
            s[i] = 'a' + (s[i] - 'a' + n) % 26;
        }
    } else {
        for (int i = 0; i < s.length(); i++) {
            s[i] = 'a' + (s[i] - 'a' - n + 26) % 26;
        }
    }
    cout << s << endl;
    return 0;
}