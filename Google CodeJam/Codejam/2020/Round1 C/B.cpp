#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[11];
int tnc[1111];
bool vis[1111];

void add(int u) {
    while (u) {
        cnt[u % 10] += 1;
        u /= 10;
    }
}

void pos(string k) {
    for (int i = 0; i < k.length(); i++) {
        tnc[k[i]] += 1;
    }
}

int U;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";
        cin >> U;

        memset(tnc, 0, sizeof tnc);
        memset(cnt, 0, sizeof cnt);
        memset(vis, 0, sizeof vis);

        vector<string> store;
        for (int i = 0; i < 10000; i++) {
            int x;
            string k;
            cin >> x >> k;
            store.push_back(k);
            tnc[k[0]] += 1;
        }
        vector<pair<int, char>> vs;
        for (int i = 'A'; i <= 'Z'; i++){
            if (tnc[i] == 0) continue;
            vis[i] = 1;
            vs.push_back({-tnc[i], (char)i});
        }
        sort(vs.begin(), vs.end());
        string ans = "";
        for (int i = 0; i < vs.size(); i++) {
            ans += vs[i].second;
        }
        for (string p : store) {
            pos(p);
        }
        for (int i = 'A'; i <= 'Z'; i++){
            if (vis[i] == 1) continue;
            if (tnc[i] == 0) continue;
            ans = (char)i + ans;
        }
        cout << ans << endl;
    }
    return 0;
}