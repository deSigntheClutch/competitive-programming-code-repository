#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, q;
int a[N];
int oddp[N];
map<int, int> father;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        father.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            oddp[i] = 1;
            int t = a[i];
            for (int j = 2; j * j <= a[i]; j++) {
                if (a[i] % j) continue;
                int cnt = 0;
                while (t % j == 0) t /= j, cnt += 1;
                if (cnt & 1) oddp[i] *= j;
            }
            if (t != 1) {
                oddp[i] *= t;
            }
            father[oddp[i]] += 1;
        }
        map<int, int> new_father;
        int ans0 = 1, ans1 = 1;
        for (auto x = father.begin(); x != father.end(); x++) {
            //cout << x->first << " " << x->second << endl;
            ans0 = max(ans0, x->second);
            if (x->second % 2 == 0)
                new_father[1] += x->second;
            else {
                new_father[x->first] += x->second;
            }
        }
        for (auto x = new_father.begin(); x != new_father.end(); x++) {
            ans1 = max(ans1, x->second);
        }
        cin >> q;
        while (q--) {
            long long y;
            cin >> y;
            if (y >= 1)
                cout << ans1 << endl;
            else
                cout << ans0 << endl;
        }
    }
    return 0;
}