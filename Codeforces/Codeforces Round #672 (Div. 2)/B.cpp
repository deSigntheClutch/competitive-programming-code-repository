#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int max_1[44];

int get_max(int u) {
    int cnt = 0;
    while (u) {
        u >>= 1;
        cnt += 1;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        memset(max_1, 0, sizeof max_1);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int v = get_max(a[i]);
            max_1[v] += 1;
        }
        int res = 0;
        for (int i = 0; i < 44; i++) {
            res += (max_1[i] - 1) * max_1[i] / 2;
        }
        cout <<res<< endl;
    }
    return 0;
}