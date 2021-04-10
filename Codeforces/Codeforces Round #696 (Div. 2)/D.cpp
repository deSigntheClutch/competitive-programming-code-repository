#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[222222];
int sl[222222];
int sr[222222];
bool abvl[222222];
bool abvr[222222];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sl[i] = sr[i] = 0;
        }
        int diff = a[1];
        bool f = false;
        for (int i = 2; i <= n; i++) {
            if (a[i] - diff < 0) {
                f = true;
            } else {
                diff = a[i] - diff;
            }
        }
        if (!diff && !f) {
            cout << "YES" << endl;
            continue;
        }
        sl[0] = 0; sr[n + 1] = 0;
        abvl[0] = abvr[n + 1] = true;
        for (int i = 1; i <= n; i++) {
            sl[i] = a[i] - sl[i - 1];
            //cout << sl[i] << " ";
            abvl[i] = (abvl[i - 1] & (sl[i] >= 0)); 
        }        
       // cout << endl;
        for (int i = n; i >= 1; i--) {
            sr[i] = a[i] - sr[i + 1];
            //cout << sr[i] << " ";
            abvr[i] = (abvr[i + 1] & (sr[i] >= 0)); 
        }
        // cout << endl;
        bool fnd = false;
        for (int i = 1; i < n; i++) {
            //cout << sl[i - 1] << " " << sr[i + 2] << endl;
            vector<int> v;
            if (!abvl[i - 1] || !abvr[i + 2]) continue;
            v.push_back(sl[i - 1]);
            v.push_back(a[i + 1]);
            v.push_back(a[i]);
            v.push_back(sr[i + 2]);
            int dif = v[0];
            bool flag = false;
            for (int j = 1; j < 4; j++) {
                if (v[j] - dif < 0) {
                    flag = true;
                } else {
                    dif = v[j] - dif;
                }
            }
            if (!flag && !dif) fnd = true;
        }
        cout << (fnd ? "YES" : "NO") << endl;
    }
    return 0;
}