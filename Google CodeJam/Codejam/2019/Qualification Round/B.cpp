#include <bits/stdc++.h>
using namespace std;
 
int n;
string route;
map<char, int> x;
map<int, char> y;

string f(string s) {
    string a = ""; 
    for (char c : s) {
        a += y[x[c] ^ 1];
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    x['S'] = 0;
    x['E'] = 1;
    y[0] = 'S';
    y[1] = 'E';
    for (int cs = 1; cs <= T; cs++) {
        cin >> n;
        cin >> route;
        cout << "Case #" << cs << ": ";
        cout << f(route) << endl;
    }
    return 0;
}