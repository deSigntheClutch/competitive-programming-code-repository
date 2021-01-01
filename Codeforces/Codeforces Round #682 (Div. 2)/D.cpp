#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int M = 2e5 + 4;

int n;
int sum[M];
int xorsum;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        xorsum ^= sum[i];
    }
    if (n & 1) {
        cout << "YES" << endl;
        vector<pair<int, pair<int, int>>> ans;
        for (int i = 1; i <= n; i++) {
            if (i + 2 > n) {
                for (int j = i - 3; j >= 1; j -= 2) {
                    ans.push_back(make_pair(i, make_pair(j, j - 1)));
                }
                break;
            }
            ans.push_back(make_pair(i, make_pair(i + 1, i + 2)));
            i += 1;
        }
        cout << ans.size() << endl;
        for (auto x : ans) {
            cout << x.first << " " << x.second.first << " " << x.second.second
                 << endl;
        }
    } else {
        if (xorsum != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            n -= 1;
            vector<pair<int, pair<int, int>>> ans;
            for (int i = 1; i <= n; i++) {
                if (i + 2 > n) {
                    for (int j = i - 3; j >= 1; j -= 2) {
                        ans.push_back(make_pair(i, make_pair(j, j - 1)));
                    }
                    break;
                }
                ans.push_back(make_pair(i, make_pair(i + 1, i + 2)));
                i += 1;
            }
            cout << ans.size() << endl;
            for (auto x : ans) {
                cout << x.first << " " << x.second.first << " "
                     << x.second.second << endl;
            }
        }
    }

    return 0;
}
