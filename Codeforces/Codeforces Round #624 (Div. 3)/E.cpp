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

const int N = 1e5 + 5;
int n, d;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> d;
        int s = 0;
        vector<int> ans;
        for (int i = 0;; i++) {
            if (i + s > d) {
                ans.push_back(d - s);
                break;
            }
            ans.push_back(i);
            s += i;
        }
        if (ans.size() > n)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 1; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}