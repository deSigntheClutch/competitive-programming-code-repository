#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
const int MOD = 1e9 + 7;

int f[N], factor[N];
bool nu[N];
int t, l, r, total;

int main() {
    for (int i = 2; i < N; i++) {
        if (!nu[i]) {
            f[i] = (long long)i * (i - 1) / 2 % MOD;
            for (int j = 2 * i; j < N; j += i) {
                nu[j] = true;
                //if(!factor[j])
                    factor[j] = i;
            }
        }
    }
    for(int i = 2; i < N; i++) {
        if(nu[i]) {
            f[i] = (f[i / factor[i]] + (long long)i * (factor[i] - 1) / 2 % MOD) % MOD;
        }
    }
    printf("%d %d %d\n", f[6], f[15], f[30]);
    scanf("%d%d%d", &t, &l, &r);
    int cur = 1;
    for (int i = l; i <= r; i++) {
        total = (total + (long long)cur * f[i] % MOD) % MOD;
        cur = (long long)cur * t % MOD;
    }
    printf("%d\n", total);
    return 0;
}
