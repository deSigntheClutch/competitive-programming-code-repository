#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

string s;
int n;
vector<int> v[4];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 4; i++) v[i].clear();
        cin >> s;
        n = s.length();
        for (int i = 0; i < n; i++) {
            v[s[i] - '0'].push_back(i);
        }
        int minimum = 1e9 + 1;
        if (v[1].size() == 0 || v[2].size() == 0 || v[3].size() == 0) {
            cout << 0 << endl;
            continue;
        }
        for (int left = 0; left < n; left++) {
            int pos1 = lower_bound(v[1].begin(), v[1].end(), left) - v[1].begin();
            int pos2 = lower_bound(v[2].begin(), v[2].end(), left) - v[2].begin();
            int pos3 = lower_bound(v[3].begin(), v[3].end(), left) - v[3].begin();
            int mx = left;
            bool flag = true;
            if (pos1 < v[1].size()) mx = max(mx, v[1][pos1]);
            else flag = false;
            if (pos2 < v[2].size()) mx = max(mx, v[2][pos2]);
            else flag = false;
            if (pos3 < v[3].size()) mx = max(mx, v[3][pos3]);
            else flag = false;
            if (flag == false) continue;
            // if (left == 4) {
            //     cout << v[1][pos1] << " " << v[2][pos2] << " " << v[3][pos3] << endl;
            // }
            // cout << mx - left + 1 << endl;
            minimum  = min(minimum, mx - left + 1);
        }
        if (minimum > n) minimum = 0;
        cout << minimum << endl;
    }
    return 0;
}
