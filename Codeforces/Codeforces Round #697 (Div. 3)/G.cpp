#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 6;

int dp[N];
int n, a[N];
vector<int> divd[N];

signed main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divd[j].push_back(i);
        } 
    }
    int T;
    cin >> T;
    while (T--) {
       cin >> n;
       memset(dp, 0, sizeof dp);
       for (int i = 1; i <= n; i++) {
           cin >> a[i];
       }
       sort(a + 1, a + 1 + n);
       for (int i = 1; i <= n; i++) {
           int mx = 0;
           for (int x : divd[a[i]]) {
               mx = max(mx, dp[x]);
           }
           dp[a[i]] = mx + 1;
       }
       cout << n - *max_element(dp, dp + N) << endl;
    }
    return 0;
}