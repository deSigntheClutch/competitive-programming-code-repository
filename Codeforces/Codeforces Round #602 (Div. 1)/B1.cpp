#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
pair<int, int> b[N];
int a[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sort(b + 1, b + 1 + n);
    cin >> m;
    while (m--) {
        int k, pos;
        cin >> k >> pos;
        multiset<int> arr;
        for (int i = n; i > n - k; i--) {
            arr.insert(b[i].first);
        }
        vector<int> ans;
        int pt = 0;
        for (int i = 1; i <= n; i++) {
            if (arr.find(a[i]) != arr.end()) {
                ans.push_back(a[i]);
                arr.erase(arr.lower_bound(a[i]));
            }
            if (0 == (int)arr.size()) break;
        }

        cout << ans[pos - 1] << endl;
    }
    return 0;
}