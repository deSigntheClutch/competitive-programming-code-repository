//  g++ -std=c++14 A.cpp -o a && ./a
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int r = 0, c = 0;
    for (int i=  0; i < s.length(); i++) {
        if (s[i] == 'R') r++;
        else c++;
    }
    cout << r + c + 1 << endl;
    return 0;
}