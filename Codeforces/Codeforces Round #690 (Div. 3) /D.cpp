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

int check(vector<int> & a, int portion) {
    int cur = 0;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        cur += a[i];
        if (cur > portion) {
            return -1;
        } else if (cur == portion) {
            cur = 0;
            cnt += 1;
        }
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        vector<int> ans(100000, 0);
        int n;
        cin >> n;
        vector<int> a;
        int sum = 0;
        for (int q, i = 0; i < n; i++) {
            cin >> q;
            sum += q;
            a.push_back(q);
        }
        for (int i = 1; i * i <= sum; i++) {
            if (sum % i) continue;
            int tmp = check(a, i);
            if (tmp != -1) {
                ans[n - tmp] = 1;
            }
            tmp = check(a, sum / i);
            if (tmp != -1) {
                ans[n - tmp] = 1;
            }
        }
        for (int i = 0; i < 100000; i++) {
            if (ans[i] == 1) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}