#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <memory>
#include <stack>

#define int long long

using namespace std;

const int N = 1e5 + 5;

int n;
string a, b;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a >> b;
        int r = 0;
        int bb = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) r++;
            else if (a[i] < b[i]) bb++;
        }
        if (r > bb) cout << "RED" << endl;
        else if (r < bb) cout << "BLUE" << endl;
        else cout << "EQUAL" << endl;
    }
    return 0;
}