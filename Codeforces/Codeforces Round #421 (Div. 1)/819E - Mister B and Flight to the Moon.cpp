#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
int n;

void solve(int x) {
    vector<int> t;
    if (x == 3) {
        t.push_back(1), t.push_back(2), t.push_back(3);
        ans.push_back(t), ans.push_back(t);
    } else if (x == 4) {
        t.push_back(1), t.push_back(2), t.push_back(3);
        ans.push_back(t), t.clear();
        t.push_back(2), t.push_back(3), t.push_back(4);
        ans.push_back(t), t.clear();
        t.push_back(3), t.push_back(4), t.push_back(1);
        ans.push_back(t), t.clear();
        t.push_back(4), t.push_back(1), t.push_back(2);
        ans.push_back(t), t.clear();
    } else {
        for (int i = 1; i < x - 2; ++i) {
            t.clear();
            t.push_back(i), t.push_back(x - 1), t.push_back(i + 1), t.push_back(x);
            ans.push_back(t);
        }
        t.clear(), t.push_back(1), t.push_back(x - 1), t.push_back(x);
        ans.push_back(t);
        t.clear(), t.push_back(x - 2), t.push_back(x - 1), t.push_back(x);
        ans.push_back(t);
        solve(x - 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    solve(n);
    cout << (int)ans.size() << endl;
    for(vector<int> t : ans) {
        cout << (int)t.size();
        for(int x : t) {
            cout << " " << x;
        }
        cout << endl;
    }
    return 0;
}
