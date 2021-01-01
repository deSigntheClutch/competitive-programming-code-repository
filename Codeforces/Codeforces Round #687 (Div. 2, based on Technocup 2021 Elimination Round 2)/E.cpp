#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;

int n, k, a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    int sum = 0, hp = 0;
    vector<vector<int>> group(k + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        if (hp + a[i] < 0) {
            for (int j = n; j >= i; j--) {
                group[j % (k + 1)].push_back(a[j]);
            }
            break;
        }
        sum += hp;
        hp += a[i];
    }
    for (int i = 0; i < k + 1; i++) {
        for (int j = 0; j < group[i].size(); j++) {
            sum += group[i][j] * j;
        }
    }
    cout << sum + hp * group[n % (k + 1)].size() << endl;
    return 0;
}
