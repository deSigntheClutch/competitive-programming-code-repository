#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <set>
#include <memory>

#define int long long

using namespace std;

const int N = 4e5 + 5;

int n;
int b[N], a[N];
set<int> s;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> n;
        s.clear();
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            s.insert(b[i]);
        }
        int pt = 0;
        priority_queue<int> usedun;
        priority_queue<int> unused;
        for (int i = 1; i <= 2 * n; i++) {
            if (s.find(i) == s.end()) {
                a[pt++] = i;
                unused.push(i);
                usedun.push(-i);
            }
        }
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            while (!usedun.empty() && -usedun.top() < b[i]) {
                usedun.pop();
            }
            if (usedun.empty()) break;
            cnt0 += 1;
            usedun.pop();
        }

        int cnt1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!unused.empty() && unused.top() > b[i]) {
                unused.pop();
            }
            if (unused.empty()) break;
            cnt1 += 1;
            unused.pop();
        }
        cnt1 = n - cnt1;
        cout << cnt0 - cnt1 + 1 << endl;
    }
    return 0;
}