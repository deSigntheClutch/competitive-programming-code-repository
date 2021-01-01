#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    cout << 4 << endl;
    cout << "L 2" << endl;
    cout << "R 2" << endl;
    cout << "R 2" << endl;
    cout << "R " << 2 * n - 1 << endl;
    return 0;
}
