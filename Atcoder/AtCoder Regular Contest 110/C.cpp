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

const int N = 2e5 + 5;

int a[N];
int n;
bool used[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int pt = n;
    int matched = n;
    vector<int> ans;
    for (int u = n; u >= 1; u--) {
        if (used[u]) continue;
        int cur = pt;
        while (pt >= 1 && a[pt] != u) pt--;
        for (int i = pt; i < cur; i++) {
            ans.push_back(i);
            swap(a[i], a[i + 1]);
        }
        for (int i = cur; i > pt; i--) {
            if (matched != a[i]) {
                cout << -1 << endl;
                return 0;
            }
            used[matched] = true;
            matched -= 1;
        }
        //cout << u << " " << pt << endl;
    }
    for (int x : ans) cout << x << endl;
    return 0;
}