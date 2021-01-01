#include <bits/stdc++.h>
using namespace std;

int n;
string a, b, ta, tb;
vector<int> ans;

void flip(int id) {
    ans.push_back(id);
    string alpha = a.substr(0, n - id);
    string beta = a.substr(n - id, id);
    reverse(beta.begin(), beta.end());
    a = beta + alpha;
}

int main() {
    cin >> n >> a >> b;
    ta = a, tb = b;
    sort(ta.begin(), ta.end());
    sort(tb.begin(), tb.end());
    if (ta != tb) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int idx = a.find(b[i]);
        flip(n - 1 - idx);
        flip(1);
        flip(n);
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}