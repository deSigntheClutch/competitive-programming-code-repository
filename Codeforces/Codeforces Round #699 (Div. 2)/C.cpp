#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, m;
int a[N], b[N], c[N];
int ans[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        map<int, vector<int>> cnt;
        map<int, int> has;
        cnt.clear();
        has.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];      
        for (int i = 1; i <= m; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) {
            has[b[i]] = i;
            if (a[i] == b[i]) continue;
            cnt[b[i]].push_back(i);
        }
        bool got = false;
        int pos = -1;       
        bool flag = true;
        for (int i = m; i >= 1; i--) {
            if (cnt[c[i]].size() == 0) {
                if (has[c[i]] == 0 && !got) flag = false; 
                else if (has[c[i]] != 0 && !got){
                    ans[i] = has[c[i]];
                    got = true;
                    pos = has[c[i]];
                } else {
                    ans[i] = pos;
                }
            }
            else {
                if (!got) {
                    got = true;
                    pos = cnt[c[i]][cnt[c[i]].size() - 1];
                }
                ans[i] = cnt[c[i]][cnt[c[i]].size() - 1];
                cnt[c[i]].pop_back();
            }
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[b[i]].size() != 0) flag = false;
        }
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i <= m; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}