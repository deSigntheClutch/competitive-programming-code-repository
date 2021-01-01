#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <set>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n;

bool check(int x) {
    int val = x;
    while (x) {
        int digit = x % 10;
        x /= 10;
        if (digit != 0) {
            if (val % digit != 0) return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 600000; i++) {
            if (check(n + i)) {
                cout << n + i << endl;
                break;
            }
        }
    }
}