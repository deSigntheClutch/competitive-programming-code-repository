#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[111111];
int sum;
vector<pair<int, int>> ans;

void solve(int l, int r, int x, int y) {
    if (r - l + 1 < 4) {
        if (r - l == 0) a[l] = x;
        else if (r - l == 1) {
            a[r] = x;
            a[l] = y;
            ans.push_back({r, l});
                sum += (r - l) * (r - l);

        } else if(r - l == 2) {
            a[l] = y;
            a[r] = y - 1;
            a[l + 1] = x;
            ans.push_back({r, l});
            ans.push_back({r, l});
            sum += (r - l - 1) * (r - l - 1);
            sum += (r - l) * (r - l);
        }
        return ;
    }
    a[l] = y - 1;
    a[l + 1] = x;
    a[r] = x + 1;
    a[r - 1] = y;
    ans.push_back({r - 1, l});
    sum += 2 * (r - l) * (r - l) + (r - l + 1) * (r - l + 1);
    ans.push_back({r, l + 1});
    ans.push_back({r, l});
    solve(l + 2, r - 2, x + 2, y - 2);
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    
    cin >> T;
    while (T--) {
        cin >> n;
        sum = 0;
        ans.clear();
        solve(1, n, 1, n);
        cout << sum << endl;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << ans.size() << endl;
        for (auto x: ans) {
            cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}