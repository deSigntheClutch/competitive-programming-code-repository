#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, m;
int bugs[N];
string s;
int sum[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> s;
        for (int i = 1; i <= m; i++) {
            cin >> bugs[i];
        }
        for (int i = 'a'; i <= 'z'; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                sum[j] = (s[j] == i);
                if (j > 0) sum[j] += sum[j - 1];
               // cout << sum[j] << " ";
            }
            //cout << endl;
            for (int j = 1; j <= m; j++) {
                cnt += sum[bugs[j] - 1];
            }
            cout << cnt + sum[n - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}