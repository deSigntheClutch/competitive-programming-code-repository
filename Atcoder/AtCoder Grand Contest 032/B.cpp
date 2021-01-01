#include <bits/stdc++.h>
using namespace std;

int n;
set<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n & 1) {
        for (int i = 1; i < n; i++) {
            int x = i;
            int y = n - i;
            if (x > y) swap(x, y);
            s.insert(make_pair(x, y));
        }
    } else {
        for (int i = 1; i <= n; i++) {
            int x = i;
            int y = n - i + 1;
            if (x > y) swap(x, y);
            s.insert(make_pair(x, y));
        }
    }
    cout << n * (n - 1) / 2 - (int)s.size() << endl; 
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s.find(make_pair(i, j)) == s.end()) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}