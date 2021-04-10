#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, A, B;
int h[123456];

bool check(int v) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int val = h[i] - v * B;
        if (val >= 0) {
            cnt += (val + ((A - B) - 1))/ (A - B);
        }
    }
    return cnt <= v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int l = 1, r = 1e9 + 10, md;
    for (int i = 0; i < 34; i++) {
        md = (l + r) >> 1;
        if (check(md))
            r = md;
        else
            l = md + 1;
    }

    cout << md << endl;
    return 0;
}