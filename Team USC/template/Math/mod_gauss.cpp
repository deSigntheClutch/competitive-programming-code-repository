const int MOD = 1e9 + 7;

int equ, var;      // number of equation, number of var
int a[maxn][maxn]; //(equ, var) coef, column var = value of the equation
                   // 1x + 2y + 3z = 3
                   // 0x + 1y + 0z = 2
                   // 10x + 2y + 6z = 22
                   // a will be like
                   // 1, 2, 3, 3
                   // 0, 1, 0, 2
                   // 10, 2, 6, 22
int x[maxn];       // solution
int free_x[maxn];
int free_num;
//

int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int powMod(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = (ll)res * u % MOD;
        v >>= 1;
        u = (ll)u * u % MOD;
    }
    return res;
}

int Gauss() {
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
                for (int j = col; j < var + 1; j++) a[i][j] = ((a[i][j] * ta - a[k][j] * tb) % MOD + MOD) % MOD;
            }
    }
    for (int i = k; i < equ; i++)
        if (a[i][col] != 0) return -1; // no possible solution

    if (k < var) return var - k;
    for (int i = var - 1; i >= 0; i--) {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; j++)
            if (a[i][j]) x[i] = ((x[i] - a[i][j] * x[j]) % MOD + MOD) % MOD;
        x[i] = x[i] * powMod(a[i][i], MOD - 2) % MOD;
    }
    return 0;
}