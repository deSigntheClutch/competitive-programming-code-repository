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

int n, k;
string s;

string convert(int x) {
    string ans = "";
    while (x) {
        ans += ((x & 1) + '0');
        x >>= 1;
    }
    if (ans.length() > k) {
        return "NO";
    }
    for (int i = ans.length(); i < k; i++) {
        ans += '0';
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> s;
        int cnt0 = 0;
        for (int i = 0; i < max(0ll, k - 21); i++) {
            cnt0 += (s[i] == '0');
        }

        int start = 0;
        for (int i = max(0ll, k - 21); i < k; i++) {
            start <<= 1;
            start += (s[i] - '0');
        }

        int len = min(21ll, k);
        // cout << start << endl;
        vector<int> vec;
        if (cnt0 == 0) vec.push_back(start ^ ((1ll << len) - 1));

        for (int end = k; end < n; end++) {
            cnt0 -= (s[end - k] == '0');
            start -= (s[end - len] - '0') << (len - 1);
            start <<= 1;
            start += (s[end] - '0');
            cnt0 += (s[end - len] == '0');
            // cout << start << endl;
            if (cnt0 == 0)
                vec.push_back(start ^ ((1ll << len) - 1));
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        //        for (int x : vec) {
        //            cout << x << endl;
        //        }
        int l = 0, r = 2e6 + 10, md;
        for (int cs = 0; cs < 25; cs++) {
            md = (l + r) >> 1;
            if (md >= vec.size() || vec[md] > md)
                r = md;
            else
                l = md + 1;
        }

        if (md >= 1 && md >= vec.size()) {
            md = vec[vec.size() - 1] + 1;
        } else {
            md = (md == 0) ? 0 : vec[md - 1] + 1;
        }
        cout << convert(md) << endl;
    }
    return 0;
}