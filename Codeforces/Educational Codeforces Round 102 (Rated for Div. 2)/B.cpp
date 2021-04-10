#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 3;
const int INF = 1e15;

string s, t;
int n, m;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> s >> t;
        if (s.length() < t.length()) swap(s, t);

        n = s.length();
        m = t.length();
        string ans = "";
        bool find = false;

        for (int i = 1; i <= 60; i++) {
            ans = "";
            if ((i * n) % m != 0) continue;
            for (int j = 0; j < i; j++) {
                ans += s;
            }
            int pt = 0;
            bool flag = true;
            for (int j = 0; j < i * n; j++) {
                if (ans[j] != t[pt]) {
                    flag = false;
                    break;
                }
                pt = (pt + 1) % m;
            }
            if (flag) {
                cout << ans << endl;
                find = true;
                break;
            }
        }

        if (!find) cout << "-1" << endl;
    }
    return 0;
}