#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const int N = 5e5 + 10;
typedef complex<double> base;

void fft(vector<base> & a, bool invert) {
    int n = (int)a.size(), lg_n = 0;
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j],  v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);
    fft(fa, false),  fft(fb, false);
    for (size_t i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    res.resize(n);
    for (size_t i = 0; i < n; ++i) {
        res[i] = int(fa[i].real() + 0.5);
    }
}

int n;
char s[N];
bool invalid[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, s);
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'V') a[i] = 1;
            if (s[n - 1 - i] == 'K') b[i] = 1;
        }
        vector<int> res;
        multiply(a, b, res);
        for (int i = 1; i <= n; i++) invalid[i] = false;
        for (int i = 0; i < 2 * n - 1; i++) {
            if (res[i]) invalid[abs(i - n + 1)] = true;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = i; j <= n; j += i) {
                if (invalid[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(i);
        }
        printf("%d\n", (int)ans.size());
        for (int x : ans) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}
