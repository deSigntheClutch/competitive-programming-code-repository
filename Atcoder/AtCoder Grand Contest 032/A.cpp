#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

bool flag = true;
vector<int> ans;
int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    set<pair<int, int>> s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(make_pair(i, a[i]));
    }
    for (int i = n; i >= 1; i--) {
        pair<int, int> pick = make_pair(-1, -1);
        for (auto x: s) {
            if (x.first == x.second) {
                pick = x;
            }
        }
        if (pick == make_pair(-1, -1)) {
            flag = false;
            break;
        } else {
            ans.push_back(pick.first);
            s.erase(s.find(pick));
            int cnt = 1;
            for (auto x: s) {
                pair<int, int> tmp = *s.find(x);
                s.erase(s.find(x));
                tmp.first = cnt;
                cnt++;
                s.insert(tmp);
            }
        }
    }
    if (flag == false) {
        cout << -1 << endl;
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for (int x: ans) {
        cout << x << endl;
    }
    cout << endl;
    return 0;
}