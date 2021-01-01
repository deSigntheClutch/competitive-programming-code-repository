#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int n;
string a[N];


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        vector<pair<int, int>> ans;
       cin >> n;
       for (int i = 0; i < n; i++) {
           cin >> a[i];
       }
       if (a[0][1] == '1' && a[1][0] == '1') {
            if (a[n - 1][n - 2] == '1') {
                ans.push_back({n, n - 1});
            }
            if (a[n - 2][n - 1] == '1') {
                ans.push_back({n - 1, n});
            }
       } else if (a[0][1] == '1' && a[1][0] == '1') {
            if (a[n - 1][n - 2] == '0') {
                ans.push_back({n, n - 1});
            }
            if (a[n - 2][n - 1] == '0') {
                ans.push_back({n - 1, n});
            }
       } else {
            if (a[n - 1][n - 2] == '1' && a[n - 2][n - 1] == '1') {
                if (a[0][1] == '1') {
                    ans.push_back({1, 2});
                }
                if (a[1][0] == '1') {
                    ans.push_back({2, 1});
                }
            } else if (a[n - 1][n - 2] == '0' && a[n - 2][n - 1] == '0') {
                if (a[0][1] == '0') {
                    ans.push_back({1, 2});
                }
                if (a[1][0] == '0') {
                    ans.push_back({2, 1});
                }
            } else {
                if (a[0][1] == '1') {
                    ans.push_back({1, 2});
                }
                else if (a[1][0] == '1') {
                    ans.push_back({2, 1});
                }
                if (a[n - 1][n - 2] == '0') {
                    ans.push_back({n, n - 1});
                }
                else if (a[n - 2][n - 1] == '0') {
                    ans.push_back({n - 1, n});
                }
            }
       }
       cout <<(int)ans.size() << endl;
       for (auto x : ans) {
           cout << x.first << " " << x.second << endl;
       }
    }
    return 0;
}
