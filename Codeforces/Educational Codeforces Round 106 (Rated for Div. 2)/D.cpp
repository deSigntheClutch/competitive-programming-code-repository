#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e7 + 2;

int dp[N];
bool np[N];

int pw[N];
int c, d, x, a, b;
string s;

signed main() {
    ios::sync_with_stdio(false);
    pw[0] = 1;
    for (int i = 1; i < 20; i++) {
        pw[i] = pw[i - 1] * 2;
    }

    for (int i = 2; i < N; i++) {
        if (np[i]) continue;
        dp[i] += 1;
        for (int j = 2 * i; j < N; j += i) {
            dp[j] += 1;
            np[j] = true;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> c >> d >> x;
        vector<int> val;
        for (int _gcd = 1; _gcd * _gcd <= x; _gcd++) {
            if (x % _gcd) continue;
            int v1 = _gcd;
            val.push_back(v1);

            int v2 = x / _gcd;
            if (v1 == v2) continue;
            val.push_back(v2);

        }
        int ans = 0;
        // gcd = v
        for (int v : val) {
            //cout << v << endl;
            int w = x / v;
            w += d;
            if (w % c) continue;
            w /= c;
           // cout << "lcm: "<< w * v << " "<< w << " " << pw[dp[w]] << endl;
            ans += pw[dp[w]];
        }

        cout << ans << endl;
        //cout << endl;
    }
    return 0;
}