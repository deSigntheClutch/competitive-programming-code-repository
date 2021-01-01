#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, k;
int a[N];

bool check(int x) {
    vector<int> v;
    for(int i = 1; i <= x; i++) {
        v.push_back(-a[i]);
    }
    sort(v.begin(), v.end());
    long long res = 0;
    for (int i = 0; i < (int)v.size(); i += 2) {
        int cur = -v[i];
        res += cur;
    }
    return res <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for  (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int ans = 1; ans <= n; ans++) {
        if (check(ans) == false) {
            cout << ans - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}