#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-9;

int sgn(long double x) {
    if (x > eps) return 1;
    else if (x < -eps) return -1;
    else return 0;
}

struct Point {
    int x, y, z;
    void read(){
        cin >> x >> y >> z;
    }
    Point(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {

    }
    bool operator == (struct Point c) const {
        return c.x == x && c.y == y && c.z == z;
    }
    Point operator - (struct Point c) const {
        return Point(x - c.x, y - c.y, z - c.z);
    }
    int sqr_norm() {
        return x*x + y*y + z*z;
    }
    double norm() {
        return sqrt(sqr_norm());
    }
    int operator * (struct Point c) const {
        return x * c.x + y * c.y + z * c.z;
    }
};

typedef Point Vector;

Point a, b;
Point o;
int r;

double area(Point x, Point y, Point z) {
    long double p = ((x - y).norm() + (y - z).norm() + (x - z).norm()) / 2;
    return sqrt(p * (p - (x - y).norm()) * (p - (x - z).norm()) * (p - (z - y).norm()));
}

double center_to_seg(Point cen, Point x, Point y) {
    return 2 * area(cen, x, y) / (x - y).norm();
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        o.read(); 
        cin >> r;
        a.read();
        b.read();
        if (a == b || (o - a) * (b - a) <= 0 || (o - b) * (a - b) <= 0) {
            cout << (a - b).norm() << endl;
            continue;
        }
        if (r <= center_to_seg(o, a, b)) {
            cout << fixed << setprecision(14) << (a - b).norm() << endl;
            continue;
        }
        double sum_tan = sqrt((a-o).sqr_norm() - r * r) + sqrt((b-o).sqr_norm() - r * r);
        double theta = acos(((a-o).sqr_norm() + (b-o).sqr_norm() - (a-b).sqr_norm()) * .5 / (a-o).norm() / (b-o).norm()); 
        double the1 = acos(r / (b-o).norm());
        double the2 = acos(r / (a-o).norm());
        double arc = (theta - the1 - the2) * r;
        cout << fixed << setprecision(14) << arc + sum_tan << endl;
    }
    return 0;
}
