#include <bits/stdc++.h>
using namespace std;
#define int long long

const double pi = acos(-1.0);
const int MOD = 1e6 + 3;
const int N = 1e3 + 3;

int n, m, k;

void ask(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
}

void answer(int x) {
    cout << "! " << x << endl;
}

const int maxn = 110;
const int mod = 1e6 + 3;
int a[maxn][maxn], x[maxn], free_x[maxn], free_num;

inline int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

inline int lcm(int a, int b) { return a * b / gcd(a, b); }

int Qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}

int Gauss(int equ, int var) {
    int max_r, col, k;
    free_num = 0;
    for (k = 0, col = 0; k < equ && col < var; k++, col++) {
        max_r = k;
        for (int i = k + 1; i < equ; i++)
            if (abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        if (a[max_r][col] == 0) {
            k--;
            free_x[free_num] = col;
            continue;
        }
        if (max_r != k)
            for (int j = col; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        for (int i = k + 1; i < equ; i++)
            if (a[i][col] != 0) {
                int LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                int ta = LCM / abs(a[i][col]);
                int tb = LCM / abs(a[k][col]);
                if (a[i][col] * a[k][col] < 0) tb = -tb;
                for (int j = col; j < var + 1; j++) a[i][j] = ((a[i][j] * ta - a[k][j] * tb) % mod + mod) % mod;
            }
    }
    for (int i = k; i < equ; i++)
        if (a[i][col] != 0) return -1;
    if (k < var) return var - k;
    for (int i = var - 1; i >= 0; i--) {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; j++)
            if (a[i][j]) x[i] = ((x[i] - a[i][j] * x[j]) % mod + mod) % mod;
        x[i] = x[i] * Qpow(a[i][i], mod - 2) % mod;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    srand(time(NULL));
    int equ = 49;
    int var = 11;
    vector<int> ans(equ, 0);
    vector<int> xx(equ, 0);
    for (int i = 0; i < equ; i++) {
        ask(i);
        cin >> ans[i];
        xx[i] = i;
    }
    memset(free_x, 1, sizeof(free_x));
    for (int i = 0; i < equ; i++) {
        int tmp = 1;
        for (int j = 0; j < var; j++) {
            a[i][j] = tmp;
            tmp = tmp * xx[i] % MOD;
        }
        a[i][var] = ans[i];
    }
    Gauss(equ, var);
    if (free_num == -1) {
        answer(-1);
    } else {
        for (int vv = 0; vv < MOD; vv++) {
            int cur = 0;
            int tmp = 1;
            for (int i = 0; i < var; i++) {
                cur = (cur + tmp * x[i]) % MOD;
                tmp = tmp * vv % MOD;
            }
            if (cur == 0) {
                answer(vv);
                return 0;
            }
        }
        answer(-1);
    }
    return 0;
}
