#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int M = 1e2 + 5;
const int N = 1e6 + 10;

int f[M], e[M], v[M];
int l[N];
int n, m, L;

void multiply(int *a, int *b) {
    int res[M];
    memset(res, 0, sizeof res);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            res[(i + j) % m] = (res[(i + j) % m] + (long long)a[i] * b[j] % MOD) % MOD;
        }
    }
    for(int i = 0; i <= m; i++){
        a[i] = res[i];
    }
}

void quick_mod(int x) {
    while (x) {
        if (x & 1) multiply(f, v);
        x >>= 1;
        multiply(v, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> L >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        f[t % m]++;
    }
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        l[i] = t;
        v[t % m]++;
    }
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        e[(l[i] + t) % m]++;
    }
    quick_mod(L - 2);
    multiply(f, e);
    cout << f[0] << endl;
    return 0;
}
