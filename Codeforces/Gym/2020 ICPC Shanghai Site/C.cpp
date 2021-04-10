#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 33;

int x, y;
int f[N][2][2];
int dp[N];

int cal(int pos, bool allA, bool allB) {
    if (pos < 0) return 1;

    if (f[pos][allA][allB] != -1) return f[pos][allA][allB];

    int bitA = x >> pos & 1;
    int bitB = y >> pos & 1;

    if (allA) {
        if (bitB)
            return f[pos][allA][allB] = (2 * cal(pos - 1, allA, true) % MOD + cal(pos - 1, allA, allB)) % MOD;
        else
            return f[pos][allA][allB] = 2 * cal(pos - 1, allA, allB) % MOD;
    } else if (allB) {
        if (bitA)
            return f[pos][allA][allB] = (2 * cal(pos - 1, true, allB) % MOD + cal(pos - 1, allA, allB)) % MOD;
        else
            return f[pos][allA][allB] = 2 * cal(pos - 1, allA, allB) % MOD;
    }

    if (bitA == 0 && bitB == 0)
        return f[pos][allA][allB] = cal(pos - 1, allA, allB);
    else if (bitA == 1 && bitB == 0) {
        return f[pos][allA][allB] = (cal(pos - 1, true, allB) + cal(pos - 1, allA, allB)) % MOD;
    } else if (bitA == 0 && bitB == 1) {
        return f[pos][allA][allB] = (cal(pos - 1, allA, true) + cal(pos - 1, allA, allB)) % MOD;
    } else {
        return f[pos][allA][allB] = ((cal(pos - 1, true, true) + cal(pos - 1, true, allB)) % MOD + cal(pos - 1, allA, true)) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        if (x < y) swap(x, y);

        memset(f, -1, sizeof f);
        f[0][1][1] = 3;
        for (int i = 1; i < N; i++) {
            f[i][1][1] = (long long)3 * f[i - 1][1][1] % MOD;
        }

        int res = 0;
        int highestA = -1, highestB = -1;

        for (int i = 30; i >= 0; i--) {
            int bitA = x >> i & 1;
            int bitB = y >> i & 1;
            int cur = 0;

            if (highestA != -1 && (bitB == 0 && highestB == -1)) {
                cur = cal(i - 1, true, false);
            } else if (highestA != -1 && highestB != -1) {
                cur = 2 * cal(i - 1, true, true) % MOD;
            } else if (highestA != -1 && (bitB == 1 && highestB == -1)) {
                cur = (cal(i - 1, true, false) + cal(i - 1, true, true)) % MOD;
            } else if ((bitA == 1 && highestA == -1) && (bitB == 1 && highestB == -1)) {
                cur = (cal(i - 1, false, true) + cal(i - 1, true, false)) % MOD;
            } else if ((bitA == 1 && highestA == -1) && (bitB == 0 && highestB == -1)) {
                cur = cal(i - 1, false, false);
            }

            if (bitA && highestA == -1) {
                highestA = i;
            }
            if (bitB && highestB == -1) {
                highestB = i;
            }
            res = (res + (long long)(i + 1) * cur % MOD) % MOD;
        }

        cout << res << endl;
    }
    return 0;
}