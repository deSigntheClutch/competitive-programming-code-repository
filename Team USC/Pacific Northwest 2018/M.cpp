#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double pi = acos(-1.0);
const int N = 1e5 + 4;
const double eps = 1e-7;

struct Point {
    double x, y;
    void read(){
        cin >> x >> y;
    }
    Point(double a = 0, double b = 0) : x(a), y(b) {}

    // counter-clockwise
    // [cos,  sin]   [x]
    // [-sin, cos]   [y]
    void rotate(double theta) {
        double tx = x * cos(theta) - y * sin(theta);
        double ty = x * sin(theta) + y * cos(theta);
        x = tx, y = ty;
    }
    bool operator < (struct Point v) const {
        if (x == v.x) return y < v.y;
        return x < v.x;
    }
    Point operator - (struct Point c) const {
        return Point(x - c.x, y - c.y);
    }
    Point operator * (double d) const {
        return Point(d * x, d * y);
    }
    Point operator + (struct Point c) const {
        return Point(x + c.x, y + c.y);
    }
    double sqr_norm() {
        return x*x + y*y;
    }
    double norm() {
        return sqrt(sqr_norm());
    }
};

typedef Point Vector;

double cross(struct Point a, struct Point b) {
    return a.x * b.y - a.y * b.x;
}

int n, C;
Point p[N];
int stk[N], l;
int kts[N], r;

double check(Point a, Point b, double rate) {
    Point x = a + (b - a) * rate;
    return x.x * x.y;
}

double cal(Point a, Point b) {
    double len = (b - a).norm();
    double l = 0, r = len;
    double ml, mr;
    for (int i = 0; i < 64; i++) {
        ml = (2 * l + r) / 3;
        mr = (l + 2 * r) / 3;
        if (check(a, b, ml / len) > check(a, b, mr / len)) r = mr;
        else l = ml; 
    }
    return check(a, b, mr / len);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> C;
    for (int i = 1; i <= n; i++) {
        double cost;
        cin >> cost;
        p[i].read();
        p[i].x = (C / cost) * p[i].x;
        p[i].y = (C / cost) * p[i].y;
    }       
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        while (l >= 2 && cross(p[stk[l - 1]] - p[stk[l - 2]], p[i] - p[stk[l - 1]]) <= 0) l--;
        stk[l++] = i;
    }
    for (int i = n; i >= 1; i--) {
        while (r >= 2 && cross(p[kts[r - 1]] - p[kts[r - 2]], p[i] - p[kts[r - 1]]) <= 0) r--;
        kts[r++] = i;
    }
    double xy = 0;
    for (int i = 0; i < r; i++) {
        xy = max(xy, p[kts[i]].x * p[kts[i]].y);
        if (i >= 1) xy = max(xy, cal(p[kts[i - 1]], p[kts[i]]));
    }
    for (int i = 0; i < l; i++) {
        xy = max(xy, p[stk[i]].x * p[stk[i]].y);
        if (i >= 1) xy = max(xy, cal(p[stk[i - 1]], p[stk[i]]));
    }
    cout << fixed << setprecision(2) << xy << endl;
    return 0;
}

/*

7 8
1.1 0.5
1 -0.5
0 0
2 -1
4 0
1 2
2.5 1.7

*/