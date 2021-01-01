#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<int> vec;

long long n, m;
const int MOD = 998244353;

matrix multiply(matrix a, matrix b) {
    matrix ans = matrix(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                ans[i][j] = (ans[i][j] + (long long)a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return ans;
}

void task2() {
   vector<int> a(m + 1, 0);
   a[1] = a[2] = 1;
   for (int i = 3; i <= m; i++) {
       a[i] = a[i - 1] + a[i - 2];
   } 

}

matrix quick_mod(matrix x, long long p) {
    matrix res = matrix(n + 1, vec(n + 1, 0));
    for (int i = 0; i < n + 1; i++) {
        res[i][i] = 1;
    }
    while (p) {
        if (p & 1) res = multiply(res, x);
        p >>= 1;
        x = multiply(x, x);
    }
    return res;
}

void task3() {
    matrix gen = matrix(n + 1, vec(n + 1, 0));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            gen[i][j] = 1;
        }
    }
    gen[n - 1][n - 1] = 1;
    gen[n - 1][n] = 1;
    gen[n][n - 1] = 1;
    matrix A = matrix(n + 1, vec(1, 0));
    for (int i = n; i >= 0; i--) {
        A[i][0] = 1; 
    }
    if (m == 1) {
        cout << 1 << endl;
        return ;
    }
    gen = quick_mod(gen, m - 1);
    matrix ans = multiply(gen, A);
    if (n == 1) cout << ans[n][0] << endl;
    else cout << ans[0][0] << endl;
}

void task1() {
    vector<vector<int>> d(3001, vector<int>(3000+1, 0));
    d[1][1] = 1;
    d[1][2] = 1;
    for (int i = 3; i <= 3000; i++) {
        d[1][i] = (d[1][i - 2] + d[1][i - 1]) % MOD;
    }
    for (int i = 2; i <= 3000; i++) {
        d[i][1] = d[i - 1][1];
        for (int j = 2; j <= 3000; j++) {
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD;
        }
    }
    cout << d[n][m] << endl;
}

void task4() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if (n <= 3000 && m <= 3000) task1();
    else if (n <= 200000 && m <= 200000) task2();
    else if (n <= 3) task3();
    else if (n <= 2000) task3();
    else task4();
    return 0;
}
