#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[323456], b[334567];
int d[323456];
int n;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        int len = 1;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> d[i];
            cnt[d[i]] += 1;
            if (cnt[d[i]] == 1) {
                b[len++] = d[i];
            }
        }
        bool flag = true;

        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second != 2) {
                flag = false;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }

        if (n == 1) {
            if (b[1] % 2 == 0 && b[1] > 0) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }

        sort(b + 1, b + 1 + n, greater<int>());
        for (int i = 1; i <= n; i++) {
            if (b[i] % 2 != 0) {
                flag = false;
            }
        }
        
        int cur = 2 * n - 2;
        int delta = 0;
        int sum = 0;
        int pp = 0;
        vector<int> v;
        for (int i = 1; i < n; i++) {
            if ((b[i] - b[i + 1]) % cur != 0 || (b[i] - b[i + 1]) / cur <= 0) {
                flag = false;
            }
            delta = (b[i] - b[i + 1]) / cur;
            v.push_back(delta);
            cur -= 2;
        }
        reverse(v.begin(), v.end());
        for (auto x : v) {
            pp += x;
            sum += pp;
        }

        if ((b[n] - 2 * sum) % n != 0) 
            flag = false;
        int init = (b[n] - 2 * sum) / n; 
        if (init % 2 == 1 || init < 2) flag = false;

        if (!flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}