#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[2111], n, k;
int sum[2111];

signed main() {
    vector<int> v;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            v.push_back(sum[i] - sum[j - 1]);
        }
    }
    for (int i = 42; i >= 0; i--) {
        int cnt = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[j] >> i & 1) cnt += 1;
        }
        vector<int> tmp_v;
        if (cnt >= k) {
            for (int j = 0; j < v.size(); j++) {
                if (v[j] >> i & 1) {
                    tmp_v.push_back(v[j]);
                }
            }
            v = tmp_v;
        } 
    }
    int ans = v[0];
    for (int i = 0; i < k; i++) {
        ans &= v[i];
    }
    cout << ans << endl;
    return 0;
}