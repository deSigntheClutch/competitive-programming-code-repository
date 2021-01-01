#include <bits/stdc++.h>
using namespace std;
#define int long long
const double PI = acos(-1.0);
const int N = 1e6 + 10;
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
    for (int i = 0; i < n; ++i) {
        res[i] = (fa[i].real() + 0.5);
    }
}

string s;
int ans[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    vector<int> a(2*n), b(2*n);
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            a[i] = 1;
        }else{
            a[i] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        if(s[i] == 'B'){
            b[-i + (n-1)] = 1;
        }else{
            b[-i + (n-1)] = 0;
        }
    }
    vector<int> res; 
    multiply(a, b, res);
    //cout<<"SIZE: "<<res.size()<<endl;
    for(int i = n; i < n + n-1; i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
