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

using namespace std;

const int N = 1e5 + 5;

int n;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s;
        int pt = -1;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] != ')') {
                pt = i;
                break;
            }
        }
        if (n - 1 - pt > n - (n - 1 - pt)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}