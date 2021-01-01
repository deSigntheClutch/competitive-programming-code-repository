#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define int long long

using namespace std;

string pattern;
string s;
int n;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    pattern = "110";
    if (n == 1) {
        if (s == "0") cout << (int)1e10 << endl;
        else cout << (int)2e10 << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        int cover = 0;
        int pt = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] != pattern[(pt + i) % 3]) {
                cover = -1;
                break;
            }
            pt += 1;
            if (j == n - 1) break;
            if ((pt + i) % 3 == 0) cover += 1;
        }
        if (cover == -1) {
            continue;
        } else {
            cout << ((int)1e10) - cover << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}