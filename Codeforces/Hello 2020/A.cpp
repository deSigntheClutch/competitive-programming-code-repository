#include <bits/stdc++.h>
using namespace std;

vector<string> a, b;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=  0; i < n; i++) {
        string s;
        cin >>s;
        a.push_back(s);
    }
        for (int i=  0; i < m; i++) {
        string s;
        cin >>s;
        b.push_back(s);
    }
    int y;
    cin >> y;
    while (y--) {
        int q;
        cin >> q;
        q--;
        q= q % (n * m);
        cout << a[q % n] + b[q % m] << endl;
    }
    return 0;
}