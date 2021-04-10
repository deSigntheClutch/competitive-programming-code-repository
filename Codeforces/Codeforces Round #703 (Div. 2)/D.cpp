#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 2e5 + 6;
 
int a[N];
int b[N], sum[N];
int n, k;
 
bool check(int val) {
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        b[i] = (a[i] >= val) ? 1 : 0;
        sum[i] = sum[i - 1] + b[i];
    }
    s.insert(0);
    for (int i = 1; i <= n; i++) {
        if (i >= k) {
            s.insert(2 * sum[i - k] - (i - k));
            int cur = 2 * sum[i] - i;
            if (cur > *s.begin()) {
                return true;
            }
        }
    }
    return false;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n + 1, md;
    for (int i = 0; i < 20; i++) {
        md = (l + r) >> 1;
        if (check(md)) l = md + 1;
        else r = md;
    }
    cout << md - 1 << endl;
}