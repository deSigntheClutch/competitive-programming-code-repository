#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;
const ll INF = 8e18 + 7;

// lower -even-> start -odd-> end -even-> upper
int n;
ll a[N], sum[N];
int sumOfEven[N], sumOfOdd[N];
ll minCarry[4];
ll f[N][4];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sumOfEven[i] = sumOfEven[i - 1] + (a[i] % 2 == 0);
        sumOfOdd[i] = sumOfOdd[i - 1] + (a[i] % 2 != 0) + 2 * (a[i] == 0);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            f[i][j] = INF;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 0) {
                f[i][j] = sum[i] - sum[0];
                minCarry[j] = min(minCarry[j], f[i][j] - sumOfOdd[i]);
            } else if (j == 1 || j == 3) {
                f[i][j] = sumOfOdd[i] + minCarry[j - 1];
                minCarry[j] = min(minCarry[j], f[i][j] - sumOfEven[i]);
            } else {
                f[i][j] = sumOfEven[i] + minCarry[j - 1];
                minCarry[j] = min(minCarry[j], f[i][j] - sumOfOdd[i]);
            }
        }
    }
    ll res = INF;
    for (int i = 1; i <= n; i++) {
        //printf("%lld %lld %lld %lld\n", f[i][0], f[i][1], f[i][2], f[i][3]);
        res = min(res, f[i][3] + sum[n] - sum[i]);
    }
    cout << res << endl;
}