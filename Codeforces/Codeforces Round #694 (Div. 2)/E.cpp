#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, q;
int a[N];
int oddp[N];
map<int, int> father;
map<int, int> new_father;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        father.clear(); 
        new_father.clear();

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int tmp = 1;
            for (int j = 2; j <= 1000; j++) {
                int cnt = 0;
                while (a[i] % j == 0) {
                    a[i] /= j;
                    cnt += 1;
                }
                if (cnt & 1) tmp *= j;
            }
            tmp *= a[i];
            father[tmp] += 1;
        }

        int ans0 = 1, ans1 = 1;
        for (auto x = father.begin(); x != father.end(); x++) {
            ans0 = max(ans0, x->second);
            if (x->second % 2 == 0) {
                new_father[1] += x->second;
                ans1 = max(ans1, new_father[1]);
            }
            else {
                new_father[x->first] += x->second;
                ans1 = max(ans1, new_father[x->first]);
            }
        }
        cin >> q;
        while (q--) {
            int y;
            cin >> y;
            if (y >= 1)
                cout << ans1 << endl;
            else
                cout << ans0 << endl;
        }
    }
    return 0;
}