#include <bits/stdc++.h>
using namespace std;

int n;
int y[1234];
set<pair<int, int>> s;
bool vis[1234];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    bool flag = false;
    for (int i = 2; i <= n; i++) {
        bool flag = true;
        int gcd = __gcd(abs(i - 1), abs(y[i] - y[1]));
        pair<int, int> k = make_pair((i - 1) / gcd, (y[i] - y[1]) / gcd);
        memset(vis, 0, sizeof vis);
        vis[1] = 1;
        for (int j = 2; j <= n; j++) {
            int gcdi = __gcd(abs(j - 1), abs(y[j] - y[1]));
            pair<int, int> tmp = make_pair((j - 1) / gcdi, (y[j] - y[1]) / gcdi);
            if (tmp == k) vis[j] = 1;
        }
        vector<int> vec;
        for (int j = 2; j <= n; j++) {
            if (!vis[j]) vec.push_back(j);
        }
        if((int)vec.size() == 0) {
            cout << "No" << endl;
            return 0;
        }
        for (int j = 0; j < (int)vec.size() - 1; j++) {
            int gcdi = __gcd(abs(vec[j + 1] - vec[j]), abs(y[vec[j + 1]] - y[vec[j]]));
            pair<int, int> ntt = make_pair((vec[j + 1] - vec[j]) / gcdi, (y[vec[j + 1]] - y[vec[j]]) / gcdi);
            if (k != ntt) flag = false;
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    bool fg = true;
    pair<int, int> tt;
    for (int i = 2; i < n; i++) {
        bool flag = true;
        pair<int, int> ntt = make_pair(1, y[i + 1] - y[i]);
        if(i == 2) tt = ntt;
        else {
            if(tt != ntt) fg = false;
        }
    }
    if(fg) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
