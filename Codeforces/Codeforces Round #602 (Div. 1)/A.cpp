#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string s;
int n, k;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s;
        vector<pair<int, int>> ans;
        for (int i = 0; i < k - 1; i++) {
            int a = i * 2;
            int b = i * 2 + 1;
            if (s[a] != '(') {
                int pt = a;
                while (s[pt] != '(' && pt < n) pt++;
                for (int x = 0; x < (pt - a + 1) / 2; x++) {
                    swap(s[a + x], s[a + pt - a - x]);
                }
                ans.push_back(make_pair(a + 1, pt + 1));
            }
            if (s[b] != ')') {
                int pt = b;
                while (s[pt] != ')' && pt < n) pt++;
                for (int x = 0; x < (pt - b + 1) / 2; x++) {
                    swap(s[b + x], s[b + pt - b - x]);
                }
                ans.push_back(make_pair(b + 1, pt + 1));
            }
        }
        for (int i = 2 * (k - 1); i < n; i++) {
            if (s[i] != '(') {
                int pt = i;
                while (s[pt] != '(' && pt < n) pt++;
                if (pt == n) break;
                for (int x = 0; x < (pt - i + 1) / 2; x++) {
                    swap(s[i + x], s[i + pt - i - x]);
                }
                ans.push_back(make_pair(i + 1, pt + 1));
            }
        }
        cout << (int)ans.size() << endl;
        for (auto x : ans) {
            cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}