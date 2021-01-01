#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> pii;

int n;
int x[N], y[N];

int gcd(int a, int b) {
    return (b > 0)? gcd(b, a % b) : a;
}

pii standard(int x, int y) {
    int tmp = gcd(abs(x), abs(y));
    if ((x == 0 && y < 0) || x < 0) x *= -1, y *= -1;
    return make_pair(x / tmp, y / tmp);
}

struct Line {
    int a, b, c;
    Line(int x1, int y1, int x2, int y2) {
        a = y1 - y2;
        b = -(x1 - x2);
        c = -a * x1 - b * y1;
        int tmp = gcd(abs(c), gcd(abs(a), abs(b)));
        a /= tmp;
        b /= tmp;
        c /= tmp;
        if (a < 0 || (a == 0 && b < 0)) a *= -1, b *= -1, c *= -1;
    }
    bool operator < (struct Line l) const {
        return make_tuple(a, b, c) < make_tuple(l.a, l.b, l.c);
    }
    void print() {
        cout << a << " " << b << " " << c << endl;
    }
};

map<pii, int> cnt_k;
map<Line, bool> used;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int cnt = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int u = x[i] - x[j], v = y[i] - y[j];
            Line l = Line(x[i], y[i], x[j], y[j]);
            if (used[l] == true) continue;
            used[l] = true;
            pii vec = standard(u, v);
            cnt += 1;
            cnt_k[vec] += 1;
            ans += cnt - cnt_k[vec];
        }
    }
    cout << ans << endl;
    return 0;
}