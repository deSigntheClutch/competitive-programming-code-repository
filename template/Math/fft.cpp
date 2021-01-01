const double PI = acos(-1.0);
 
struct base {
    double a, b;
    base() { a = 0, b = 0; }
    base(double a, double b) : a(a), b(b) {}
    base operator + (const base& y) const { return (base) {a + y.a, b + y.b}; }
    base operator - (const base& y) const { return (base) {a - y.a, b - y.b}; }
    base operator * (const base& y) const { return (base) {a * y.a - b * y.b, a * y.b + b * y.a}; }
    base operator ! () const { return (base) {a, -b}; }
};
 
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
            base w(1, 0);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j],  v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) {
            a[i].a /= n;
            a[i].b /= n;
        }
    }
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
    vector<base> fa, fb;
    for (auto x : a) fa.push_back(base(x, 0));
    for (auto x : b) fb.push_back(base(x, 0));
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);
    fft(fa, false),  fft(fb, false);
    for (size_t i = 0; i < n; ++i) {
        fa[i] = fa[i] * fb[i];
    }
    fft(fa, true);
    res.resize(n);
    for (size_t i = 0; i < n; ++i) {
        res[i] = (long long)(fa[i].a + 0.5) % MOD;
    }
}
