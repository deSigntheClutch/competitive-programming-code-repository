#include <bits/stdc++.h>
using namespace std;

int m;

int main() {
    ios::sync_with_stdio(false);
    int cnt = 0;
    while (cin >> m) {
        cout << "Case #" << ++cnt << ": " << (int)((double)m *log10(2)) << endl;
    }
    return 0;
}