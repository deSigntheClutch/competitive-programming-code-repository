#include <algorithm>
#include <cstdio>
#include <cstring>
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

const int N = 1e3 + 5;

int n;
pair<int, int> a[N];
int b[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        memset(b, 0, sizeof b);
        cin >> n;
        int s = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            if (i & 1) s += a[i].first;
            sum += a[i].first;
        }
        if (s * 2 > sum) {
            for (int i = 0; i < n; i++) {
                if (i & 1) cout << a[i].first << " ";
                else cout << 1 << " ";
            }
            cout << endl;

        } else {
            for (int i = 0; i < n; i++) {
                if (!(i & 1)) cout << a[i].first << " ";
                else cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}