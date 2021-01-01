#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020" ||
            (s.substr(0, 3) == "202" && s.substr(n - 1, 1) == "0") ||
            (s.substr(0, 2) == "20" && s.substr(n - 2, 2) == "20") ||
            (s.substr(0, 1) == "2" && s.substr(n - 3, 3) == "020"))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}