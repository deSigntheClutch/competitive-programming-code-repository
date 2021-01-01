#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 123;

int n, k;
string s;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n>>s;
        int pt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                swap(s[i], s[pt]);
                pt++;
            }
        }
        cout << s << endl;
    }
    return 0;
}

/*

gg A.cpp && run


*/
