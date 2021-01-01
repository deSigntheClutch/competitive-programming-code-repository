#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n;
int a[N];
int sum[N];
int f[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    f[0] = f[1] = 1;
    sum[a[1]] = 1;

    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) f[i] = f[i - 1];
        else f[i] = (f[i - 1] + sum[a[i]]) % MOD;
        if (a[i] != a[i - 1]) sum[a[i]] = (sum[a[i]] + f[i - 1]) % MOD;
    }
    cout << f[n] << endl;
    return 0;
}